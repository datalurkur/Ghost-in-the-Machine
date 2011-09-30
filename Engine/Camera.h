#ifndef CAMERA_H
#define CAMERA_H

#include <Engine/Frustum.h>
#include <Engine/SceneNode.h>

class Camera: public Frustum, public SceneNode {
public:
    Camera(const std::string &name);

private:
};

#endif
