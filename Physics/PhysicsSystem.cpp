#include <Physics/PhysicsSystem.h>

PhysicsSystem::PhysicsSystem():
    _gravity(0.0, 0.0)
{
}

PhysicsSystem::~PhysicsSystem() {
}

void PhysicsSystem::step(float time, bool clearWhenDone) {
	ContactList contacts;

	// First, update the broad phase contacts
	if(_newBodies) {
		_newBodies = false;
		_broadPhase.findNewContacts();
	}

	// Now, perform narrow-phase collision detection
	_broadPhase.getContacts(contacts);
	findCollisions(contacts);

	// Solve the system
	solve(time);

	// Clean up
    if(clearWhenDone) {
        clearForces();
    }
}

void PhysicsSystem::solve(float time) {
	// Clear all the island flags in the system
	// FIXME - Write this
}

void PhysicsSystem::findCollisions(const ContactList &contacts) {
	// FIXME - Write this
}

void PhysicsSystem::clearForces() {
}

PhysicsBody* PhysicsSystem::createBody(const Vector2 &pos, const AABB &bounds, PhysicsBody::BodyType type) {
	PhysicsBody *newBody = new PhysicsBody(pos, bounds, type);

	// Store the bodies in two separate data structures - one for fast iteration, the other for fast AABB culling
	_broadPhase.addBody(newBody);
	_bodies.push_back(newBody);

	_newBodies = true;

	return newBody;
}

void PhysicsSystem::destroyBody(PhysicsBody *body) {
	_broadPhase.removeBody(body);
	_bodies.remove(body);
	delete body;
}

void PhysicsSystem::setGravity(const Vector2 &gravity) {
    _gravity = gravity;
}

const Vector2& PhysicsSystem::getGravity() const {
    return _gravity;
}
