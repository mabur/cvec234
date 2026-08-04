## Matrices

Cvec234 defines the following square matrices in 2, 3, 4 dimensions:
* `float2x2`, `float3x3`, `float4x4` matrices with `float` elements.
* `double2x2`, `double3x3`, `double4x4` matrices with `double` elements.


## Elementwise Operations

Matrices can be added, subtracted, multiplied and divided elementwise using the arithmetic operators, in just the same way as vectors:
```clike
double2x2 A = ...;
double2x2 B = ...;
double2x2 C = A + B; 
double2x2 D = A - B;
double2x2 E = A * B;
double2x2 F = A / B;
double2x2 G = -A;
double2x2 H = 0.5 * A;
double2x2 I = A / 2.0;
```


## Matrix Operations

* `MUL(A, B)` multiplies two square matrices of the same type. This is NOT elementwise multiplication.

* `INVERSE(A)` calculates the inverse of a square matrix.

* `ARE_EQUAL_MATRIX2`, `ARE_EQUAL_MATRIX3`, `ARE_EQUAL_MATRIX4`.


## Matrix Construction

You can construct a matrix by expliciting setting each of its elements:
```clike
double2x2 A;
A.columns[0][0] = 1; A.columns[1][0] = 2;
A.columns[0][1] = 3; A.columns[1][1] = 4;
```

You can also construct a matrix by using the following functions, either individually or by multiplying them together:

* `rotate_around_x_4(angle)` constructs a 4x4 homogeneous matrix that represents a rotation around the x-axis in 3D. The input `angle` can be either `float` or `double` and the resulting matrix will have the same element type.

* `rotate_around_y_4(angle)` constructs a 4x4 homogeneous matrix that represents a rotation around the y-axis in 3D. The input `angle` can be either `float` or `double` and the resulting matrix will have the same element type.

* `rotate_around_z_4(angle)` constructs a 4x4 homogeneous matrix that represents a rotation around the z-axis in 3D. The input `angle` can be either `float` or `double` and the resulting matrix will have the same element type.

* `translate_4(x, y, z)` constructs a 4x4 homogeneous matrix that represents a translation in 3D. The input coordinates can all be either `float` or `double` and the resulting matrix will have the same element type.
