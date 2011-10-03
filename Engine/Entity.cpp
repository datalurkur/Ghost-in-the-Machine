#include <Engine/Entity.h>

const std::string Entity::NodeType = "Entity";

Entity::Entity(const std::string &name):
    SceneNode(name, NodeType)
{
}

Entity::Entity(const std::string &name, const std::string &type):
    SceneNode(name, type)
{
}

Entity::~Entity() {
}

void Entity::update(int elapsed) {
    // FIXME - This is where a list of controllers would be passed an elapsed time to use to update
}