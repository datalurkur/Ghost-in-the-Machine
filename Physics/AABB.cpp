#include <Physics/AABB.h>

AABB::AABB():
_lower(0.0, 0.0), _upper(0.0, 0.0)
{}

AABB::AABB(const Vector2& v1, const Vector2& v2) {
    setExtents(v1, v2);
}

AABB::~AABB() {}

void AABB::setExtents(const Vector2& v1, const Vector2& v2) {
    _lower=Vector2(min(v1.x, v2.x), min(v1.y, v2.y));
    _upper=Vector2(max(v1.x, v2.x), max(v1.y, v2.y));
}

const Vector2& AABB::getLowerBound() {
    return _lower;
}

const Vector2& AABB::getUpperBound() {
    return _upper;
}

Vector2 AABB::getCenter() const {
    return (_lower + _upper) * 0.5;
}

const float AABB::getPerimeter() const {
    return ((_upper.x - _lower.x) + (_upper.y - _lower.y)) * 2;
}

bool AABB::contains(const AABB& other) const {
    return (
        (_lower.x <= other._lower.x) &&
        (_lower.y <= other._lower.y) &&
        (_upper.x >= other._upper.x) &&
        (_upper.y >= other._upper.y)
    );
}

bool AABB::overlaps(const AABB& other) const {
    Vector2 lowerMargin, upperMargin;
    lowerMargin = _lower - other._upper;
    if(lowerMargin.x > 0.0 || lowerMargin.y > 0.0) { return false; }

    upperMargin = other._lower - _upper;
    if(upperMargin.x > 0.0 || upperMargin.y > 0.0) { return false; }

    return true;
}

void AABB::expand(const AABB& other) {
    _lower = Vector2(min(_lower.x, other._lower.x), min(_lower.y, other._lower.y));
    _upper = Vector2(max(_upper.x, other._upper.x), max(_upper.y, other._upper.y));
}

void AABB::expand(const Vector2& border) {
	_lower -= border;
	_upper += border;
}

AABB AABB::Combine(const AABB& b1, const AABB& b2) {
    AABB ret = b1;
    ret.expand(b2);
    return ret;
}
