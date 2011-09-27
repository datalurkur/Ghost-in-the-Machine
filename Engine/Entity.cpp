#include <Engine/Entity.h>

const std::string Entity::NodeType = "Entity";

Entity::Entity(const std::string &name): SceneNode(name) {
}

Entity::~Entity() {
}
