#pragma once

#include "vector.h"
#include "matrix_core.h"
#include "matrix_inverse.h"
#include "matrix_multiplication.h"

#if defined(__GNUC__) || defined(__clang__)
    #define TYPE_OF_EXPRESSION(x) __typeof__(x)
#elif defined(__cplusplus)
    #define TYPE_OF_EXPRESSION(x) decltype(x)
#endif

#define T_float2 TYPE_OF_EXPRESSION((float2){})
#define T_float3 TYPE_OF_EXPRESSION((float3){})
#define T_float4 TYPE_OF_EXPRESSION((float4){})

#define T_double2 TYPE_OF_EXPRESSION((double2){})
#define T_double3 TYPE_OF_EXPRESSION((double3){})
#define T_double4 TYPE_OF_EXPRESSION((double4){})

#define T_float2x2 TYPE_OF_EXPRESSION((float2x2){})
#define T_float3x3 TYPE_OF_EXPRESSION((float3x3){})
#define T_float4x4 TYPE_OF_EXPRESSION((float4x4){})

#define T_double2x2 TYPE_OF_EXPRESSION((double2x2){})
#define T_double3x3 TYPE_OF_EXPRESSION((double3x3){})
#define T_double4x4 TYPE_OF_EXPRESSION((double4x4){})

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
