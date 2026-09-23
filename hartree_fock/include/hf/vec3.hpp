#pragma once //include just once in a .cpp file
#include <cmath> 

namespace hf {

struct Vec3 {
    double x{}, y{}, z{};
};

// constexpr: can be evaluated at compile time; may be defined in the header
// const Vec3&: pass by reference (no copy), const = original is not modified
constexpr Vec3 operator+(const Vec3& a, const Vec3& b) 
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

constexpr Vec3 operator-(const Vec3& a, const Vec3& b)
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

constexpr Vec3 operator*(double s, const Vec3& v)
{
    return {s * v.x, s * v.y, s * v.z};
}

constexpr double dot(const Vec3& a, const Vec3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

constexpr double norm2(const Vec3& v)
{
    return dot(v, v);
}

inline double norm(const Vec3& v)
{
    return std::sqrt(norm2(v));
}

}