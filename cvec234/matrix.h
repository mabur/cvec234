#pragma once

#include "vector.h"
#include "matrix_core.h"
#include "matrix_inverse.h"
#include "matrix_multiplication.h"

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
