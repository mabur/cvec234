## Matrices

Cvec234 defines the following square matrices in 2,3,4 dimensions:
* `float2x2`, `float3x3`, `float4x4` matrices with `float` elements.
* `double2x2`, `double3x3`, `double4x4` matrices with `double` elements.

## Matrix Operations

* `ARE_EQUAL_MATRIX2`, `ARE_EQUAL_MATRIX3`, `ARE_EQUAL_MATRIX4`.

* `MUL(A, B)` multiplies two square matrices of the same type.

* `INVERSE(A)` calculates the inverse of a square matrix.


## Matrix Construction Functions

* `rotate_around_x_4(angle)` constructs a 4x4 homogeneous matrix that represents a rotation around the x-axis in 3D. The input `angle` can be either `float` or `double` and the resulting matrix will have the same element type.

* `rotate_around_y_4(angle)` constructs a 4x4 homogeneous matrix that represents a rotation around the y-axis in 3D. The input `angle` can be either `float` or `double` and the resulting matrix will have the same element type.

* `rotate_around_z_4(angle)` constructs a 4x4 homogeneous matrix that represents a rotation around the z-axis in 3D. The input `angle` can be either `float` or `double` and the resulting matrix will have the same element type.

* `translate_4(x, y, z)` constructs a 4x4 homogeneous matrix that represents a translation in 3D. The input coordinates can all be either `float` or `double` and the resulting matrix will have the same element type.
