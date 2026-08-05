## Introduction

Cvec234 is a lightweight C library that provides small vectors and matrices in 2, 3, 4 dimensions for:
* Game programming
* Computer graphics
* Computer vision

Vectors and matrices are then used for things like:
* Color components
* Points and directions, using Cartesian or Homogeneous coordinates
* Velocities and accelerations
* Transformations

Cvec234 works with these languages and compilers:
* C or C++ using GCC or Clang. It uses compiler extensions for arithmetic operators and SIMD.
* C++ using MSVC. In this case it uses C++ for arithmetic operators, but does not support SIMD.


## Examples

```clike
#include <cvec234/cvec234.h>

///////////////////////////////////////////////////////////////////////////////
// COLORS

float3 interpolateColors(float3 rgb1, float3 rgb2, float t) {
    return (1 - t) * rgb1 + t * rgb2;
}

///////////////////////////////////////////////////////////////////////////////
// 2D PARTICLES

typedef struct MovingPoint {
    double2 position;
    double2 velocity;
} MovingPoint;

MovingPoint updateMovingPoint(MovingPoint p) {
    p.position = p.position + p.velocity;
    return p;
}

///////////////////////////////////////////////////////////////////////////////
// FIRST PERSON CAMERA PROJECTION USING HOMOGENEOUS COORDINATES

typedef struct CameraExtrinsics {
    float x;
    float y;
    float z;
    float yaw;
    float pitch;
} CameraExtrinsics;

typedef struct CameraIntrinsics {
    int width;
    int height;
    float field_of_view_degrees;
} CameraIntrinsics;

float4x4 imageFromCamera(CameraIntrinsics c) {
    float f = height / (2.f * tanf(field_of_view_degrees * M_PI / 180.f / 2.f));
    float cx = 0.5f * width;
    float cy = 0.5f * height;
    float4x4 image_from_camera = {};
    image_from_camera.columns[0][0] = f;
    image_from_camera.columns[1][1] = f;
    image_from_camera.columns[2][0] = cx;
    image_from_camera.columns[2][1] = cy;
    image_from_camera.columns[3][2] = 1;
    image_from_camera.columns[2][3] = 1;
    return image_from_camera;
}

float4x4 worldFromCamera(CameraExtrinsics coordinates) {
    float4x4 R_flip = rotate_around_x_4(M_PI);
    float4x4 R_yaw = rotate_around_y_4(coordinates.yaw);
    float4x4 R_pitch = rotate_around_x_4(coordinates.pitch);
    float4x4 translation = translate_4(coordinates.x, coordinates.y, coordinates.z);
    return MUL(MUL(MUL(translation, R_flip), R_yaw), R_pitch);
}

float4x4 cameraFromWorld(CameraExtrinsics coordinates) {
    return INVERSE(worldFromCamera(coordinates));
}

float4x4 imageFromWorld(CameraIntrinsics intrinsics, CameraExtrinsics extrinsics) {
    return MUL(imageFromCamera(intrinsics), cameraFromWorld(extrinsics));
}
```
