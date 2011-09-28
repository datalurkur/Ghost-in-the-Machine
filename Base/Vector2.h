#ifndef VECTOR2_H
#define VECTOR2_H

#include <Base/Base.h>
#include <Base/Log.h>

class Vector2 {
public:
    union {
        float data[2];
        struct { float x, y; };
    };

public:
    Vector2();
    Vector2(const Vector2 &other);
    Vector2(float nX, float nY);

    Vector2 operator+(const Vector2 &rhs) const;
    Vector2 operator-(const Vector2 &rhs) const;

    Vector2& operator+=(const Vector2 &rhs);
    Vector2& operator-=(const Vector2 &rhs);

    float operator[](int i);
    const float operator[](int i) const;

private:
};

#endif
