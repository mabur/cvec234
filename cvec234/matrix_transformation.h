#pragma once

#include <math.h>

#include "matrix_core.h"

static inline
float4x4 rotate_around_x_float4x4(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    float4x4 R;
    R.columns[0][0] = 1; R.columns[1][0] = 0; R.columns[2][0] =  0; R.columns[3][0] = 0;
    R.columns[0][1] = 0; R.columns[1][1] = c; R.columns[2][1] = -s; R.columns[3][1] = 0;
    R.columns[0][2] = 0; R.columns[1][2] = s; R.columns[2][2] =  c; R.columns[3][2] = 0;
    R.columns[0][3] = 0; R.columns[1][3] = 0; R.columns[2][3] =  0; R.columns[3][3] = 1;
    return R;
}

static inline
double4x4 rotate_around_x_double4x4(double angle) {
    double c = cos(angle);
    double s = sin(angle);
    double4x4 R;
    R.columns[0][0] = 1; R.columns[1][0] = 0; R.columns[2][0] =  0; R.columns[3][0] = 0;
    R.columns[0][1] = 0; R.columns[1][1] = c; R.columns[2][1] = -s; R.columns[3][1] = 0;
    R.columns[0][2] = 0; R.columns[1][2] = s; R.columns[2][2] =  c; R.columns[3][2] = 0;
    R.columns[0][3] = 0; R.columns[1][3] = 0; R.columns[2][3] =  0; R.columns[3][3] = 1;
    return R;
}

static inline
float4x4 rotate_around_y_float4x4(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    float4x4 R;
    R.columns[0][0] =  c; R.columns[1][0] = 0; R.columns[2][0] = s; R.columns[3][0] = 0;
    R.columns[0][1] =  0; R.columns[1][1] = 1; R.columns[2][1] = 0; R.columns[3][1] = 0;
    R.columns[0][2] = -s; R.columns[1][2] = 0; R.columns[2][2] = c; R.columns[3][2] = 0;
    R.columns[0][3] =  0; R.columns[1][3] = 0; R.columns[2][3] = 0; R.columns[3][3] = 1;
    return R;
}

static inline
double4x4 rotate_around_y_double4x4(double angle) {
    double c = cos(angle);
    double s = sin(angle);
    double4x4 R;
    R.columns[0][0] =  c; R.columns[1][0] = 0; R.columns[2][0] = s; R.columns[3][0] = 0;
    R.columns[0][1] =  0; R.columns[1][1] = 1; R.columns[2][1] = 0; R.columns[3][1] = 0;
    R.columns[0][2] = -s; R.columns[1][2] = 0; R.columns[2][2] = c; R.columns[3][2] = 0;
    R.columns[0][3] =  0; R.columns[1][3] = 0; R.columns[2][3] = 0; R.columns[3][3] = 1;
    return R;
}

float4x4 rotate_around_z_float4x4(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    float4x4 R;
    R.columns[0][0] = c; R.columns[1][0] = -s; R.columns[2][0] = 0; R.columns[3][0] = 0;
    R.columns[0][1] = s; R.columns[1][1] =  c; R.columns[2][1] = 0; R.columns[3][1] = 0;
    R.columns[0][2] = 0; R.columns[1][2] =  0; R.columns[2][2] = 1; R.columns[3][2] = 0;
    R.columns[0][3] = 0; R.columns[1][3] =  0; R.columns[2][3] = 0; R.columns[3][3] = 1;
    return R;
}

double4x4 rotate_around_z_double4x4(double angle) {
    double c = cos(angle);
    double s = sin(angle);
    double4x4 R;
    R.columns[0][0] = c; R.columns[1][0] = -s; R.columns[2][0] = 0; R.columns[3][0] = 0;
    R.columns[0][1] = s; R.columns[1][1] =  c; R.columns[2][1] = 0; R.columns[3][1] = 0;
    R.columns[0][2] = 0; R.columns[1][2] =  0; R.columns[2][2] = 1; R.columns[3][2] = 0;
    R.columns[0][3] = 0; R.columns[1][3] =  0; R.columns[2][3] = 0; R.columns[3][3] = 1;
    return R;
}

static inline
float4x4 translate_float4x4(float x, float y, float z) {
    float4x4 T;
    T.columns[0][0] = 1; T.columns[1][0] = 0; T.columns[2][0] = 0; T.columns[3][0] = x;
    T.columns[0][1] = 0; T.columns[1][1] = 1; T.columns[2][1] = 0; T.columns[3][1] = y;
    T.columns[0][2] = 0; T.columns[1][2] = 0; T.columns[2][2] = 1; T.columns[3][2] = z;
    T.columns[0][3] = 0; T.columns[1][3] = 0; T.columns[2][3] = 0; T.columns[3][3] = 1;
    return T;
}

static inline
double4x4 translate_double4x4(double x, double y, double z) {
    double4x4 T;
    T.columns[0][0] = 1; T.columns[1][0] = 0; T.columns[2][0] = 0; T.columns[3][0] = x;
    T.columns[0][1] = 0; T.columns[1][1] = 1; T.columns[2][1] = 0; T.columns[3][1] = y;
    T.columns[0][2] = 0; T.columns[1][2] = 0; T.columns[2][2] = 1; T.columns[3][2] = z;
    T.columns[0][3] = 0; T.columns[1][3] = 0; T.columns[2][3] = 0; T.columns[3][3] = 1;
    return T;
}

////////////////////////////////////////////////////////////////////////////////
// DEFINE OVERLOADED/GENERIC FUNCTIONS

#ifdef __cplusplus

float4x4 rotate_around_x_4(float angle) {return rotate_around_x_float4x4(angle);}
float4x4 rotate_around_y_4(float angle) {return rotate_around_y_float4x4(angle);}
float4x4 rotate_around_z_4(float angle) {return rotate_around_z_float4x4(angle);}
float4x4 translate_4(float x, float y, float z) {return translate_float4x4(x, y, z);}

double4x4 rotate_around_x_4(double angle) {return rotate_around_x_double4x4(angle);}
double4x4 rotate_around_y_4(double angle) {return rotate_around_y_double4x4(angle);}
double4x4 rotate_around_z_4(double angle) {return rotate_around_z_double4x4(angle);}
double4x4 translate_4(double x, double y, double z) {return translate_double4x4(x, y, z);}

#else

#define rotate_around_x_4(angle) _Generic((angle),float:rotate_around_x_float4x4,double:rotate_around_x_double4x4)(angle)
#define rotate_around_y_4(angle) _Generic((angle),float:rotate_around_y_float4x4,double:rotate_around_y_double4x4)(angle)
#define rotate_around_z_4(angle) _Generic((angle),float:rotate_around_z_float4x4,double:rotate_around_z_double4x4)(angle)
#define translate_4(x,y,z)       _Generic((x),    float:translate_float4x4,      double:translate_double4x4      )(x,y,z)

#endif
