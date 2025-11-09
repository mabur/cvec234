#pragma once

typedef unsigned char byte2 __attribute__((vector_size(2)));
typedef unsigned char byte3 __attribute__((vector_size(4)));  // Including padding
typedef unsigned char byte4 __attribute__((vector_size(4)));
typedef unsigned char byte5 __attribute__((vector_size(8)));  // Including padding
typedef unsigned char byte6 __attribute__((vector_size(8)));  // Including padding
typedef unsigned char byte7 __attribute__((vector_size(8)));  // Including padding
typedef unsigned char byte8 __attribute__((vector_size(8)));

typedef int int2 __attribute__((vector_size(8)));
typedef int int3 __attribute__((vector_size(16)));  // Including padding
typedef int int4 __attribute__((vector_size(16)));
typedef int int5 __attribute__((vector_size(32)));  // Including padding
typedef int int6 __attribute__((vector_size(32)));  // Including padding
typedef int int7 __attribute__((vector_size(32)));  // Including padding
typedef int int8 __attribute__((vector_size(32)));

typedef float float2 __attribute__((vector_size(8)));
typedef float float3 __attribute__((vector_size(16)));  // Including padding
typedef float float4 __attribute__((vector_size(16)));
typedef float float5 __attribute__((vector_size(32)));  // Including padding
typedef float float6 __attribute__((vector_size(32)));  // Including padding
typedef float float7 __attribute__((vector_size(32)));  // Including padding
typedef float float8 __attribute__((vector_size(32)));

typedef double double2 __attribute__((vector_size(16)));
typedef double double3 __attribute__((vector_size(32)));  // Including padding
typedef double double4 __attribute__((vector_size(32)));
typedef double double5 __attribute__((vector_size(64)));  // Including padding
typedef double double6 __attribute__((vector_size(64)));  // Including padding
typedef double double7 __attribute__((vector_size(64)));  // Including padding
typedef double double8 __attribute__((vector_size(64)));
