#include <stdio.h>

#include <cvec234/matrix.h>
#include <cvec234/vector.h>

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
    if (a[0] == b[0] && a[1] == b[1]) {
        printf("%s ok\n", description);
    } else {
        printf("%s [%f,%f]!=[%f,%f] bad\n", description, a[0], a[1], b[0], b[1]);
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_DOUBLE2(const char* description, double2 a, double2 b) {
    global_assert_count++;
    if (a[0] == b[0] && a[1] == b[1]) {
        printf("%s ok\n", description);
    } else {
        printf("%s [%f,%f]!=[%f,%f] bad\n", description, a[0], a[1], b[0], b[1]);
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_FLOAT3(const char* description, float3 a, float3 b) {
    global_assert_count++;
    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
        printf("%s ok\n", description);
    } else {
        printf("%s [%f,%f,%f]!=[%f,%f,%f] bad\n", description, a[0], a[1], a[2], b[0], b[1], b[2]);
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_DOUBLE3(const char* description, double3 a, double3 b) {
    global_assert_count++;
    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
        printf("%s ok\n", description);
    } else {
        printf("%s [%f,%f,%f]!=[%f,%f,%f] bad\n", description, a[0], a[1], a[2], b[0], b[1], b[2]);
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_FLOAT4(const char* description, float4 a, float4 b) {
    global_assert_count++;
    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]) {
        printf("%s ok\n", description);
    } else {
        printf("%s [%f,%f,%f,%f]!=[%f,%f,%f,%f] bad\n", description, a[0], a[1], a[2], a[3], b[0], b[1], b[2], b[3]);
        global_assert_errors++;
    }
}
void ASSERT_EQUAL_DOUBLE4(const char* description, double4 a, double4 b) {
    global_assert_count++;
    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]) {
        printf("%s ok\n", description);
    } else {
        printf("%s [%f,%f,%f,%f]!=[%f,%f,%f,%f] bad\n", description, a[0], a[1], a[2], a[3], b[0], b[1], b[2], b[3]);
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
    auto If2 = (float2x2){.columns={{1,0},{0,1}}};
    auto Id2 = (double2x2){.columns={{1,0},{0,1}}};
    auto If3 = (float3x3){.columns={{1,0,0},{0,1,0},{0,0,1}}};
    auto Id3 = (double3x3){.columns={{1,0,0},{0,1,0},{0,0,1}}};
    auto If4 = (float4x4){.columns={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};
    auto Id4 = (double4x4){.columns={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};

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

    summarize_tests();
    return 0;
}
