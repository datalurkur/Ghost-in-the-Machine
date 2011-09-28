#include <Base/Vector2.h>

Vector2::Vector2(): x(0), y(0) {}
Vector2::Vector2(const Vector2 &other): x(other.x), y(other.y) {}
Vector2::Vector2(float nX, float nY): x(nX), y(nY) {}

Vector2 Vector2::operator+(const Vector2 &rhs) const {
    Vector2 ret(*this);
    ret += rhs;
    return ret;
}

Vector2 Vector2::operator-(const Vector2 &rhs) const {
    Vector2 ret(*this);
    ret -= rhs;
    return ret;
}

Vector2& Vector2::operator+=(const Vector2 &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

float Vector2::operator[](int i) {
    return data[i];
}

const float Vector2::operator[](int i) const {
    return data[i];
}
