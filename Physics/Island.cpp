#include <Physics/Island.h>
#include <Physics/PhysicsBody.h>
#include <Physics/Contact.h>

Island::Island() {
}

Island::~Island() {
}

void Island::addBody(PhysicsBody *body) {
	_bodies.push_back(body);
}

void Island::addContact(Contact *contact) {
	_contacts.push_back(contact);
}

void Island::solve(float time, const Vector2 &gravity) {
	BodyList::iterator bItr;
	PhysicsBody *body;

	// Integrate velocity for each body
	for(bItr = _bodies.begin(); bItr != _bodies.end(); bItr++) {
		body = *bItr;
		if(body->getType() != PhysicsBody::Dynamic) { continue; }

		Vector2 newVelocity = body->getVelocity();
		// Apply foce and gravity
		newVelocity += time * (gravity + (body->getForce() * body->getInverseMass()));
		// Apply the linear damping factor
		newVelocity *= max(min(1.0 - (time * body->getDamping()), 1.0), 0.0);

		body->setVelocity(newVelocity);
	}

	// Solve constraints
}

void Island::clearStaticBodies() {
	// FIXME
}