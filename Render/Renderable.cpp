#include <Render/Renderable.h>

Renderable::Renderable(): _viewMatrix(Matrix4::Identity) {
}

Renderable::~Renderable() {
}

void Renderable::setViewMatrix(const Matrix4 &matrix) {
	_viewMatrix = matrix;
}

const Matrix4& Renderable::getViewMatrix() const {
	return _viewMatrix;
}