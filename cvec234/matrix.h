#pragma once

#include "vector.h"

#if defined(__GNUC__) || defined(__clang__)
    #define TYPE_OF_EXPRESSION(x) typeof(x)
#elif defined(__cplusplus)
    #define TYPE_OF_EXPRESSION(x) decltype(x)
#endif

typedef struct float2x2 {float2 columns[2];} float2x2;
typedef struct float3x3 {float3 columns[3];} float3x3;
typedef struct float4x4 {float4 columns[4];} float4x4;

typedef struct double2x2 {double2 columns[2];} double2x2;
typedef struct double3x3 {double3 columns[3];} double3x3;
typedef struct double4x4 {double4 columns[4];} double4x4;

#define T_float2   __typeof__((float2){})
#define T_float3   __typeof__((float3){})
#define T_float4   __typeof__((float4){})

#define T_double2  __typeof__((double2){})
#define T_double3  __typeof__((double3){})
#define T_double4  __typeof__((double4){})

#define T_float2x2   __typeof__((float2x2){})
#define T_float3x3   __typeof__((float3x3){})
#define T_float4x4   __typeof__((float4x4){})

#define T_double2x2  __typeof__((double2x2){})
#define T_double3x3  __typeof__((double3x3){})
#define T_double4x4  __typeof__((double4x4){})

////////////////////////////////////////////////////////////////////////////////
// Matrix equality:

#define ARE_EQUAL_MATRIX2(A, B) (\
    (A).columns[0][0] == (B).columns[0][0] && (A).columns[1][0] == (B).columns[1][0] && \
    (A).columns[0][1] == (B).columns[0][1] && (A).columns[1][1] == (B).columns[1][1])

#define ARE_EQUAL_MATRIX3(A, B) (\
    (A).columns[0][0] == (B).columns[0][0] && (A).columns[1][0] == (B).columns[1][0] && (A).columns[2][0] == (B).columns[2][0] && \
    (A).columns[0][1] == (B).columns[0][1] && (A).columns[1][1] == (B).columns[1][1] && (A).columns[2][1] == (B).columns[2][1] && \
    (A).columns[0][2] == (B).columns[0][2] && (A).columns[1][2] == (B).columns[1][2] && (A).columns[2][2] == (B).columns[2][2])

#define ARE_EQUAL_MATRIX4(A, B) (\
    (A).columns[0][0] == (B).columns[0][0] && (A).columns[1][0] == (B).columns[1][0] && (A).columns[2][0] == (B).columns[2][0] && (A).columns[3][0] == (B).columns[3][0] && \
    (A).columns[0][1] == (B).columns[0][1] && (A).columns[1][1] == (B).columns[1][1] && (A).columns[2][1] == (B).columns[2][1] && (A).columns[3][1] == (B).columns[3][1] && \
    (A).columns[0][2] == (B).columns[0][2] && (A).columns[1][2] == (B).columns[1][2] && (A).columns[2][2] == (B).columns[2][2] && (A).columns[3][2] == (B).columns[3][2] && \
    (A).columns[0][3] == (B).columns[0][3] && (A).columns[1][3] == (B).columns[1][3] && (A).columns[2][3] == (B).columns[2][3] && (A).columns[3][3] == (B).columns[3][3])

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
// Matrix-inverse

#define SET_INVERSE_2x2(in, out) do { \
    auto a = (in).columns[0][0]; \
    auto b = (in).columns[1][0]; \
    auto c = (in).columns[0][1]; \
    auto d = (in).columns[1][1]; \
    auto det = a * d - b * c; \
    auto inv_det = 1 / det; \
    (out).columns[0][0] = d; \
    (out).columns[0][1] = -c; \
    (out).columns[1][0] = -b; \
    (out).columns[1][1] = a; \
    (out).columns[0] *= inv_det; \
    (out).columns[1] *= inv_det; \
} while (0)

static inline float2x2 inverse_float2x2(float2x2 A) {
    float2x2 result;
    SET_INVERSE_2x2(A, result);
    return result;
}

