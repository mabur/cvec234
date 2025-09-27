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
        printf("%s ", description);
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
        printf("%s ", description);
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
        printf("%s ", description);
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
        printf("%s ", description);
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
        printf("%s ", description);
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
        printf("%s ", description);
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
    float2 Vf2 = {1,2};
    float3 Vf3 = {1,2,3};
    float4 Vf4 = {1,2,3,4};

    double2 Vd2 = {1,2};
    double3 Vd3 = {1,2,3};
    double4 Vd4 = {1,2,3,4};

    float2x2 If2 = {.columns={{1,0},{0,1}}};
    double2x2 Id2 = {.columns={{1,0},{0,1}}};
    float3x3 If3 = {.columns={{1,0,0},{0,1,0},{0,0,1}}};
    double3x3 Id3 = {.columns={{1,0,0},{0,1,0},{0,0,1}}};
    float4x4 If4 = {.columns={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};
    double4x4 Id4 = {.columns={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};

    double4x4 ScaleUpXd4 = {.columns={{2,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};
    double4x4 ScaleUpYd4 = {.columns={{1,0,0,0},{0,2,0,0},{0,0,1,0},{0,0,0,1}}};
    double4x4 ScaleUpZd4 = {.columns={{1,0,0,0},{0,1,0,0},{0,0,2,0},{0,0,0,1}}};
    double4x4 ScaleUpWd4 = {.columns={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,2}}};

    double4x4 ScaleDownXd4 = {.columns={{.5,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};
    double4x4 ScaleDownYd4 = {.columns={{1,0,0,0},{0,.5,0,0},{0,0,1,0},{0,0,0,1}}};
    double4x4 ScaleDownZd4 = {.columns={{1,0,0,0},{0,1,0,0},{0,0,.5,0},{0,0,0,1}}};
    double4x4 ScaleDownWd4 = {.columns={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,.5}}};

    double2x2 Td2_forward = {.columns={{1,0},{2,1}}};
    double2x2 Td2_backward = {.columns={{1,0},{-2,1}}};

    double3x3 Td3_forward = {.columns={{1,0,0},{0,1,0},{2,3,1}}};
    double3x3 Td3_backward = {.columns={{1,0,0},{0,1,0},{-2,-3,1}}};

    double4x4 Td4_forward = {.columns={{1,0,0,0},{0,1,0,0},{0,0,1,0},{2,3,4,1}}};
    double4x4 Td4_backward = {.columns={{1,0,0,0},{0,1,0,0},{0,0,1,0},{-2,-3,-4,1}}};

    ASSERT_EQUAL_INT("DOT2", DOT2(((int2){1,2}), ((int2){3,4})), 11);
    ASSERT_EQUAL_INT("DOT3", DOT3(((int3){1,2,3}), ((int3){4,5,6})), 32);
    ASSERT_EQUAL_INT("DOT4", DOT4(((int3){1,2,3,4}), ((int3){5,6,7,8})), 70);

    ASSERT_EQUAL_INT("SQUARED_NORM2", SQUARED_NORM2(((int2){1,2})), 5);
    ASSERT_EQUAL_INT("SQUARED_NORM3", SQUARED_NORM3(((int3){1,2,3})), 14);

    ASSERT_EQUAL_INT("SQUARED_DISTANCE2", SQUARED_DISTANCE2(((int2){1,2}), ((int2){3,4})), 8);
    ASSERT_EQUAL_INT("SQUARED_DISTANCE3", SQUARED_DISTANCE3(((int3){1,2,3}), ((int3){4,5,6})), 27);

    ASSERT_EQUAL_FLOAT2("mul_float2x2_float2", mul_float2x2_float2(If2, Vf2), Vf2);
    ASSERT_EQUAL_FLOAT3("mul_float3x3_float3", mul_float3x3_float3(If3, Vf3), Vf3);
    ASSERT_EQUAL_FLOAT4("mul_float4x4_float4", mul_float4x4_float4(If4, Vf4), Vf4);

    ASSERT_EQUAL_FLOAT2("MUL float2x2 float2", MUL(If2, Vf2), Vf2);
    ASSERT_EQUAL_FLOAT3("MUL float3x3 float3", MUL(If3, Vf3), Vf3);
    ASSERT_EQUAL_FLOAT4("MUL float4x4 float4", MUL(If4, Vf4), Vf4);

    ASSERT_EQUAL_DOUBLE2("mul_double2x2_double2", mul_double2x2_double2(Id2, Vd2), Vd2);
    ASSERT_EQUAL_DOUBLE3("mul_double3x3_double3", mul_double3x3_double3(Id3, Vd3), Vd3);
    ASSERT_EQUAL_DOUBLE4("mul_double4x4_double4", mul_double4x4_double4(Id4, Vd4), Vd4);

    ASSERT_EQUAL_DOUBLE2("MUL double2x2 double2", MUL(Id2, Vd2), Vd2);
    ASSERT_EQUAL_DOUBLE3("MUL double3x3 double3", MUL(Id3, Vd3), Vd3);
    ASSERT_EQUAL_DOUBLE4("MUL double4x4 double4", MUL(Id4, Vd4), Vd4);

    ASSERT_EQUAL_DOUBLE4("mul_double4x4_double4 X", mul_double4x4_double4(ScaleUpXd4, (double4){1,2,3,4}), (double4){2,2,3,4});
    ASSERT_EQUAL_DOUBLE4("mul_double4x4_double4 Y", mul_double4x4_double4(ScaleUpYd4, (double4){1,2,3,4}), (double4){1,4,3,4});
    ASSERT_EQUAL_DOUBLE4("mul_double4x4_double4 Z", mul_double4x4_double4(ScaleUpZd4, (double4){1,2,3,4}), (double4){1,2,6,4});
    ASSERT_EQUAL_DOUBLE4("mul_double4x4_double4 W", mul_double4x4_double4(ScaleUpWd4, (double4){1,2,3,4}), (double4){1,2,3,8});

    ASSERT_EQUAL_FLOAT2x2("mul_float2x2_float2x2", mul_float2x2_float2x2(If2, If2), If2);
    ASSERT_EQUAL_FLOAT3x3("mul_float3x3_float3x3", mul_float3x3_float3x3(If3, If3), If3);
    ASSERT_EQUAL_FLOAT4x4("mul_float4x4_float4x4", mul_float4x4_float4x4(If4, If4), If4);

    ASSERT_EQUAL_FLOAT2x2("MUL float2x2 float2x2", MUL(If2, If2), If2);
    ASSERT_EQUAL_FLOAT3x3("MUL float3x3 float3x3", MUL(If3, If3), If3);
    ASSERT_EQUAL_FLOAT4x4("MUL float4x4 float4x4", MUL(If4, If4), If4);

    ASSERT_EQUAL_DOUBLE2x2("mul_double2x2_double2x2", mul_double2x2_double2x2(Id2, Id2), Id2);
    ASSERT_EQUAL_DOUBLE3x3("mul_double3x3_double3x3", mul_double3x3_double3x3(Id3, Id3), Id3);
    ASSERT_EQUAL_DOUBLE4x4("mul_double4x4_double4x4", mul_double4x4_double4x4(Id4, Id4), Id4);

    ASSERT_EQUAL_DOUBLE4x4("mul_double4x4_double4x4 X", mul_double4x4_double4x4(ScaleUpXd4, ScaleDownXd4), Id4);
    ASSERT_EQUAL_DOUBLE4x4("mul_double4x4_double4x4 Y", mul_double4x4_double4x4(ScaleUpYd4, ScaleDownYd4), Id4);
    ASSERT_EQUAL_DOUBLE4x4("mul_double4x4_double4x4 Z", mul_double4x4_double4x4(ScaleUpZd4, ScaleDownZd4), Id4);
    ASSERT_EQUAL_DOUBLE4x4("mul_double4x4_double4x4 W", mul_double4x4_double4x4(ScaleUpWd4, ScaleDownWd4), Id4);

    ASSERT_EQUAL_DOUBLE2x2("mul_double2x2_double2x2 translation", mul_double2x2_double2x2(Td2_forward, Td2_backward), Id2);
    ASSERT_EQUAL_DOUBLE2x2("mul_double2x2_double2x2 translation", mul_double2x2_double2x2(Td2_backward, Td2_forward), Id2);

    ASSERT_EQUAL_DOUBLE3x3("mul_double3x3_double3x3 translation", mul_double3x3_double3x3(Td3_forward, Td3_backward), Id3);
    ASSERT_EQUAL_DOUBLE3x3("mul_double3x3_double3x3 translation", mul_double3x3_double3x3(Td3_backward, Td3_forward), Id3);

    ASSERT_EQUAL_DOUBLE4x4("mul_double4x4_double4x4 translation", mul_double4x4_double4x4(Td4_forward, Td4_backward), Id4);
    ASSERT_EQUAL_DOUBLE4x4("mul_double4x4_double4x4 translation", mul_double4x4_double4x4(Td4_backward, Td4_forward), Id4);

    ASSERT_EQUAL_DOUBLE2x2("MUL double2x2 double2x2", MUL(Id2, Id2), Id2);
    ASSERT_EQUAL_DOUBLE3x3("MUL double3x3 double3x3", MUL(Id3, Id3), Id3);
    ASSERT_EQUAL_DOUBLE4x4("MUL double4x4 double4x4", MUL(Id4, Id4), Id4);

    ASSERT_EQUAL_FLOAT2x2("inverse_float2x2", inverse_float2x2(If2), If2);
    ASSERT_EQUAL_FLOAT3x3("inverse_float3x3", inverse_float3x3(If3), If3);
    ASSERT_EQUAL_FLOAT4x4("inverse_float4x4", inverse_float4x4(If4), If4);

    ASSERT_EQUAL_DOUBLE2x2("inverse_double2x2", inverse_double2x2(Id2), Id2);
    ASSERT_EQUAL_DOUBLE3x3("inverse_double3x3", inverse_double3x3(Id3), Id3);
    ASSERT_EQUAL_DOUBLE4x4("inverse_double4x4", inverse_double4x4(Id4), Id4);

    ASSERT_EQUAL_DOUBLE4x4("inverse_double4x4 X", inverse_double4x4(ScaleUpXd4), ScaleDownXd4);
    ASSERT_EQUAL_DOUBLE4x4("inverse_double4x4 Y", inverse_double4x4(ScaleUpYd4), ScaleDownYd4);
    ASSERT_EQUAL_DOUBLE4x4("inverse_double4x4 Z", inverse_double4x4(ScaleUpZd4), ScaleDownZd4);
    ASSERT_EQUAL_DOUBLE4x4("inverse_double4x4 W", inverse_double4x4(ScaleUpWd4), ScaleDownWd4);

    ASSERT_EQUAL_DOUBLE2x2("inverse_double2x2 translation 1", inverse_double2x2(Td2_forward), Td2_backward);
    ASSERT_EQUAL_DOUBLE2x2("inverse_double2x2 translation 2", inverse_double2x2(Td2_backward), Td2_forward);

    ASSERT_EQUAL_DOUBLE3x3("inverse_double3x3 translation 1", inverse_double3x3(Td3_forward), Td3_backward);
    ASSERT_EQUAL_DOUBLE3x3("inverse_double3x3 translation 2", inverse_double3x3(Td3_backward), Td3_forward);

    ASSERT_EQUAL_DOUBLE4x4("inverse_double4x4 translation 1", inverse_double4x4(Td4_forward), Td4_backward);
    ASSERT_EQUAL_DOUBLE4x4("inverse_double4x4 translation 2", inverse_double4x4(Td4_backward), Td4_forward);

    ASSERT_EQUAL_FLOAT2x2("INVERSE float 2x2", INVERSE(If2), If2);
    ASSERT_EQUAL_FLOAT3x3("INVERSE float 3x3", INVERSE(If3), If3);
    ASSERT_EQUAL_FLOAT4x4("INVERSE float 4x4", INVERSE(If4), If4);

    ASSERT_EQUAL_DOUBLE2x2("INVERSE double 2x2", INVERSE(Id2), Id2);
    ASSERT_EQUAL_DOUBLE3x3("INVERSE double 3x3", INVERSE(Id3), Id3);
    ASSERT_EQUAL_DOUBLE4x4("INVERSE double 4x4", INVERSE(Id4), Id4);

    ASSERT_EQUAL_FLOAT4x4("rotate_around_x_4 float", rotate_around_x_4(0.f), If4);
    ASSERT_EQUAL_FLOAT4x4("rotate_around_y_4 float", rotate_around_y_4(0.f), If4);
    ASSERT_EQUAL_FLOAT4x4("rotate_around_z_4 float", rotate_around_z_4(0.f), If4);
    ASSERT_EQUAL_FLOAT4x4("translate_4 float", translate_4(0.f, 0.f, 0.f), If4);

    ASSERT_EQUAL_DOUBLE4x4("rotate_around_x_4 double", rotate_around_x_4(0.0), Id4);
    ASSERT_EQUAL_DOUBLE4x4("rotate_around_y_4 double", rotate_around_y_4(0.0), Id4);
    ASSERT_EQUAL_DOUBLE4x4("rotate_around_z_4 double", rotate_around_z_4(0.0), Id4);
    ASSERT_EQUAL_DOUBLE4x4("translate_4 double", translate_4(0.0, 0.0, 0.0), Id4);

    summarize_tests();
    return 0;
}
