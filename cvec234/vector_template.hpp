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

typedef VecTemp<int, 2> int2;
typedef VecTemp<int, 3> int3;
typedef VecTemp<int, 4> int4;

typedef VecTemp<float, 2> float2;
typedef VecTemp<float, 3> float3;
typedef VecTemp<float, 4> float4;

typedef VecTemp<double, 2> double2;
typedef VecTemp<double, 3> double3;
typedef VecTemp<double, 4> double4;