static inline double2x2 inverse_double2x2(double2x2 A) {
    double2x2 result;
    SET_INVERSE_2x2(A, result);
    return result;
}

#define SET_INVERSE_3x3(in, out) do { \
    auto a00 = (in).columns[0][0]; \
    auto a01 = (in).columns[1][0]; \
    auto a02 = (in).columns[2][0]; \
    auto a10 = (in).columns[0][1]; \
    auto a11 = (in).columns[1][1]; \
    auto a12 = (in).columns[2][1]; \
    auto a20 = (in).columns[0][2]; \
    auto a21 = (in).columns[1][2]; \
    auto a22 = (in).columns[2][2]; \
    \
    auto C00 =  (a11 * a22 - a12 * a21); \
    auto C01 = -(a10 * a22 - a12 * a20); \
    auto C02 =  (a10 * a21 - a11 * a20); \
    \
    auto C10 = -(a01 * a22 - a02 * a21); \
    auto C11 =  (a00 * a22 - a02 * a20); \
    auto C12 = -(a00 * a21 - a01 * a20); \
    \
    auto C20 =  (a01 * a12 - a02 * a11); \
    auto C21 = -(a00 * a12 - a02 * a10); \
    auto C22 =  (a00 * a11 - a01 * a10); \
    \
    auto det = a00 * C00 + a01 * C01 + a02 * C02; \
    auto inv_det = (1) / det; \
    \
    (out).columns[0][0] = C00; \
    (out).columns[1][0] = C01; \
    (out).columns[2][0] = C02; \
    \
    (out).columns[0][1] = C10; \
    (out).columns[1][1] = C11; \
    (out).columns[2][1] = C12; \
    \
    (out).columns[0][2] = C20; \
    (out).columns[1][2] = C21; \
    (out).columns[2][2] = C22; \
    \
    (out).columns[0] *= inv_det; \
    (out).columns[1] *= inv_det; \
    (out).columns[2] *= inv_det; \
} while (0)

static inline float3x3 inverse_float3x3(float3x3 A) {
    float3x3 result;
    SET_INVERSE_3x3(A, result);
    return result;
}

static inline double3x3 inverse_double3x3(double3x3 A) {
    double3x3 result;
    SET_INVERSE_3x3(A, result);
    return result;
}

