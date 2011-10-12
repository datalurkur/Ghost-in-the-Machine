#ifndef ENTITY_H
#define ENTITY_H

#include <Engine/SceneNode.h>
#include <Engine/Controller.h>
#include <Engine/PhysicsController.h>

class Entity: public SceneNode {
public:
	static const std::string NodeType;

public:
    Entity(const std::string &name);
    ~Entity();

    void update(int elapsed);

    template <typename T>
    void addController(T *controlObject);

protected:
    Entity(const std::string &name, const std::string &type);

private:
    ControllerList _controllers;
};

#endif
