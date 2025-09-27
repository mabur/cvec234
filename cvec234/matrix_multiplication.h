#pragma once

#include "matrix_core.h"

////////////////////////////////////////////////////////////////////////////////
// Matrix-vector multiplication:

#define MUL_2x2_2(A, b) ( \
    (A).columns[0] * (b)[0] + \
    (A).columns[1] * (b)[1]   \
)

#define MUL_3x3_3(A, b) ( \
    (A).columns[0] * (b)[0] + \
    (A).columns[1] * (b)[1] + \
    (A).columns[2] * (b)[2]   \
)

#define MUL_4x4_4(A, b) ( \
    (A).columns[0] * (b)[0] + \
    (A).columns[1] * (b)[1] + \
    (A).columns[2] * (b)[2] + \
    (A).columns[3] * (b)[3]   \
)

static inline float2 mul_float2x2_float2(float2x2 A, float2 b) {
    return MUL_2x2_2(A, b);
}

static inline double2 mul_double2x2_double2(double2x2 A, double2 b) {
    return MUL_2x2_2(A, b);
}

static inline float3 mul_float3x3_float3(float3x3 A, float3 b) {
    return MUL_3x3_3(A, b);
}

static inline double3 mul_double3x3_double3(double3x3 A, double3 b) {
    return MUL_3x3_3(A, b);
}

static inline float4 mul_float4x4_float4(float4x4 A, float4 b) {
    return MUL_4x4_4(A, b);
}

static inline double4 mul_double4x4_double4(double4x4 A, double4 b) {
    return MUL_4x4_4(A, b);
}

////////////////////////////////////////////////////////////////////////////////
// Matrix-matrix multiplication:

static inline float2x2 mul_float2x2_float2x2(float2x2 A, float2x2 B) {
    float2x2 R;
    R.columns[0] = A.columns[0] * B.columns[0][0] + A.columns[1] * B.columns[0][1];
    R.columns[1] = A.columns[0] * B.columns[1][0] + A.columns[1] * B.columns[1][1];
    return R;
}

static inline double2x2 mul_double2x2_double2x2(double2x2 A, double2x2 B) {
    double2x2 R;
    R.columns[0] = A.columns[0] * B.columns[0][0] + A.columns[1] * B.columns[0][1];
    R.columns[1] = A.columns[0] * B.columns[1][0] + A.columns[1] * B.columns[1][1];
    return R;
}

static inline float3x3 mul_float3x3_float3x3(float3x3 A, float3x3 B) {
    float3x3 R;
    R.columns[0] = A.columns[0] * B.columns[0][0] + A.columns[1] * B.columns[0][1] + A.columns[2] * B.columns[0][2];
    R.columns[1] = A.columns[0] * B.columns[1][0] + A.columns[1] * B.columns[1][1] + A.columns[2] * B.columns[1][2];
    R.columns[2] = A.columns[0] * B.columns[2][0] + A.columns[1] * B.columns[2][1] + A.columns[2] * B.columns[2][2];
    return R;
}

static inline double3x3 mul_double3x3_double3x3(double3x3 A, double3x3 B) {
    double3x3 R;
    R.columns[0] = A.columns[0] * B.columns[0][0] + A.columns[1] * B.columns[0][1] + A.columns[2] * B.columns[0][2];
    R.columns[1] = A.columns[0] * B.columns[1][0] + A.columns[1] * B.columns[1][1] + A.columns[2] * B.columns[1][2];
    R.columns[2] = A.columns[0] * B.columns[2][0] + A.columns[1] * B.columns[2][1] + A.columns[2] * B.columns[2][2];
    return R;
}

static inline float4x4 mul_float4x4_float4x4(float4x4 A, float4x4 B) {
    float4x4 R;
    R.columns[0] = A.columns[0] * B.columns[0][0] + A.columns[1] * B.columns[0][1] + A.columns[2] * B.columns[0][2] + A.columns[3] * B.columns[0][3];
    R.columns[1] = A.columns[0] * B.columns[1][0] + A.columns[1] * B.columns[1][1] + A.columns[2] * B.columns[1][2] + A.columns[3] * B.columns[1][3];
    R.columns[2] = A.columns[0] * B.columns[2][0] + A.columns[1] * B.columns[2][1] + A.columns[2] * B.columns[2][2] + A.columns[3] * B.columns[2][3];
    R.columns[3] = A.columns[0] * B.columns[3][0] + A.columns[1] * B.columns[3][1] + A.columns[2] * B.columns[3][2] + A.columns[3] * B.columns[3][3];
    return R;
}

