#pragma once

#include <math.h>

#if defined(__clang__) || defined(__GNUC__)
    #include "vector_implementation_extensions.h"
#elif defined(__cplusplus)
    #include "vector_implementation_cpp.hpp"
#else
    #error "The vector types require either clang or gcc or C++"
#endif

#define DOT2(a, b) ((a)[0] * (b)[0] + (a)[1] * (b)[1])
#define DOT3(a, b) ((a)[0] * (b)[0] + (a)[1] * (b)[1] + (a)[2] * (b)[2])
#define DOT4(a, b) ((a)[0] * (b)[0] + (a)[1] * (b)[1] + (a)[2] * (b)[2] + (a)[3] * (b)[3])

#define SQUARED_NORM2(a) DOT2((a), (a))
#define SQUARED_NORM3(a) DOT3((a), (a))

#define NORM2(a) (sqrt(SQUARED_NORM2(a)))
#define NORM3(a) (sqrt(SQUARED_NORM3(a)))

#define NORMALIZED2(a) (a / NORM2(a))
#define NORMALIZED3(a) (a / NORM3(a))

#define SQUARED_DISTANCE2(a, b) SQUARED_NORM2((a) - (b))
#define SQUARED_DISTANCE3(a, b) SQUARED_NORM3((a) - (b))

#define DISTANCE2(a, b) NORM2((a) - (b))
#define DISTANCE3(a, b) NORM3((a) - (b))

#define ARE_EQUAL_VECTOR2(a,b) ((a)[0]==(b)[0]&&(a)[1]==(b)[1])
#define ARE_EQUAL_VECTOR3(a,b) ((a)[0]==(b)[0]&&(a)[1]==(b)[1]&&(a)[2]==(b)[2])
#define ARE_EQUAL_VECTOR4(a,b) ((a)[0]==(b)[0]&&(a)[1]==(b)[1]&&(a)[2]==(b)[2]&&(a)[3]==(b)[3])
