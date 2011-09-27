#ifndef ENTITY_H
#define ENTITY_H

#include <Engine/SceneNode.h>

class Entity: public SceneNode {
public:
    Entity(const std::string &name);
    ~Entity();

private:
};

#endif