static inline double4x4 mul_double4x4_double4x4(double4x4 A, double4x4 B) {
    double4x4 R;
    R.columns[0] = A.columns[0] * B.columns[0][0] + A.columns[1] * B.columns[0][1] + A.columns[2] * B.columns[0][2] + A.columns[3] * B.columns[0][3];
    R.columns[1] = A.columns[0] * B.columns[1][0] + A.columns[1] * B.columns[1][1] + A.columns[2] * B.columns[1][2] + A.columns[3] * B.columns[1][3];
    R.columns[2] = A.columns[0] * B.columns[2][0] + A.columns[1] * B.columns[2][1] + A.columns[2] * B.columns[2][2] + A.columns[3] * B.columns[2][3];
    R.columns[3] = A.columns[0] * B.columns[3][0] + A.columns[1] * B.columns[3][1] + A.columns[2] * B.columns[3][2] + A.columns[3] * B.columns[3][3];
    return R;
}

////////////////////////////////////////////////////////////////////////////////
// DEFINE OVERLOADED/GENERIC FUNCTIONS

#ifdef __cplusplus

static inline float2 MUL(float2x2 A, float2 B) { return mul_float2x2_float2(A, B); }
static inline float3 MUL(float3x3 A, float3 B) { return mul_float3x3_float3(A, B); }
static inline float4 MUL(float4x4 A, float4 B) { return mul_float4x4_float4(A, B); }

static inline float2x2 MUL(float2x2 A, float2x2 B) { return mul_float2x2_float2x2(A, B); }
static inline float3x3 MUL(float3x3 A, float3x3 B) { return mul_float3x3_float3x3(A, B); }
static inline float4x4 MUL(float4x4 A, float4x4 B) { return mul_float4x4_float4x4(A, B); }

static inline double2 MUL(double2x2 A, double2 B) { return mul_double2x2_double2(A, B); }
static inline double3 MUL(double3x3 A, double3 B) { return mul_double3x3_double3(A, B); }
static inline double4 MUL(double4x4 A, double4 B) { return mul_double4x4_double4(A, B); }

static inline double2x2 MUL(double2x2 A, double2x2 B) { return mul_double2x2_double2x2(A, B); }
static inline double3x3 MUL(double3x3 A, double3x3 B) { return mul_double3x3_double3x3(A, B); }
static inline double4x4 MUL(double4x4 A, double4x4 B) { return mul_double4x4_double4x4(A, B); }

#else

#define CVEC_BAD_SIG ((void)0)
#define MUL(A, B) _Generic((A), \
T_float2x2:  _Generic((B), T_float2:  mul_float2x2_float2, T_float2x2: mul_float2x2_float2x2, default: CVEC_BAD_SIG), \
T_float3x3:  _Generic((B), T_float3:  mul_float3x3_float3, T_float3x3: mul_float3x3_float3x3, default: CVEC_BAD_SIG), \
T_float4x4:  _Generic((B), T_float4:  mul_float4x4_float4, T_float4x4: mul_float4x4_float4x4, default: CVEC_BAD_SIG), \
T_double2x2: _Generic((B), T_double2: mul_double2x2_double2, T_double2x2: mul_double2x2_double2x2, default: CVEC_BAD_SIG), \
T_double3x3: _Generic((B), T_double3: mul_double3x3_double3, T_double3x3: mul_double3x3_double3x3, default: CVEC_BAD_SIG), \
T_double4x4: _Generic((B), T_double4: mul_double4x4_double4, T_double4x4: mul_double4x4_double4x4, default: CVEC_BAD_SIG),\
default: CVEC_BAD_SIG \
)(A, B)

#endif
