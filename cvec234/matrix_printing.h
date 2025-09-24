#pragma once

#include <stdio.h>

#include "matrix.h"

static inline void print_float2x2(float2x2 A) {
    printf("[%f,%f;%f,%f]",
        A.columns[0][0], A.columns[1][0],
        A.columns[0][1], A.columns[1][1]
    );
}

static inline void print_double2x2(double2x2 A) {
    printf("[%lf,%lf;%lf,%lf]",
        A.columns[0][0], A.columns[1][0],
        A.columns[0][1], A.columns[1][1]
    );
}

static inline void print_float3x3(float3x3 A) {
    printf("[%f,%f,%f;%f,%f,%f;%f,%f,%f]",
        A.columns[0][0], A.columns[1][0], A.columns[2][0],
        A.columns[0][1], A.columns[1][1], A.columns[2][1],
        A.columns[0][2], A.columns[1][2], A.columns[2][2]
    );
}

static inline void print_double3x3(double3x3 A) {
    printf("[%lf,%lf,%lf;%lf,%lf,%lf;%lf,%lf,%lf]",
        A.columns[0][0], A.columns[1][0], A.columns[2][0],
        A.columns[0][1], A.columns[1][1], A.columns[2][1],
        A.columns[0][2], A.columns[1][2], A.columns[2][2]
    );
}

static inline void print_float4x4(float4x4 A) {
    printf("[%f,%f,%f,%f;%f,%f,%f,%f;%f,%f,%f,%f;%f,%f,%f,%f]",
        A.columns[0][0], A.columns[1][0], A.columns[2][0], A.columns[3][0],
        A.columns[0][1], A.columns[1][1], A.columns[2][1], A.columns[3][1],
        A.columns[0][2], A.columns[1][2], A.columns[2][2], A.columns[3][2],
        A.columns[0][3], A.columns[1][3], A.columns[2][3], A.columns[3][3]
    );
}

static inline void print_double4x4(double4x4 A) {
    printf("[%lf,%lf,%lf,%lf;%lf,%lf,%lf,%lf;%lf,%lf,%lf,%lf;%lf,%lf,%lf,%lf]",
        A.columns[0][0], A.columns[1][0], A.columns[2][0], A.columns[3][0],
        A.columns[0][1], A.columns[1][1], A.columns[2][1], A.columns[3][1],
        A.columns[0][2], A.columns[1][2], A.columns[2][2], A.columns[3][2],
        A.columns[0][3], A.columns[1][3], A.columns[2][3], A.columns[3][3]
    );
}
