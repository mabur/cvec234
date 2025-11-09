#pragma once

template<typename T, size_t D>
struct VecTemp {
    T data[D];
    // Indexing:
    T& operator[](size_t i) { return data[i]; }
    const T& operator[](size_t i) const { return data[i]; }
    // Elementwise vector assignment operators
    VecTemp& operator+=(const VecTemp& b) {
        for (size_t i = 0; i < D; ++i) data[i] += b[i];
        return *this;
    }
    VecTemp& operator-=(const VecTemp& b) {
        for (size_t i = 0; i < D; ++i) data[i] -= b[i];
        return *this;
    }
    VecTemp& operator*=(const VecTemp& b) {
        for (size_t i = 0; i < D; ++i) data[i] *= b[i];
        return *this;
    }
    VecTemp& operator/=(const VecTemp& b) {
        for (size_t i = 0; i < D; ++i) data[i] /= b[i];
        return *this;
    }
    VecTemp& operator*=(T scalar) {
        for (size_t i = 0; i < D; ++i) data[i] *= scalar;
        return *this;
    }
    VecTemp& operator/=(T scalar) {
        for (size_t i = 0; i < D; ++i) data[i] /= scalar;
        return *this;
    }
    // Vector-vector arithmetics
    friend VecTemp operator+(VecTemp a, const VecTemp& b) {return a += b;}
    friend VecTemp operator-(VecTemp a, const VecTemp& b) {return a -= b;}
    friend VecTemp operator*(VecTemp a, const VecTemp& b) {return a *= b;}
    friend VecTemp operator/(VecTemp a, const VecTemp& b) {return a /= b;}
    // Vector-scalar arithmetics
    friend VecTemp operator*(VecTemp a, T scalar) {return a *= scalar;}
    friend VecTemp operator*(T scalar, VecTemp b) {return b *= scalar;}
    friend VecTemp operator/(VecTemp a, T scalar) {return a /= scalar;}
    // Unary minus
    friend VecTemp operator-(const VecTemp& v) {return VecTemp{} -= v;}
};

typedef VecTemp<unsigned char, 2> byte2;
typedef VecTemp<unsigned char, 3> byte3;
typedef VecTemp<unsigned char, 4> byte4;
typedef VecTemp<unsigned char, 5> byte5;
typedef VecTemp<unsigned char, 6> byte6;
typedef VecTemp<unsigned char, 7> byte7;
typedef VecTemp<unsigned char, 8> byte8;

typedef VecTemp<int, 2> int2;
typedef VecTemp<int, 3> int3;
typedef VecTemp<int, 4> int4;
typedef VecTemp<int, 5> int5;
typedef VecTemp<int, 6> int6;
typedef VecTemp<int, 7> int7;
typedef VecTemp<int, 8> int8;

typedef VecTemp<float, 2> float2;
typedef VecTemp<float, 3> float3;
typedef VecTemp<float, 4> float4;
typedef VecTemp<float, 5> float5;
typedef VecTemp<float, 6> float6;
typedef VecTemp<float, 7> float7;
typedef VecTemp<float, 8> float8;

typedef VecTemp<double, 2> double2;
typedef VecTemp<double, 3> double3;
typedef VecTemp<double, 4> double4;
typedef VecTemp<double, 5> double5;
typedef VecTemp<double, 6> double6;
typedef VecTemp<double, 7> double7;
typedef VecTemp<double, 8> double8;
