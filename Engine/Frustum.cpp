#include <Engine/Frustum.h>
#include <Base/Matrix4.h>

Frustum::Frustum() {
}

void Frustum::setAspectRatio(const float ratio) {
    _aspectRatio = ratio;
}

const float Frustum::getAspectRatio() const {
    return _aspectRatio;
}

const Matrix4 Frustum::getProjectionMatrix() const {
    // FIXME - Frustum obviously needs to get beefed up with planes
    //  Realistically, the frustum is just a vehicle for computing the projection matrix,
    //   the camera is the object that needs to make the sorts of decisions about what type
    //   frustum it's using, which will consequently change the projection matrix returned by it
    return Matrix4::MakeOrtho(-2*_aspectRatio, 2*_aspectRatio, -2, 2, -10, 10);
}

std::ostream& operator<<(std::ostream &lhs, const Frustum &rhs) {
	lhs << "Frustum";
	lhs << " Aspect ratio: " << rhs.getAspectRatio();
	return lhs;
}