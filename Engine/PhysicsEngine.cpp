#include <Engine/PhysicsEngine.h>

PhysicsEngine::PhysicsEngine():
    _gravity(0.0, -10.0), _world(0)
{
    _world = new b2World(b2Vec2(_gravity));
}

PhysicsEngine::~PhysicsEngine() { 
    delete _world;
    _world = 0;
}
