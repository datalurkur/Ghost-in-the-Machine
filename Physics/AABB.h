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

    Vector2 getCenter() const;
    const float getPerimeter() const;

    bool contains(const AABB& other) const;
    bool overlaps(const AABB& other) const;

    void expand(const AABB& other);
	void expand(const Vector2& border);

	inline AABB operator+(const Vector2& rhs) {
		AABB ret(*this);
		ret.expand(rhs);
		return ret;
	}

    inline AABB& operator=(const AABB& rhs) {
        _lower = rhs._lower;
        _upper = rhs._upper;
        return *this;
    }
    
	inline bool operator==(const AABB& rhs) {
		return (_lower == rhs._lower && _upper == rhs._upper);
	}

public:
    static AABB Combine(const AABB& b1, const AABB& b2);

protected:
    Vector2 _lower, _upper;
};

#endif
