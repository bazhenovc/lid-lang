/** MIT License

    Copyright (c) 2019 Kyrylo Bazhenov

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once

#include <string_view>
#include <vector>
#include <unordered_map>
#include <memory>

namespace llvm
{
    class LLVMContext;
    class Value;
    class Type;
    class BasicBlock;
    class Module;

    class ConstantFolder;
    class IRBuilderDefaultInserter;
    template <typename T /*= ConstantFolder*/,
              typename Inserter /*= IRBuilderDefaultInserter*/>
    class IRBuilder;
}

namespace AST
{
    struct BaseExpression;
    typedef std::unique_ptr<BaseExpression> BaseExpressionPtr;

    struct StructTypeInfo
    {
        struct Member
        {
            unsigned int    Index;
            llvm::Type*     Type;
        };

        std::unordered_map<std::string_view, Member> Members;
    };

    struct CodeGenResult
    {
        llvm::Value* const* Values = nullptr;
        size_t NumValues = 0;

        CodeGenResult() {}

        explicit CodeGenResult(llvm::Value** value)
            : Values(value), NumValues(1)
        {}

        explicit CodeGenResult(const std::vector<llvm::Value*>& data)
            : Values(data.data()), NumValues(data.size())
        {}
    };

    struct GeneratedScope
    {
        std::unordered_map<std::string_view, CodeGenResult> Bindings;
        std::unordered_map<std::string_view, llvm::Type*> Types;
        std::unordered_map<llvm::Type*, StructTypeInfo> TypeInfoMap;
        llvm::BasicBlock* RootBlock = nullptr;
    };

    struct SourceParseContext
    {
        std::string_view    Source;
        size_t              LineNumber = 0;
    };

    typedef llvm::IRBuilder<llvm::ConstantFolder, llvm::IRBuilderDefaultInserter> IRBuilder;
    struct CodeGenContext
    {
        GeneratedScope&             Scope;
        IRBuilder*                  Builder = nullptr;
        llvm::Module*               Module = nullptr;
        llvm::LLVMContext*          Context = nullptr;
    };

    struct ExpressionType
    {
        std::string_view            TypeName;
        std::vector<ExpressionType> ArgumentTypes; // 0 is the return type, rest are arguments

        bool IsPointer = false;
        bool IsFunction = false;
    };

    struct ExpressionQualifiers
    {
        bool IsMutable = false;
    };

    // Expressions

    struct ExpressionScope
    {
        std::vector<std::pair<std::string_view, BaseExpressionPtr>> Bindings;
        std::vector<std::pair<std::string_view, BaseExpressionPtr>> Types;
    };

    struct BaseExpression
    {
        SourceParseContext  ParseContext;

        BaseExpression(SourceParseContext context);

        virtual ~BaseExpression();
        virtual CodeGenResult Generate(CodeGenContext& cc) = 0;

        void Assert(bool condition, std::string_view message) const;

        std::string GetTypeName(llvm::Type* type) const;
        bool IsSafeTypeCastPossible(llvm::Value* value, llvm::Type* desiredType) const;
        llvm::Type* ResolveType(ExpressionType type, const GeneratedScope& scope) const;
        llvm::Value* GenerateSafeTypeCast(llvm::Value* value, llvm::Type* desiredType) const;
        llvm::Value* GenerateBoolean(CodeGenContext& cc, llvm::Value* value) const;

        // Debug printing
        virtual void DebugPrint(int indent);
    };

    struct BinaryOperatorExpression : public BaseExpression
    {
        std::string_view    Operator;
        BaseExpressionPtr   LHS;
        BaseExpressionPtr   RHS;

        llvm::Value* LocalValue;

        BinaryOperatorExpression(SourceParseContext parseContext,
                                 BaseExpressionPtr&& lhs, BaseExpressionPtr&& rhs);

