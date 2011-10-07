#include <Physics/AABB.h>

AABB::AABB():
_lower(0.0, 0.0), _upper(0.0, 0.0)
{}

AABB::AABB(const Vector2& v1, const Vector2& v2) {
    setExtents(v1, v2);
}

AABB::~AABB() {}

void AABB::setExtents(const Vector2& v1, const Vector2& v2) {
    _lower=Vector2(std::min(v1.x, v2.x), std::min(v1.y, v2.y));
    _upper=Vector2(std::max(v1.x, v2.x), std::max(v1.y, v2.y));
}

const Vector2& AABB::getLowerBound() {
    return _lower;
}

const Vector2& AABB::getUpperBound() {
    return _upper;
}

const Vector2& AABB::getCenter() const {
    return (_lower + _upper) * 0.5;
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
    _lower = Vector2(std::min(_lower.x, other._lower.x), std::min(_lower.y, other._lower.y));
    _upper = Vector2(std::max(_upper.x, other._upper.x), std::max(_upper.y, other._upper.y));
}
