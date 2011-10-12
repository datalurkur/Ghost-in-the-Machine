#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <Box2D/Box2D.h>

class PhysicsEngine {
public:
    PhysicsEngine();
    ~PhysicsEngine();

private:
    b2Vec2 _gravity;
    b2World *_world;
};

#endif
