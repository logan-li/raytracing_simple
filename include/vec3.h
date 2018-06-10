#pragma once

#include <cmath>

class vec3
{
public:
    union
    {
        float v[3];
        struct {float x, y, z;};
        struct {float r, g, b;};
    };

    static const vec3 zero;
    static const vec3 one;

    vec3() {}
    vec3(float x, float y, float z): x(x), y(y), z(z) {}

    inline const vec3& operator+() const;
    inline vec3 operator-() const;

    inline vec3& operator+=(vec3 v);
    inline vec3& operator-=(vec3 v);
    inline vec3& operator*=(vec3 v);
    inline vec3& operator/=(vec3 v);
    inline vec3& operator*=(float t);
    inline vec3& operator/=(float t);

    inline float len() const;
    inline float sqr_len() const;
    inline vec3& normalize();
    inline vec3 unit() const;
};

inline vec3 operator+(vec3 a, vec3 b);
inline vec3 operator-(vec3 a, vec3 b);
inline vec3 operator*(vec3 a, vec3 b);
inline vec3 operator/(vec3 a, vec3 b);
inline vec3 operator*(vec3 v, float t);
inline vec3 operator*(float t, vec3 v);
inline vec3 operator/(vec3 v, float t);

inline float dot(vec3 a, vec3 b);
inline vec3 cross(vec3 a, vec3 b);


// implemention

const vec3& vec3::operator+() const
{
    return *this;
}

vec3 vec3::operator-() const
{
    return vec3(-x, -y, -z);
}

vec3& vec3::operator+=(vec3 v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

vec3& vec3::operator-=(vec3 v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

vec3& vec3::operator*=(vec3 v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

vec3& vec3::operator/=(vec3 v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

vec3& vec3::operator*=(float t)
{
    x *= t;
    y *= t;
    z *= t;
    return *this;
}

vec3& vec3::operator/=(float t)
{
    t = 1.0f / t;
    x *= t;
    y *= t;
    z *= t;
    return *this;
}


float vec3::len() const
{
    return sqrtf(sqr_len());
}

float vec3::sqr_len() const
{
    return dot(*this, *this);
}

vec3& vec3::normalize()
{
    *this /= len();
    return *this;
}

vec3 vec3::unit() const
{
    return *this / len();
}

vec3 operator+(vec3 a, vec3 b)
{
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

vec3 operator-(vec3 a, vec3 b)
{
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

vec3 operator*(vec3 a, vec3 b)
{
    return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}

vec3 operator/(vec3 a, vec3 b)
{
    return vec3(a.x / b.x, a.y / b.y, a.z / b.z);
}

vec3 operator*(vec3 v, float t)
{
    return vec3(v.x * t, v.y * t, v.z * t);
}

vec3 operator*(float t, vec3 v)
{
    return v * t;
}

vec3 operator/(vec3 v, float t)
{
    return v * (1.0f / t);
}

float dot(vec3 a, vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 cross(vec3 a, vec3 b)
{
    return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
