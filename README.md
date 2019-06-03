# LID - Lisp In Disguise

Hello, this is my experimental programming language based on LLVM libraries.

At this stage it's pretty basic, thus I recommend you to lower your expectations. Please refrain from using this code in production for now.

## Supported features

In no particular order:

* All low-level types that LLVM supports: bool, i8/u8, i16/u16, i32/u32, i64/u64, i128/u128, f16, f32, f64
* User-defined structs
* Mutable and immutable variables (immutable by default)
* Conditional branches
* Loops
* Binary arithmeric and logic operators
* Type inference
* User-defined functions and external functions from DLLs
* Lambdas and closures

## Examples

### Demo application source and output

<table>
<tr>
<td><pre lang="javacript">

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
        TestTypeCast()
        TestForLoop()
        TestStructMembers()
        TestNestedStruct()

        let x = rand() {
            x
        }
    }

</pre></td>
<td><pre>

    > lid-compiler.exe tests/basic-test.lisp -ir-binary=build/basic-test.ll -ir-plaintext=stdout
    > lli.exe build/basic-test.ll
    Hello World
    This is a string constant
    TestLambda
    Lambda as argument test passed
    Mutable test passed
    Mutable test passed
    If passed
    1 is true
    Testing integer binary operators
    5 equals 5
    1 not-equals 5
    9 is greater than 3
    2 is lesser than 4
    7 equals or greater than 5
    7 equals or greater than 7
    5 equals or lesser than 7
    7 equals or lesser than 7
    Testing floating-point binary operators
    5.0 equals 5.0
    1.8 not-equals 5.14
    9.2 is greater than 3.3
    2.2 is lesser than 4.1
    7.1 equals or greater than 5.2
    7.0 equals or greater than 7.0
    5.0 equals or lesser than 7.0
    7.0 equals or lesser than 7.0
    Type cast test passed
    Loop iteration
    Loop iteration
    Loop iteration
    Loop iteration
    Loop test passed
    Struct test passed
    Mutable struct test passed
    Mutable struct test passed
    Nested struct test passed
    Mutable nested struct test passed

</pre></td>
</tr>
</table>

### Importing external functions

<table>
<tr>
<td><pre lang="javacript">
    extern function rand(): i32
    extern function sinf(:f32): f32
    extern function cosf(:f32): f32
    extern function puts(:&u8): i32
</pre></td>
<td><pre lang="llvm">
    declare dllimport i32 @rand()
    declare dllimport float @sinf(float)
    declare dllimport float @cosf(float)
    declare dllimport i32 @puts(i8*)
</pre></td>
</tr>
</table>

### Declaring constants and functions
<table>
<tr>
<td><pre lang="javacript">

    const StringConstant = "This is a string constant"
    const FloatConstant = 3.14

    const NamedLambda = function(): f32 {
        (FloatConstant + 2)
    }

    function GetFloat(): f32 {
        FloatConstant
    }


</pre></td>
<td><pre lang="llvm">

    define internal float @lambda() {
    __funcbody:
      ret float 0x40148F5C20000000
    }

    define internal float @GetFloat() {
    __funcbody:
      ret float 0x40091EB860000000
    }

</pre></td>
</tr>
</table>

### Declaring functions inside functions inside functions

<table>
<tr>
<td><pre lang="javacript">

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

</pre></td>
<td><pre lang="llvm">

    define internal float @TestLambda(i128) {
    __funcbody:
      %1 = call float @lambda.1()
      ret float %1
    }

    define internal float @lambda.1() {
    __funcbody:
      %0 = call float @lambda()
      %1 = call float @lambda.2(float %0)
      ret float %1
    }

    define internal float @lambda.2(float) {
    __funcbody:
      %1 = call float @lambda.3(float 4.250000e+01)
      ret float %1
    }

    define internal float @lambda.3(float) {
    __funcbody:
      %1 = call i32 @puts(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @__str_literal.4, i64 0, i64 0))
      %2 = call float @GetFloat()
      %3 = fdiv float %0, %2
      %4 = fadd float 0x3FF3851EC0000000, %0
      %5 = fmul float %4, 2.000000e+00
      %6 = fadd float %3, %5
      ret float %6
    }

