#ifndef VECTOR_H
#define VECTOR_H

#include <Base/Base.h>
#include <Base/Log.h>

#define VectorData (*static_cast<T*>(this))
#define ConstVectorData (*static_cast<const T*>(this))

// The template from which all Vector classes are constructed
template <typename T, int N>
class VectorBase {
public:
	float _data[N];

	VectorBase();
	VectorBase(const T &other);

	T operator+(const T &rhs) const;
	T operator-(const T &rhs) const;

	T& operator+=(const T &rhs);
	T& operator-=(const T &rhs);

	float& operator[](int index);
	const float& operator[](int index) const;
};

template <typename T, int N>
VectorBase<T,N>::VectorBase() {
};

template <typename T, int N>
VectorBase<T,N>::VectorBase(const T &other) {
	memcpy(VectorData, other, sizeof(float) * N);
}

template <typename T, int N>
T VectorBase<T,N>::operator+(const T &rhs) const {
	T ret(ConstVectorData);
	ret += rhs;
	return ret;
}

template <typename T, int N>
T VectorBase<T,N>::operator-(const T &rhs) const {
	T ret(ConstVectorData);
	ret -= rhs;
	return ret;
}

template <typename T, int N>
T& VectorBase<T,N>::operator+=(const T &rhs) {
	for(int i=0; i<N; i++) {
		VectorData[i] += rhs[i];
	}
	return VectorData;
}

template <typename T, int N>
T& VectorBase<T,N>::operator-=(const T &rhs) {
	for(int i=0; i<N; i++) {
		VectorData[i] -= rhs[i];
	}
	return VectorData;
}

template <typename T, int N>
float& VectorBase<T,N>::operator[](int index) {
	return _data[index];
}

template <typename T, int N>
const float& VectorBase<T,N>::operator[](int index) const {
	return _data[index];
}

// Basic vector class (convenience, so we don't have to write out the VectorBase inheritance every time)
template <int N>
class Vector: public VectorBase<Vector<N>, N> {};

// Vector class specifications
template <>
class Vector<2>: public VectorBase<Vector<2>, 2> {
public:
	Vector(float x, float y);
};

typedef Vector<2> Vector2;

#undef VectorData
#undef ConstVectorData

#endif
