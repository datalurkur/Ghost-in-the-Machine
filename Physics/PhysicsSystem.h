#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <Physics/AABBTree.h>
#include <Physics/PhysicsBody.h>

class PhysicsSystem {
public:
    PhysicsSystem();
    ~PhysicsSystem();

    void step(float time, bool clearWhenDone = true);
    void clearForces();

    PhysicsBody* createBody();
    void destroyBody(PhysicsBody *body);

    void setGravity(const Vector2 &gravity);
    const Vector2& getGravity() const;

private:
    Vector2 _gravity;
    AABBTree _bodies;
};

#endif
