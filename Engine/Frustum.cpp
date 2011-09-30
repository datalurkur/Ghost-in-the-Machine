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
    return Matrix4::MakeOrtho(-_aspectRatio, _aspectRatio, -1, 1, -10, 10);
}
