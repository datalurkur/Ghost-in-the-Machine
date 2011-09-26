#ifndef SCENENODE_H
#define SCENENODE_H

#include <Base/Vector.h>

class SceneNode {
public:
	SceneNode();
	virtual ~SceneNode();

private:
	Vector2 _position;
};

#endif