#define SET_INVERSE_4x4(in, out) do { \
    auto a00 = (in).columns[0][0]; \
    auto a01 = (in).columns[1][0]; \
    auto a02 = (in).columns[2][0]; \
    auto a03 = (in).columns[3][0]; \
    auto a10 = (in).columns[0][1]; \
    auto a11 = (in).columns[1][1]; \
    auto a12 = (in).columns[2][1]; \
    auto a13 = (in).columns[3][1]; \
    auto a20 = (in).columns[0][2]; \
    auto a21 = (in).columns[1][2]; \
    auto a22 = (in).columns[2][2]; \
    auto a23 = (in).columns[3][2]; \
    auto a30 = (in).columns[0][3]; \
    auto a31 = (in).columns[1][3]; \
    auto a32 = (in).columns[2][3]; \
    auto a33 = (in).columns[3][3]; \
    \
    auto C00 =  (a11*(a22*a33 - a23*a32) - a12*(a21*a33 - a23*a31) + a13*(a21*a32 - a22*a31)); \
    auto C01 = -(a10*(a22*a33 - a23*a32) - a12*(a20*a33 - a23*a30) + a13*(a20*a32 - a22*a30)); \
    auto C02 =  (a10*(a21*a33 - a23*a31) - a11*(a20*a33 - a23*a30) + a13*(a20*a31 - a21*a30)); \
    auto C03 = -(a10*(a21*a32 - a22*a31) - a11*(a20*a32 - a22*a30) + a12*(a20*a31 - a21*a30)); \
    \
    auto C10 = -(a01*(a22*a33 - a23*a32) - a02*(a21*a33 - a23*a31) + a03*(a21*a32 - a22*a31)); \
    auto C11 =  (a00*(a22*a33 - a23*a32) - a02*(a20*a33 - a23*a30) + a03*(a20*a32 - a22*a30)); \
    auto C12 = -(a00*(a21*a33 - a23*a31) - a01*(a20*a33 - a23*a30) + a03*(a20*a31 - a21*a30)); \
    auto C13 =  (a00*(a21*a32 - a22*a31) - a01*(a20*a32 - a22*a30) + a02*(a20*a31 - a21*a30)); \
    \
    auto C20 =  (a01*(a12*a33 - a13*a32) - a02*(a11*a33 - a13*a31) + a03*(a11*a32 - a12*a31)); \
    auto C21 = -(a00*(a12*a33 - a13*a32) - a02*(a10*a33 - a13*a30) + a03*(a10*a32 - a12*a30)); \
    auto C22 =  (a00*(a11*a33 - a13*a31) - a01*(a10*a33 - a13*a30) + a03*(a10*a31 - a11*a30)); \
    auto C23 = -(a00*(a11*a32 - a12*a31) - a01*(a10*a32 - a12*a30) + a02*(a10*a31 - a11*a30)); \
    \
    auto C30 = -(a01*(a12*a23 - a13*a22) - a02*(a11*a23 - a13*a21) + a03*(a11*a22 - a12*a21)); \
    auto C31 =  (a00*(a12*a23 - a13*a22) - a02*(a10*a23 - a13*a20) + a03*(a10*a22 - a12*a20)); \
    auto C32 = -(a00*(a11*a23 - a13*a21) - a01*(a10*a23 - a13*a20) + a03*(a10*a21 - a11*a20)); \
    auto C33 =  (a00*(a11*a22 - a12*a21) - a01*(a10*a22 - a12*a20) + a02*(a10*a21 - a11*a20)); \
    \
    auto det = a00*C00 + a01*C01 + a02*C02 + a03*C03; \
    auto inv_det = (1) / det; \
    \
    (out).columns[0][0] = C00; \
    (out).columns[1][0] = C01; \
    (out).columns[2][0] = C02; \
    (out).columns[3][0] = C03; \
    \
    (out).columns[0][1] = C10; \
    (out).columns[1][1] = C11; \
    (out).columns[2][1] = C12; \
    (out).columns[3][1] = C13; \
    \
    (out).columns[0][2] = C20; \
    (out).columns[1][2] = C21; \
    (out).columns[2][2] = C22; \
    (out).columns[3][2] = C23; \
    \
    (out).columns[0][3] = C30; \
    (out).columns[1][3] = C31; \
    (out).columns[2][3] = C32; \
    (out).columns[3][3] = C33; \
    \
    (out).columns[0] *= inv_det; \
    (out).columns[1] *= inv_det; \
    (out).columns[2] *= inv_det; \
    (out).columns[3] *= inv_det; \
} while (0)

static inline float4x4 inverse_float4x4(float4x4 A) {
    float4x4 result;
    SET_INVERSE_4x4(A, result);
    return result;
}

static inline double4x4 inverse_double4x4(double4x4 A) {
    double4x4 result;
    SET_INVERSE_4x4(A, result);
    return result;
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

static inline float2x2 INVERSE(float2x2 A) {return inverse_float2x2(A);}
static inline float3x3 INVERSE(float3x3 A) {return inverse_float3x3(A);}
static inline float4x4 INVERSE(float4x4 A) {return inverse_float4x4(A);}

static inline double2x2 INVERSE(double2x2 A) {return inverse_double2x2(A);}
static inline double3x3 INVERSE(double3x3 A) {return inverse_double3x3(A);}
static inline double4x4 INVERSE(double4x4 A) {return inverse_double4x4(A);}

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

#define INVERSE(A) _Generic((A), \
    float2x2: inverse_float2x2, \
    float3x3: inverse_float3x3, \
    float4x4: inverse_float4x4, \
    \
    double2x2: inverse_double2x2, \
    double3x3: inverse_double3x3, \
    double4x4: inverse_double4x4 \
)(A)

#endif
