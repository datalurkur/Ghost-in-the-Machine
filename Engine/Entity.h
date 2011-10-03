#ifndef ENTITY_H
#define ENTITY_H

#include <Engine/SceneNode.h>

class Entity: public SceneNode {
public:
	static const std::string NodeType;

public:
    Entity(const std::string &name);
    ~Entity();

    void update(int elapsed);

protected:
    Entity(const std::string &name, const std::string &type);

private:
};

#endif
