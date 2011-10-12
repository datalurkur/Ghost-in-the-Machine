#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <Base/Vector2.h>
#include <Box2D/Box2D.h>

// Some entites will need more granular control over their body and 
//  fixtures than the functions of this class will provide

class PhysicsEngine {
public:
    PhysicsEngine();
    ~PhysicsEngine();

    void update(int elapsed);

    // Generic do-it-yourself functions
    b2World *getPhysicsWorld();
    void destroyObject(b2Body *body);
    
    // High-level builder functions
    b2Body *createStaticBox(const Vector2 &pos, const Vector2 &dim);
    b2Body *createDynamicBox(const Vector2 &pos, const Vector2 &dim, float density, float friction, bool canRotate = true);

private:
    b2Vec2 _gravity;
    b2World *_world;

    int _stepSize, _velocityIterations, _positionIterations;
};

#endif
