#pragma once

#include <stdio.h>

#include "vector.h"

static inline void print_float2(float2 a) {
    printf("[%f,%f]", a[0], a[1]);
}

static inline void print_double2(double2 a) {
    printf("[%lf,%lf]", a[0], a[1]);
}

static inline void print_int2(int2 a) {
    printf("[%d,%d]", a[0], a[1]);
}

static inline void print_float3(float3 a) {
    printf("[%f,%f,%f]", a[0], a[1], a[2]);
}

static inline void print_double3(double3 a) {
    printf("[%lf,%lf,%lf]", a[0], a[1], a[2]);
}

static inline void print_int3(int3 a) {
    printf("[%d,%d,%d]", a[0], a[1], a[2]);
}

static inline void print_float4(float4 a) {
    printf("[%f,%f,%f,%f]", a[0], a[1], a[2], a[3]);
}

static inline void print_double4(double4 a) {
    printf("[%lf,%lf,%lf,%lf]", a[0], a[1], a[2], a[3]);
}

static inline void print_int4(int4 a) {
    printf("[%d,%d,%d,%d]", a[0], a[1], a[2], a[3]);
}
