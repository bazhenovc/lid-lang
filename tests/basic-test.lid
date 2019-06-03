//  MIT License
//
//  Copyright (c) 2019 Kyrylo Bazhenov
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

// Various imports from libc and others

extern function rand(): i32
extern function sinf(:f32): f32
extern function cosf(:f32): f32
extern function puts(:&u8): i32

const StringConstant = "This is a string constant"
const FloatConstant = 3.14

const NamedLambda = function(): f32 {
    (FloatConstant + 2)
}

function GetFloat(): f32 {
    FloatConstant
}

function TestLambda(:i128): f32 {
    (function(): f32 {
        (function(rootValue: f32): f32 {
            (function(inValue: f32): f32 {
                puts("TestLambda")
                ((inValue / GetFloat()) + ((1.22 + inValue) * 2))
            }) (42.5)
        }) (NamedLambda())
    }) ()
}

function LambdaArgument(x: function(value: i32): void): void {
    x(128)
}

function TestLambdaAsArgument(): void {
    LambdaArgument(function(value: i32): void {
        if (value == 128) { puts("Lambda as argument test passed") }
        else              { puts("Lambda as argument test failed") }
    })
}

function TestScope(): u32 {
    let x = 42 {
        (function(): u32 {
            (x + rand())
        }) ()
    }
}

function TestScopeLambda(): i32 {
    let x = function(:f16): i32 { rand() } {
        x(0.2)
    }
}

function TestScopeMutable(): void {
    let x: i32 #mutable = 0 {
        if (x == 0) {
            puts("Mutable test passed")
        } else {
            puts("Mutable test failed")
        }
        x = (x + 42)
        if (x == 42) {
            puts("Mutable test passed")
        } else {
            puts("Mutable test failed")
        }
    }
}

function TestIf(): void {
    if 0 {
        puts("If failed")
    } else {
        puts("If passed")
    }
}

function TestIfElse(): void {
    if      0 { puts("0 is false, this should never happen") }
    else if 1 { puts("1 is true") }
    else if 2 { puts("2 is also true, but this should never happen") }
    else if 3 { puts("3 is also true, however this should not happen too") }
    else {
        puts("Else, we will never see this one")
        puts("if we ever see this message - something is seriously broken")
    }
}

function TestIntegerBinaryOperators(): void {
    puts("Testing integer binary operators")
    if (5 == 5)         { puts("5 equals 5") }                 else { puts("integer equality operator failed") }
    if (1 ~= 5)         { puts("1 not-equals 5") }             else { puts("integer not-equality operator failed") }
    if (9 >  3)         { puts("9 is greater than 3") }        else { puts("integer greater-than operator failed") }
    if (2 <  4)         { puts("2 is lesser than 4") }         else { puts("integer lesser-than operator failed") }
    if (7 >= 5)         { puts("7 equals or greater than 5") } else { puts("integer greater-equals operator failed") }
    if (7 >= 7)         { puts("7 equals or greater than 7") } else { puts("integer greater-equals operator failed") }
    if (5 <= 7)         { puts("5 equals or lesser than 7") }  else { puts("integer lesser-equals operator failed") }
    if (7 <= 7)         { puts("7 equals or lesser than 7") }  else { puts("integer lesser-equals operator failed") }
}

function TestFloatBinaryOperators(): void {
    puts("Testing floating-point binary operators")
    if (5.0 == 5.0)     { puts("5.0 equals 5.0") }                 else { puts("float equality operator failed") }
    if (1.8 ~= 5.14)    { puts("1.8 not-equals 5.14") }            else { puts("float not-equality operator failed") }
    if (9.2 >  3.3)     { puts("9.2 is greater than 3.3") }        else { puts("float greater-than operator failed") }
    if (2.2 <  4.1)     { puts("2.2 is lesser than 4.1") }         else { puts("float lesser-than operator failed") }
    if (7.1 >= 5.2)     { puts("7.1 equals or greater than 5.2") } else { puts("float greater-equals operator failed") }
    if (7.0 >= 7.0)     { puts("7.0 equals or greater than 7.0") } else { puts("float greater-equals operator failed") }
    if (5.0 <= 7.0)     { puts("5.0 equals or lesser than 7.0") }  else { puts("float lesser-equals operator failed") }
    if (7.0 <= 7.0)     { puts("7.0 equals or lesser than 7.0") }  else { puts("float lesser-equals operator failed") }
}

const TestValue = 42

function TestIntegerUnaryOperators(): void {
    if (-TestValue == -42)  { puts("Unary operator test passed") }
    else                    { puts("Unary operator test failed") }
}

function TestTypeCast(): void {
    let typedConstant: i8 = 255 {
        if (typedConstant == -127) {
            puts("Type cast test passed")
        } else {
            puts("Type cast test failed")
        }
    }
}

function TestForLoop(): void {
    let loopResult = for (x: i16 = 0; (x < 4); (x + 1)) { puts("Loop iteration") x } {
        if (loopResult == 3) {
            puts("Loop test passed")
        } else {
            puts("Loop test failed")
        }
    }
}

struct Vector3i {
    x: i32 = 0      // TODO: Default initializers are not implemented
    y: i32 = 0
    z: i32 = 0
}

function TestStruct(vec: Vector3i, vecPtr: &Vector3i): void {
    0
}

function TestStructMembers(): void {
    let vec = Vector3i(1, 2, 3) {
        if ((vec.x + (vec.y + vec.z)) == 6) {
            puts("Struct test passed")
        } else {
            puts("Struct test failed")
        }
        vec.x = 4
        vec.y = 5
        vec.z = 6
        if ((vec.x + (vec.y + vec.z)) == 15) {
            puts("Mutable struct test passed")
        } else {
            puts("Mutable struct test failed")
        }
        vec = Vector3i(7, 8, 9)
        if ((vec.x + (vec.y + vec.z)) == 24) {
            puts("Mutable struct test passed")
        } else {
            puts("Mutable struct test failed")
        }
    }
}

struct NestedStruct {
    offset: Vector3i
    scale: Vector3i
}

function TestNestedStruct(): void {
    let x = NestedStruct(Vector3i(1, 2, 3), Vector3i(4, 5, 6)) {
        if ((x.offset.x + x.scale.z) == 7) {
            puts("Nested struct test passed")
        } else {
            puts("Nested struct test failed")
        }
        x.offset.x = 5
        x.scale.z = 5
        if ((x.offset.x + x.scale.z) == 10) {
            puts("Mutable nested struct test passed")
        } else {
            puts("Mutable nested struct test failed")
        }
    }
}

// Main function
function main(): i32 {
    puts("Hello World")
    puts(StringConstant)
    TestLambda(5431231)
    TestScope()
    TestScopeLambda()
    TestLambdaAsArgument()
    TestScopeMutable()
    TestIf()
    TestIfElse()
    TestIntegerBinaryOperators()
    TestFloatBinaryOperators()
    TestIntegerUnaryOperators()
    TestTypeCast()
    TestForLoop()
    TestStructMembers()
    TestNestedStruct()

    let x = rand() {
        x
    }
}
