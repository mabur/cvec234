## Vectors

Cvec234 defines these vectors in 2, 3, 4 dimensions:

* `byte2`, `byte3`, `byte4` for vectors of `unsigned char`.
* `int2`, `int3`, `int4` for vectors of `int`.
* `float2`, `float3`, `float4` for vectors of `float`.
* `double2`, `double3`, `double4` for vectors of `double`.

They are constructed and accessed like this:
```clike
double2 v = {1.0, 2.0};
v[0] = 3.14;
v[1] *= -1.0;
v[0] += v[1];
```

## Elementwise Operations

Vectors can be added, subtracted, multiplied and divided elementwise using the arithmetic operators:
```clike
double2 a = {1.0, 2.0};
double2 b = {1.0, 2.0};
double2 c = a + b; 
double2 d = a - b;
double2 e = a * b;
double2 f = a / b;
double2 g = -a;
double2 h = 0.5 * a;
double2 i = a / 2.0;
```

## Vector Operations

* `ARE_EQUAL_VECTOR2`, `ARE_EQUAL_VECTOR3`, `ARE_EQUAL_VECTOR4` checks if the elements of two vectors are equal:
```clike
int3 a = {1, 2, 3};
int3 b = {4, 5, 6};
int3 c = {4, 5, 6};
int3 d = {4, 5, 10};
bool e = ARE_EQUAL_VECTOR3(a, b); // Gives false
bool f = ARE_EQUAL_VECTOR3(b, c); // Gives true
bool g = ARE_EQUAL_VECTOR2(b, d); // Checks the first two dimensions, giving true.
```

* `DOT2`, `DOT3`, `DOT4` calculates the dot product of two vectors like:
```clike
double3 a = {2.0, 3.0, 1.0};
double3 b = {1.0, -1.0, 1.0};
double c = DOT3(a, b); // Dot product in three dimensions
double d = DOT2(a, b); // Dot product in the first two dimensions
```

* `NORM2`, `NORM3` calculates the Euclidean norm of a vector like:
```clike
double3 a = {3.0, 4.0, 12.0};
double b = NORM3(a); // Norm in 3D, giving 13.0
double c = NORM2(a); // Norm in the first two dimensions, giving 5.0
```

* `SQUARED_NORM2`, `SQUARED_NORM3` calculates the squared Euclidean norm of a vector.

* `NORMALIZED2`, `NORMALIZED3` calculates a vector with the same dimension but with a norm of 1 like:
```clike
double2 a = {0.0, 10.0};
double2 b = NORMALIZED2(a); // Gives {0, 1}
```

* `DISTANCE2`, `DISTANCE3` calculates the Euclidean distance between two vectors like:
```clike
double2 a = {9.0, 6.0};
double2 b = {6.0, 2.0};
double c = DISTANCE2(a, b); // Gives 5.0
```

* `SQUARED_DISTANCE2`, `SQUARED_DISTANCE3` calculates the squared Euclidean distance between two vectors.
