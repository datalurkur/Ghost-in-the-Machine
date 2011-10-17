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
    void setVerts(Vector2 *verts, unsigned int size);
    void setVerts(const std::vector<Vector2> &verts);

    void recreateRenderables();
    
    void setupPhysics(PhysicsEngine *physics);
    void createPhysicsBody();

private:
    std::vector<Vector2> _verts;
};

#endif
