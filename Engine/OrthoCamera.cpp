#include <Engine/OrthoCamera.h>

OrthoCamera::OrthoCamera(const std::string &name): Camera(name), _zoom(1.0), _near(-10.0), _far(10.0) {}

void OrthoCamera::setAspectRatio(const float ratio) {
	setProjection(Matrix4::MakeOrtho(-(ratio/_zoom), (ratio/_zoom), -_zoom, _zoom, _near, _far));
}