</pre></td>
</tr>
</table>

### Passing functions as arguments to other functions

<table>
<tr>
<td><pre lang="javacript">

    function LambdaArgument(x: function(value: i32): void): void {
        x(128)
    }

    function TestLambdaAsArgument(): void {
        LambdaArgument(function(value: i32): void {
            if (value == 128) { puts("Lambda as argument test passed") }
            else              { puts("Lambda as argument test failed") }
        })
    }

</pre></td>
<td><pre lang="llvm">

    define internal void @LambdaArgument(void (i32)*) {
    __funcbody:
      call void %0(i32 128)
      ret void
    }

    define internal void @TestLambdaAsArgument() {
    __funcbody:
      call void @LambdaArgument(void (i32)* @lambda.7)
      ret void
    }

</pre></td>
</tr>
</table>

### Declaring local variables and local lambdas

<table>
<tr>
<td><pre lang="javacript">

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

</pre></td>
<td><pre lang="llvm">

    define internal i32 @TestScope() {
    __funcbody:
      %0 = call i32 @lambda.8()
      ret i32 %0
    }

    define internal i32 @lambda.8() {
    __funcbody:
      %0 = call i32 @rand()
      %1 = add i32 42, %0
      ret i32 %1
    }

    define internal i32 @TestScopeLambda() {
    __funcbody:
      %0 = call i32 @lambda.9(half 0xH3266)
      ret i32 %0
    }

    define internal i32 @lambda.9(half) {
    __funcbody:
      %1 = call i32 @rand()
      ret i32 %1
    }

</pre></td>
</tr>
</table>

### Using conditional branches

<table>
<tr>
<td><pre lang="javacript">

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

