## Matrices

Cvec234 defines these square matrices in 2, 3, 4 dimensions:
* `float2x2`, `float3x3`, `float4x4` matrices with `float` elements.
* `double2x2`, `double3x3`, `double4x4` matrices with `double` elements.

You can access them with `#include <cvec234/matrix.h>`.


## Matrix Operations

* `MUL(A, B)` multiplies either two matrices, or a matrix and a vector. This is NOT elementwise multiplication.

* `INVERSE(A)` calculates the inverse of a matrix.

* `ARE_EQUAL_MATRIX2`, `ARE_EQUAL_MATRIX3`, `ARE_EQUAL_MATRIX4`.


## Matrix Construction

You can construct a matrix by expliciting setting each of its elements:
```clike
#include <cvec234/matrix.h>

double2x2 A;
A.columns[0][0] = 1; A.columns[1][0] = 2;
A.columns[0][1] = 3; A.columns[1][1] = 4;
```

You can also construct a matrix by using the following functions, either individually or by multiplying them together:

* `rotate_around_x_4(angle)` constructs a 4x4 homogeneous matrix that represents a rotation around the x-axis in 3D. The input `angle` can be either `float` or `double` and the resulting matrix will have the same element type.

* `rotate_around_y_4(angle)` constructs a 4x4 homogeneous matrix that represents a rotation around the y-axis in 3D. The input `angle` can be either `float` or `double` and the resulting matrix will have the same element type.

* `rotate_around_z_4(angle)` constructs a 4x4 homogeneous matrix that represents a rotation around the z-axis in 3D. The input `angle` can be either `float` or `double` and the resulting matrix will have the same element type.

* `translate_4(x, y, z)` constructs a 4x4 homogeneous matrix that represents a translation in 3D. The input coordinates can all be either `float` or `double` and the resulting matrix will have the same element type.

```clike
#include <cvec234/matrix.h>

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
```
