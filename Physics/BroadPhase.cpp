#include <Physics/BroadPhase.h>

BroadPhase::BroadPhase() {
}

BroadPhase::~BroadPhase() {
}

void BroadPhase::addBody(PhysicsBody *body) {
	_bodies.insert(body, body->getBounds());

	// FIXME - Check to see if new contacts are created with the addition of this body
}

void BroadPhase::removeBody(PhysicsBody *body) {
	_bodies.remove(body);

	// FIXME - Remove any contacts involving this body
}

void BroadPhase::getContacts(ContactList &contacts) {
	// FIXME - Return a list of contacts that are currently being maintained
}