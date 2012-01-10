#include <Engine/IsoCamera.h>

IsoCamera::IsoCamera(const std::string &name): Camera(name), _fov(STANDARD_FOV), _near(10.0f), _far(-10.0f) {
	// DEBUG
	Matrix4 mView = Matrix4::Identity;
	mView.translate(-8.0f,-8.0f,-3.0f);
	setModelView(mView);
	glEnable(GL_DEPTH_TEST);
}

IsoCamera::~IsoCamera() {
}

void IsoCamera::setAspectRatio(const float ratio) {
	setProjection(Matrix4::MakePerspective(ratio, _fov, _near, _far));
}