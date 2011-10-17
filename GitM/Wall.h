#ifndef WALL_H
#define WALL_H

#include <Engine/Entity.h>

class Wall: public Entity {
public:
    static const std::string NodeType;

public:
    Wall(const std::string &name);
    virtual ~Wall();

    void addVert(const Vector2 &vert);

    void createRenderables();
    
    void setupPhysics(PhysicsEngine *physics);
    void createPhysicsBody();

private:
    std::vector<Vector2> _verts;
};

#endif
