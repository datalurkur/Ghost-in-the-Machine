#include <Engine/Frustum.h>
#include <Base/Matrix4.h>

Frustum::Frustum(): _dirty(true), _projection(Matrix4::Identity) {
}

void Frustum::setProjection(const Matrix4 &matrix) {
	_projection = matrix;
}

const Matrix4 Frustum::getProjection() const {
    return _projection;
}

Frustum& Frustum::operator=(const Frustum &other) {
	_projection = other.getProjection();
	return *this;
}

std::ostream& operator<<(std::ostream &lhs, const Frustum &rhs) {
	lhs << "Frustum";
	lhs << " Projection: " << rhs.getProjection();
	return lhs;
}