</pre></td>
<td><pre lang="llvm">

    define internal void @TestIf() {
    __funcbody:
      br i1 false, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %__funcbody
      br label %cond_1_body

    cond_0_body:                                      ; preds = %__funcbody
      %0 = call i32 @puts(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @__str_literal.14, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %1 = call i32 @puts(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @__str_literal.15, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %2 = phi i32 [ %0, %cond_0_body ], [ %1, %cond_1_body ]
      ret void
    }

    define internal void @TestIfElse() {
    __funcbody:
      br i1 false, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %__funcbody
      br i1 true, label %cond_1_body, label %cond_2_test

    cond_2_test:                                      ; preds = %cond_1_test
      br i1 true, label %cond_2_body, label %cond_3_test

    cond_3_test:                                      ; preds = %cond_2_test
      br i1 true, label %cond_3_body, label %cond_4_test

    cond_4_test:                                      ; preds = %cond_3_test
      br label %cond_4_body

    cond_0_body:                                      ; preds = %__funcbody
      %0 = call i32 @puts(i8* getelementptr inbounds ([37 x i8], [37 x i8]* @__str_literal.16, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %1 = call i32 @puts(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @__str_literal.17, i64 0, i64 0))
      br label %cond_next

    cond_2_body:                                      ; preds = %cond_2_test
      %2 = call i32 @puts(i8* getelementptr inbounds ([45 x i8], [45 x i8]* @__str_literal.18, i64 0, i64 0))
      br label %cond_next

    cond_3_body:                                      ; preds = %cond_3_test
      %3 = call i32 @puts(i8* getelementptr inbounds ([51 x i8], [51 x i8]* @__str_literal.19, i64 0, i64 0))
      br label %cond_next

    cond_4_body:                                      ; preds = %cond_4_test
      %4 = call i32 @puts(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @__str_literal.20, i64 0, i64 0))
      %5 = call i32 @puts(i8* getelementptr inbounds ([60 x i8], [60 x i8]* @__str_literal.21, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_4_body, %cond_3_body, %cond_2_body, %cond_1_body, %cond_0_body
      %6 = phi i32 [ %0, %cond_0_body ], [ %1, %cond_1_body ], [ %2, %cond_2_body ], [ %3, %cond_3_body ], [ %5, %cond_4_body ]
      ret void
    }

</pre></td>
</tr>
</table>

### Declaring and using mutable variables

<table>
<tr>
<td><pre lang="javacript">

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

</pre></td>
<td><pre lang="llvm">

    define internal void @TestScopeMutable() {
    __funcbody:
      %0 = alloca i32
      store i32 0, i32* %0
      %1 = load i32, i32* %0
      %2 = icmp eq i32 %1, 0
      br i1 %2, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %__funcbody
      br label %cond_1_body

    cond_0_body:                                      ; preds = %__funcbody
      %3 = call i32 @puts(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @__str_literal.10, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %4 = call i32 @puts(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @__str_literal.11, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %5 = phi i32 [ %3, %cond_0_body ], [ %4, %cond_1_body ]
      %6 = load i32, i32* %0
      %7 = add i32 %6, 42
      store i32 %7, i32* %0
      %8 = load i32, i32* %0
      %9 = icmp eq i32 %8, 42
      br i1 %9, label %cond_0_body2, label %cond_1_test1

    cond_1_test1:                                     ; preds = %cond_next
      br label %cond_1_body3

    cond_0_body2:                                     ; preds = %cond_next
      %10 = call i32 @puts(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @__str_literal.12, i64 0, i64 0))
      br label %cond_next4

    cond_1_body3:                                     ; preds = %cond_1_test1
      %11 = call i32 @puts(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @__str_literal.13, i64 0, i64 0))
      br label %cond_next4

    cond_next4:                                       ; preds = %cond_1_body3, %cond_0_body2
      %12 = phi i32 [ %10, %cond_0_body2 ], [ %11, %cond_1_body3 ]
      ret void
    }

</pre></td>
</tr>
</table>

### Using explicit type casts

<table>
<tr>
<td><pre lang="javacript">

    function TestTypeCast(): void {
        let typedConstant: i8 = 255 {
            if (typedConstant == -127) {
                puts("Type cast test passed")
            } else {
                puts("Type cast test failed")
            }
        }
    }

</pre></td>
<td><pre lang="llvm">

    define internal void @TestTypeCast() {
    __funcbody:
      br i1 true, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %__funcbody
      br label %cond_1_body

    cond_0_body:                                      ; preds = %__funcbody
      %0 = call i32 @puts(i8* getelementptr inbounds ([22 x i8], [22 x i8]* @__str_literal.56, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %1 = call i32 @puts(i8* getelementptr inbounds ([22 x i8], [22 x i8]* @__str_literal.57, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %2 = phi i32 [ %0, %cond_0_body ], [ %1, %cond_1_body ]
      ret void
    }

</pre></td>
</tr>
</table>

### Using loops

<table>
<tr>
<td><pre lang="javacript">

    function TestForLoop(): void {
        let loopResult = for (x: i16 = 0; (x < 4); (x + 1)) { puts("Loop iteration") x } {
            if (loopResult == 3) {
                puts("Loop test passed")
            } else {
                puts("Loop test failed")
            }
        }
    }

</pre></td>
<td><pre lang="llvm">

    define internal void @TestForLoop() {
    __funcbody:
      %0 = alloca i16
      store i16 0, i16* %0
      br i1 true, label %loop_body, label %loop_next

    loop_body:                                        ; preds = %loop_body, %__funcbody
      %1 = load i16, i16* %0
      %2 = call i32 @puts(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @__str_literal.58, i64 0, i64 0))
      %3 = add i16 %1, 1
      store i16 %3, i16* %0
      %4 = icmp slt i16 %3, 4
      br i1 %4, label %loop_body, label %loop_next

    loop_next:                                        ; preds = %loop_body, %__funcbody
      %5 = phi i16 [ %1, %loop_body ], [ 0, %__funcbody ]
      %6 = icmp eq i16 %5, 3
      br i1 %6, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %loop_next
      br label %cond_1_body

    cond_0_body:                                      ; preds = %loop_next
      %7 = call i32 @puts(i8* getelementptr inbounds ([17 x i8], [17 x i8]* @__str_literal.59, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %8 = call i32 @puts(i8* getelementptr inbounds ([17 x i8], [17 x i8]* @__str_literal.60, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %9 = phi i32 [ %7, %cond_0_body ], [ %8, %cond_1_body ]
      ret void
    }

</pre></td>
</tr>
</table>

### Declaring and using structures

<table>
<tr>
<td><pre lang="javacript">

    struct Vector3i {
        x: i32 = 0
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

</pre></td>
<td><pre lang="llvm">

    %Vector3i = type { i32, i32, i32 }
    %NestedStruct = type { %Vector3i, %Vector3i }

    define internal %Vector3i @Vector3i(i32, i32, i32) {
    __funcbody:
      %3 = alloca %Vector3i
      %4 = getelementptr inbounds %Vector3i, %Vector3i* %3, i32 0, i32 0
      store i32 %0, i32* %4
      %5 = getelementptr inbounds %Vector3i, %Vector3i* %3, i32 0, i32 1
      store i32 %1, i32* %5
      %6 = getelementptr inbounds %Vector3i, %Vector3i* %3, i32 0, i32 2
      store i32 %2, i32* %6
      %7 = load %Vector3i, %Vector3i* %3
      ret %Vector3i %7
    }

    define internal %NestedStruct @NestedStruct(%Vector3i, %Vector3i) {
    __funcbody:
      %2 = alloca %NestedStruct
      %3 = getelementptr inbounds %NestedStruct, %NestedStruct* %2, i32 0, i32 0
      store %Vector3i %0, %Vector3i* %3
      %4 = getelementptr inbounds %NestedStruct, %NestedStruct* %2, i32 0, i32 1
      store %Vector3i %1, %Vector3i* %4
      %5 = load %NestedStruct, %NestedStruct* %2
      ret %NestedStruct %5
    }

    define internal void @TestStruct(%Vector3i, %Vector3i*) {
    __funcbody:
      ret void
    }

    define internal void @TestStructMembers() {
    __funcbody:
      %0 = call %Vector3i @Vector3i(i32 1, i32 2, i32 3)
      %1 = alloca %Vector3i
      store %Vector3i %0, %Vector3i* %1
      %2 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 0
      %3 = load i32, i32* %2
      %4 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 1
      %5 = load i32, i32* %4
      %6 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 2
      %7 = load i32, i32* %6
      %8 = add i32 %5, %7
      %9 = add i32 %3, %8
      %10 = icmp eq i32 %9, 6
      br i1 %10, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %__funcbody
      br label %cond_1_body

    cond_0_body:                                      ; preds = %__funcbody
      %11 = call i32 @puts(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @__str_literal.61, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %12 = call i32 @puts(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @__str_literal.62, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %13 = phi i32 [ %11, %cond_0_body ], [ %12, %cond_1_body ]
      %14 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 0
      store i32 4, i32* %14
      %15 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 1
      store i32 5, i32* %15
      %16 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 2
      store i32 6, i32* %16
      %17 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 0
      %18 = load i32, i32* %17
      %19 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 1
      %20 = load i32, i32* %19
      %21 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 2
      %22 = load i32, i32* %21
      %23 = add i32 %20, %22
      %24 = add i32 %18, %23
      %25 = icmp eq i32 %24, 15
      br i1 %25, label %cond_0_body2, label %cond_1_test1

    cond_1_test1:                                     ; preds = %cond_next
      br label %cond_1_body3

    cond_0_body2:                                     ; preds = %cond_next
      %26 = call i32 @puts(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @__str_literal.63, i64 0, i64 0))
      br label %cond_next4

    cond_1_body3:                                     ; preds = %cond_1_test1
      %27 = call i32 @puts(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @__str_literal.64, i64 0, i64 0))
      br label %cond_next4

    cond_next4:                                       ; preds = %cond_1_body3, %cond_0_body2
      %28 = phi i32 [ %26, %cond_0_body2 ], [ %27, %cond_1_body3 ]
      %29 = call %Vector3i @Vector3i(i32 7, i32 8, i32 9)
      store %Vector3i %29, %Vector3i* %1
      %30 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 0
      %31 = load i32, i32* %30
      %32 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 1
      %33 = load i32, i32* %32
      %34 = getelementptr inbounds %Vector3i, %Vector3i* %1, i32 0, i32 2
      %35 = load i32, i32* %34
      %36 = add i32 %33, %35
      %37 = add i32 %31, %36
      %38 = icmp eq i32 %37, 24
      br i1 %38, label %cond_0_body6, label %cond_1_test5

    cond_1_test5:                                     ; preds = %cond_next4
      br label %cond_1_body7

    cond_0_body6:                                     ; preds = %cond_next4
      %39 = call i32 @puts(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @__str_literal.65, i64 0, i64 0))
      br label %cond_next8

    cond_1_body7:                                     ; preds = %cond_1_test5
      %40 = call i32 @puts(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @__str_literal.66, i64 0, i64 0))
      br label %cond_next8

    cond_next8:                                       ; preds = %cond_1_body7, %cond_0_body6
      %41 = phi i32 [ %39, %cond_0_body6 ], [ %40, %cond_1_body7 ]
      ret void
    }

    define internal void @TestNestedStruct() {
    __funcbody:
      %0 = call %Vector3i @Vector3i(i32 1, i32 2, i32 3)
      %1 = call %Vector3i @Vector3i(i32 4, i32 5, i32 6)
      %2 = call %NestedStruct @NestedStruct(%Vector3i %0, %Vector3i %1)
      %3 = alloca %NestedStruct
      store %NestedStruct %2, %NestedStruct* %3
      %4 = getelementptr inbounds %NestedStruct, %NestedStruct* %3, i32 0, i32 0
      %5 = getelementptr inbounds %Vector3i, %Vector3i* %4, i32 0, i32 0
      %6 = load i32, i32* %5
      %7 = getelementptr inbounds %NestedStruct, %NestedStruct* %3, i32 0, i32 1
      %8 = getelementptr inbounds %Vector3i, %Vector3i* %7, i32 0, i32 2
      %9 = load i32, i32* %8
      %10 = add i32 %6, %9
      %11 = icmp eq i32 %10, 7
      br i1 %11, label %cond_0_body, label %cond_1_test

    cond_1_test:                                      ; preds = %__funcbody
      br label %cond_1_body

    cond_0_body:                                      ; preds = %__funcbody
      %12 = call i32 @puts(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @__str_literal.67, i64 0, i64 0))
      br label %cond_next

    cond_1_body:                                      ; preds = %cond_1_test
      %13 = call i32 @puts(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @__str_literal.68, i64 0, i64 0))
      br label %cond_next

    cond_next:                                        ; preds = %cond_1_body, %cond_0_body
      %14 = phi i32 [ %12, %cond_0_body ], [ %13, %cond_1_body ]
      %15 = getelementptr inbounds %NestedStruct, %NestedStruct* %3, i32 0, i32 0
      %16 = getelementptr inbounds %Vector3i, %Vector3i* %15, i32 0, i32 0
      store i32 5, i32* %16
      %17 = getelementptr inbounds %NestedStruct, %NestedStruct* %3, i32 0, i32 1
      %18 = getelementptr inbounds %Vector3i, %Vector3i* %17, i32 0, i32 2
      store i32 5, i32* %18
      %19 = getelementptr inbounds %NestedStruct, %NestedStruct* %3, i32 0, i32 0
      %20 = getelementptr inbounds %Vector3i, %Vector3i* %19, i32 0, i32 0
      %21 = load i32, i32* %20
      %22 = getelementptr inbounds %NestedStruct, %NestedStruct* %3, i32 0, i32 1
      %23 = getelementptr inbounds %Vector3i, %Vector3i* %22, i32 0, i32 2
      %24 = load i32, i32* %23
      %25 = add i32 %21, %24
      %26 = icmp eq i32 %25, 10
      br i1 %26, label %cond_0_body2, label %cond_1_test1

    cond_1_test1:                                     ; preds = %cond_next
      br label %cond_1_body3

    cond_0_body2:                                     ; preds = %cond_next
      %27 = call i32 @puts(i8* getelementptr inbounds ([34 x i8], [34 x i8]* @__str_literal.69, i64 0, i64 0))
      br label %cond_next4

    cond_1_body3:                                     ; preds = %cond_1_test1
      %28 = call i32 @puts(i8* getelementptr inbounds ([34 x i8], [34 x i8]* @__str_literal.70, i64 0, i64 0))
      br label %cond_next4

    cond_next4:                                       ; preds = %cond_1_body3, %cond_0_body2
      %29 = phi i32 [ %27, %cond_0_body2 ], [ %28, %cond_1_body3 ]
      ret void
    }

</pre></td>
</tr>
</table>
