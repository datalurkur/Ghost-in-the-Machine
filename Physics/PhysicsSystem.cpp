#include <Physics/PhysicsSystem.h>

PhysicsSystem::PhysicsSystem():
    _gravity(0.0, 0.0)
{
}

PhysicsSystem::~PhysicsSystem() {
}

void PhysicsSystem::step(float time, bool clearWhenDone) {

    if(clearWhenDone) {
        clearForces();
    }
}

void PhysicsSystem::clearForces() {
}

PhysicsBody* PhysicsSystem::createBody() {
}

void PhysicsSystem::destroyBody(PhysicsBody *body) {
}

void PhysicsSystem::setGravity(const Vector2 &gravity) {
    _gravity = gravity;
}

const Vector2& PhysicsSystem::getGravity() const {
    return _gravity;
}
