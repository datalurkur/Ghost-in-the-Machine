#ifndef WALL_H
#define WALL_H

#include <Engine/Entity.h>

class Wall: public Entity {
public:
    static const std::string NodeType;

public:
    Wall(const std::string &name);
    virtual ~Wall();

    void addVert(const Vector2<float> &vert);
    void setVerts(Vector2<float> *verts, unsigned int size);
    void setVerts(const std::vector<Vector2<float> > &verts);

    void recreateRenderables();
    
    void setupPhysics(PhysicsEngine *physics);
    void createPhysicsBody();

private:
    std::vector<Vector2<float> > _verts;
};

#endif
