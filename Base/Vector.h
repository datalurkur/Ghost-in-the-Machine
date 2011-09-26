#ifndef VECTOR_H
#define VECTOR_H

#include <Base/Base.h>

template <typename type, int size>
class Vector {
public:
	Vector();
	Vector(const type *other);
	virtual ~Vector();

	Vector& operator+(const Vector &other);
	Vector& operator-(const Vector &other);

protected:
	inline void allocate();

protected:
	type *_data;
};

class Vector2: public Vector<float, 2> {
public:
	Vector2(const float x, const float y);
};

#endif