#ifndef AABB_H
#define AABB_H

#include <Base/Vector2.h>

class AABB {
public:
    AABB();
    AABB(const Vector2 &v1, const Vector2 &v2);
    ~AABB();

    void setExtents(const Vector2 &v1, const Vector2 &v2);
    const Vector2& getLowerBound();
    const Vector2& getUpperBound();

    const Vector2& getCenter() const;

    bool contains(const AABB& other) const;
    bool overlaps(const AABB& other) const;

    void expand(const AABB& other);

protected:
    Vector2 _lower, _upper;
};

#endif
