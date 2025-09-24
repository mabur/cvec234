#include <stdio.h>

#include <cvec234/matrix.h>
#include <cvec234/matrix_printing.h>
#include <cvec234/vector.h>
#include <cvec234/vector_printing.h>

int global_assert_count = 0;
int global_assert_errors = 0;

void ASSERT_BOOL(const char* description, bool a) {
    global_assert_count++;
    if (a) {
        printf("%s ok\n", (description));
    } else {
        printf("%s bad\n", (description));
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_INT(const char* description, int a, int b) {
    global_assert_count++;
    if (a == b) {
        printf("%s ok\n", (description));
    } else {
        printf("%s %i!=%i bad\n", (description), (a), (b));
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_FLOAT2(const char* description, float2 a, float2 b) {
    global_assert_count++;
    if (ARE_EQUAL_VECTOR2(a, b)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ");
        print_float2(a);
        printf("!=");
        print_float2(b);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_DOUBLE2(const char* description, double2 a, double2 b) {
    global_assert_count++;
    if (ARE_EQUAL_VECTOR2(a, b)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ");
        print_double2(a);
        printf("!=");
        print_double2(b);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_FLOAT3(const char* description, float3 a, float3 b) {
    global_assert_count++;
    if (ARE_EQUAL_VECTOR3(a, b)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ");
        print_float3(a);
        printf("!=");
        print_float3(b);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_DOUBLE3(const char* description, double3 a, double3 b) {
    global_assert_count++;
    if (ARE_EQUAL_VECTOR3(a, b)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ");
        print_double3(a);
        printf("!=");
        print_double3(b);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_FLOAT4(const char* description, float4 a, float4 b) {
    global_assert_count++;
    if (ARE_EQUAL_VECTOR4(a, b)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ");
        print_float4(a);
        printf("!=");
        print_float4(b);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_DOUBLE4(const char* description, double4 a, double4 b) {
    global_assert_count++;
    if (ARE_EQUAL_VECTOR4(a, b)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ");
        print_double4(a);
        printf("!=");
        print_double4(b);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_FLOAT2x2(const char* description, float2x2 A, float2x2 B) {
    global_assert_count++;
    if (ARE_EQUAL_MATRIX2(A, B)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ", description);
        print_float2x2(A);
        printf("!=");
        print_float2x2(B);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_DOUBLE2x2(const char* description, double2x2 A, double2x2 B) {
    global_assert_count++;
    if (ARE_EQUAL_MATRIX2(A, B)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ", description);
        print_double2x2(A);
        printf("!=");
        print_double2x2(B);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_FLOAT3x3(const char* description, float3x3 A, float3x3 B) {
    global_assert_count++;
    if (ARE_EQUAL_MATRIX3(A, B)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ", description);
        print_float3x3(A);
        printf("!=");
        print_float3x3(B);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_DOUBLE3x3(const char* description, double3x3 A, double3x3 B) {
    global_assert_count++;
    if (ARE_EQUAL_MATRIX3(A, B)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ", description);
        print_double3x3(A);
        printf("!=");
        print_double3x3(B);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_FLOAT4x4(const char* description, float4x4 A, float4x4 B) {
    global_assert_count++;
    if (ARE_EQUAL_MATRIX4(A, B)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ", description);
        print_float4x4(A);
        printf("!=");
        print_float4x4(B);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_DOUBLE4x4(const char* description, double4x4 A, double4x4 B) {
    global_assert_count++;
    if (ARE_EQUAL_MATRIX4(A, B)) {
        printf("%s ok\n", description);
    } else {
        printf("%s ", description);
        print_double4x4(A);
        printf("!=");
        print_double4x4(B);
        printf(" bad\n");
        global_assert_errors++;
    }
}

void summarize_tests() {
    if (global_assert_errors != 0) {
        printf("%d/%d test failed\n", global_assert_errors, global_assert_count);
    } else {
        printf("All %d test succeeded\n", global_assert_count);
    }
}

int main() {
    float2x2 If2 = {.columns={{1,0},{0,1}}};
    double2x2 Id2 = {.columns={{1,0},{0,1}}};
    float3x3 If3 = {.columns={{1,0,0},{0,1,0},{0,0,1}}};
    double3x3 Id3 = {.columns={{1,0,0},{0,1,0},{0,0,1}}};
    float4x4 If4 = {.columns={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};
    double4x4 Id4 = {.columns={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};

    ASSERT_EQUAL_INT("DOT2", DOT2(((int2){1,2}), ((int2){3,4})), 11);
    ASSERT_EQUAL_INT("DOT3", DOT3(((int3){1,2,3}), ((int3){4,5,6})), 32);
    ASSERT_EQUAL_INT("DOT4", DOT4(((int3){1,2,3,4}), ((int3){5,6,7,8})), 70);

    ASSERT_EQUAL_INT("SQUARED_NORM2", SQUARED_NORM2(((int2){1,2})), 5);
    ASSERT_EQUAL_INT("SQUARED_NORM3", SQUARED_NORM3(((int3){1,2,3})), 14);

    ASSERT_EQUAL_INT("SQUARED_DISTANCE2", SQUARED_DISTANCE2(((int2){1,2}), ((int2){3,4})), 8);
    ASSERT_EQUAL_INT("SQUARED_DISTANCE3", SQUARED_DISTANCE3(((int3){1,2,3}), ((int3){4,5,6})), 27);

    ASSERT_EQUAL_FLOAT2("mul_float2x2_float2", mul_float2x2_float2(If2, (float2){1,2}), (float2){1,2});
    ASSERT_EQUAL_FLOAT3("mul_float3x3_float3", mul_float3x3_float3(If3, (float3){1,2,3}), (float3){1,2,3});
    ASSERT_EQUAL_FLOAT4("mul_float4x4_float4", mul_float4x4_float4(If4, (float4){1,2,3,4}), (float4){1,2,3,4});

    ASSERT_EQUAL_DOUBLE2("mul_double2x2_double2", mul_double2x2_double2(Id2, (double2){1,2}), (double2){1,2});
    ASSERT_EQUAL_DOUBLE3("mul_double3x3_double3", mul_double3x3_double3(Id3, (double3){1,2,3}), (double3){1,2,3});
    ASSERT_EQUAL_DOUBLE4("mul_double4x4_double4", mul_double4x4_double4(Id4, (double4){1,2,3,4}), (double4){1,2,3,4});

    ASSERT_EQUAL_FLOAT2x2("mul_float2x2_float2x2", mul_float2x2_float2x2(If2, If2), If2);
    ASSERT_EQUAL_FLOAT3x3("mul_float3x3_float3x3", mul_float3x3_float3x3(If3, If3), If3);
    ASSERT_EQUAL_FLOAT4x4("mul_float4x4_float4x4", mul_float4x4_float4x4(If4, If4), If4);

    ASSERT_EQUAL_DOUBLE2x2("mul_double2x2_double2x2", mul_double2x2_double2x2(Id2, Id2), Id2);
    ASSERT_EQUAL_DOUBLE3x3("mul_double3x3_double3x3", mul_double3x3_double3x3(Id3, Id3), Id3);
    ASSERT_EQUAL_DOUBLE4x4("mul_double4x4_double4x4", mul_double4x4_double4x4(Id4, Id4), Id4);

    ASSERT_EQUAL_FLOAT2x2("inverse_float2x2", inverse_float2x2(If2), If2);
    ASSERT_EQUAL_FLOAT3x3("inverse_float3x3", inverse_float3x3(If3), If3);
    ASSERT_EQUAL_FLOAT4x4("inverse_float4x4", inverse_float4x4(If4), If4);

    ASSERT_EQUAL_DOUBLE2x2("inverse_double2x2", inverse_double2x2(Id2), Id2);
    ASSERT_EQUAL_DOUBLE3x3("inverse_double3x3", inverse_double3x3(Id3), Id3);
    ASSERT_EQUAL_DOUBLE4x4("inverse_double4x4", inverse_double4x4(Id4), Id4);

    ASSERT_EQUAL_FLOAT2x2("INVERSE float 2x2", INVERSE(If2), If2);
    ASSERT_EQUAL_FLOAT3x3("INVERSE float 3x3", INVERSE(If3), If3);
    ASSERT_EQUAL_FLOAT4x4("INVERSE float 4x4", INVERSE(If4), If4);

    ASSERT_EQUAL_DOUBLE2x2("INVERSE double 2x2", INVERSE(Id2), Id2);
    ASSERT_EQUAL_DOUBLE3x3("INVERSE double 3x3", INVERSE(Id3), Id3);
    ASSERT_EQUAL_DOUBLE4x4("INVERSE double 4x4", INVERSE(Id4), Id4);

    summarize_tests();
    return 0;
}
