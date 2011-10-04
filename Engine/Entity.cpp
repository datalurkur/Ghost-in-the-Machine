#include <Engine/Entity.h>

const std::string Entity::NodeType = "Entity";

Entity::Entity(const std::string &name):
	SceneNode(name, NodeType) 
{
	// FIXME - This doesn't belong here
	Renderable *renderable = Renderable::OrthoBox(_position[0], _position[1], 1.0, 1.0, 0.0, true, true);
	addRenderable(renderable);
}

Entity::Entity(const std::string &name, const std::string &type):
	SceneNode(name, type)
{
	// FIXME - This doesn't belong here
	Renderable *renderable = Renderable::OrthoBox(_position[0], _position[1], 1.0, 1.0, 0.0, true, true);
	addRenderable(renderable);
}

Entity::~Entity() {
}

void Entity::update(int elapsed) {
    // FIXME - This is where a list of controllers would be passed an elapsed time to use to update
}
