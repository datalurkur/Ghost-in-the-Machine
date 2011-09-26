#include <Base/Vector.h>

template <typename type, int size>
Vector<type,size>::Vector() {
	allocate();
}

template <typename type, int size>
Vector<type,size>::Vector(const type *other) {
	allocate();
	memcpy(_data, other, sizeof(type) * size);
}

template <typename type, int size>
Vector<type,size>::~Vector() {
	free(_data);
}

template <typename type, int size>
inline void Vector<type,size>::allocate() {
	_data = (type*)calloc(sizeof(type), size);
}

template <typename type, int size>
Vector<type,size>& Vector<type,size>::operator+(const Vector &rhs) {
	for(int i = 0; i < size; i++) {
		_data[i] += rhs[i];
	}
}

template <typename type, int size>
Vector<type,size>& Vector<type,size>::operator-(const Vector &rhs) {
	for(int i = 0; i < size; i++) {
		_data[i] -= rhs[i];
	}
}

Vector2::Vector2(const float x, const float y) {
	allocate();
	_data[0] = x;
	_data[1] = y;
}
