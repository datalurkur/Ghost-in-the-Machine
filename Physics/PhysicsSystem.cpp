#include <Physics/PhysicsSystem.h>

PhysicsSystem::PhysicsSystem():
    _gravity(0.0, 0.0)
{
}

PhysicsSystem::~PhysicsSystem() {
}

void PhysicsSystem::step(float time, bool clearWhenDone) {
	// First, update the broad phase contacts
	// FIXME - Update contacts

	// Next, solve the system
	solve(time);

    if(clearWhenDone) {
        clearForces();
    }
}

void PhysicsSystem::solve(float time) {
	// FIXME - Solve
}

void PhysicsSystem::clearForces() {
}

PhysicsBody* PhysicsSystem::createBody(const Vector2 &pos, const AABB &bounds, PhysicsBody::BodyType type) {
	PhysicsBody *newBody = new PhysicsBody(pos, bounds, type);
	_broadPhase.addBody(newBody);
	return newBody;
}

void PhysicsSystem::destroyBody(PhysicsBody *body) {
	_broadPhase.removeBody(body);
	delete body;
}

void PhysicsSystem::setGravity(const Vector2 &gravity) {
    _gravity = gravity;
}

const Vector2& PhysicsSystem::getGravity() const {
    return _gravity;
}