        virtual CodeGenResult Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct UnaryOperatorExpression : public BaseExpression
    {
        std::string_view    Operator;
        BaseExpressionPtr   RHS;

        llvm::Value* LocalValue;

        UnaryOperatorExpression(SourceParseContext parseContext,
                                BaseExpressionPtr&& rhs);

        virtual CodeGenResult Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct FunctionExpression : public BaseExpression
    {
        struct FunctionType
        {
            std::vector<std::string_view> ArgNames;
            std::vector<ExpressionType> ArgTypes;
            ExpressionType ReturnType;
        };

        struct Overload
        {
            FunctionType                    Type;
            std::vector<BaseExpressionPtr>  Body;

            mutable std::vector<llvm::Value*> LocalArgumentValues;
            mutable llvm::Value* LocalValue;
        };

        std::vector<Overload> Overloads;
        std::vector<llvm::Value*> GeneratedOverloads;

        FunctionExpression(SourceParseContext context, FunctionType&& type,
                           std::vector<BaseExpressionPtr>&& body);

        // TODO: Parse context data is not accurate here, it will provide function name but not the exact location.
        void AddOverload(std::unique_ptr<FunctionExpression>&& expr);

        virtual CodeGenResult Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct BranchExpression : public BaseExpression
    {
        struct ConditionAndValue
        {
            BaseExpressionPtr Condition;
            std::vector<BaseExpressionPtr> Values;
        };

        std::vector<ConditionAndValue> Body;

        llvm::Value* LocalValue;

        BranchExpression(SourceParseContext context, std::vector<ConditionAndValue>&& body);

        virtual CodeGenResult Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct FunctionCallExpression : public BaseExpression
    {
        BaseExpressionPtr               FunctionExpr;
        std::vector<BaseExpressionPtr>  FunctionArguments;

        llvm::Value* LocalValue;

        FunctionCallExpression(SourceParseContext parseContext,
                BaseExpressionPtr&& functionExpr, std::vector<BaseExpressionPtr>&& arguments);

        virtual CodeGenResult Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct LetExpression : public BaseExpression
    {
        struct Binding
        {
            BaseExpressionPtr       Body;
            ExpressionQualifiers    Qualifiers;
        };

        std::unordered_map<std::string_view, Binding> Bindings;
        std::vector<BaseExpressionPtr> Body;

        std::vector<llvm::Value*> LocalBindingValues;

        LetExpression(SourceParseContext parseContext,
                      std::unordered_map<std::string_view, Binding>&& bindings,
                      std::vector<BaseExpressionPtr>&& body);

        virtual CodeGenResult Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct SetExpression : public BaseExpression
    {
        BaseExpressionPtr   MutableValue;
        BaseExpressionPtr   Expression;

        llvm::Value* LocalValue;

        SetExpression(SourceParseContext parseContext,
                      BaseExpressionPtr mutableValue, BaseExpressionPtr expression);

        virtual CodeGenResult Generate(CodeGenContext &cc) override;
    };

    struct LiteralExpression : public BaseExpression
    {
        enum LiteralType
        {
            Invalid = 0,
            Integer,
            Float,
            Boolean,
            String
        };

        LiteralType         Type = Invalid;
        std::string_view    RawValue;

        llvm::Value* LocalValue;

        LiteralExpression(SourceParseContext parseContext, LiteralType type);

        virtual CodeGenResult Generate(CodeGenContext &cc) override;
    };

    struct ValueExpression : public BaseExpression
    {
        std::string_view Value;
        bool DereferencePointer;

        llvm::Value* LocalValue;

        ValueExpression(SourceParseContext parseContext, bool dereferencePointer);

        virtual CodeGenResult Generate(CodeGenContext &cc) override;
    };

    struct TypeCastExpression : public BaseExpression
    {
        ExpressionType          DesiredType;
        AST::BaseExpressionPtr  OriginalExpression;

        llvm::Value* LocalValue;

        TypeCastExpression(SourceParseContext parseContext,
                           ExpressionType desiredType,
                           BaseExpressionPtr&& originalExpression);

        virtual CodeGenResult Generate(CodeGenContext &cc) override;
    };

    struct LoopExpression : public BaseExpression
    {
        struct BindingExpression
        {
            std::string_view    Name;
            ExpressionType      DesiredType;
            BaseExpressionPtr   InitialValue;
            BaseExpressionPtr   ExitCondition;
            BaseExpressionPtr   Body;
        };

        std::vector<BindingExpression>  Bindings;
        std::vector<BaseExpressionPtr>  Body;

        std::vector<llvm::Value*> LocalTempValues;
        llvm::Value* LocalValue;

        LoopExpression(SourceParseContext parseContext,
                       std::vector<BindingExpression>&& bindings,
                       std::vector<BaseExpressionPtr>&& body);

        virtual CodeGenResult Generate(CodeGenContext &cc) override;
    };

    struct StructExpression : public BaseExpression
    {
        struct Member
        {
            std::string_view    Name;
            ExpressionType      Type;
            BaseExpressionPtr   DefaultValue;
        };

        std::vector<Member> Members;
        std::vector<llvm::Value*> LocalValues;

        StructExpression(SourceParseContext parseContext,
                         std::vector<Member>&& members);

        virtual CodeGenResult Generate(CodeGenContext &cc) override;
    };
}
