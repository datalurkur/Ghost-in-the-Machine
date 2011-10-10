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
	solve(time, contacts);

	// Clean up
    if(clearWhenDone) {
        clearForces();
    }
}

void PhysicsSystem::solve(float time, ContactList &contacts) {
	ContactList::iterator cItr;
	BodyList::iterator bItr;
	PhysicsBody *origin, *current, *other;
	ContactList *bodyContacts;

	// Clear all the island flags in the system
	for(cItr = contacts.begin(); cItr != contacts.end(); cItr++) {
		(*cItr)->clearFlag(Contact::Island);
	}
	for(bItr = _bodies.begin(); bItr != _bodies.end(); bItr++) {
		(*bItr)->clearFlag(PhysicsBody::Island);
	}

	// Iterate through the bodies, grouping them into islands
	for(bItr = _bodies.begin(); bItr != _bodies.end(); bItr++) {
		origin = (*bItr);

		// Check to see if this body has already been accounted for
		if(origin->getFlag(PhysicsBody::Island)) { continue; }

		// Bodies need to be alert and non-static to start islands
		if(!origin->getFlag(PhysicsBody::Alert)) { continue; }
		if(origin->getType() == PhysicsBody::Static) { continue; }

		// This body meets all the qualifications necessary to begin an island
		Island island;
		std::stack<PhysicsBody*> bodyStack;

		origin->setFlag(PhysicsBody::Island);
		bodyStack.push(origin);

		// Find connected bodies (via contacts, etc) and add them to the island
		while(!bodyStack.empty()) {
			current = bodyStack.top();
			bodyStack.pop();

			// Add the body to the island
			island.addBody(current);

			// Make sure the body is alert
			current->setFlag(PhysicsBody::Alert);

			// Move on to the next body if this one is static
			if(current->getType() == PhysicsBody::Static) { continue; }

			// Search the contacts of this body
			bodyContacts = current->getContacts();
			for(cItr = bodyContacts->begin(); cItr != bodyContacts->end(); cItr++) {
				// Skip contacts that are already part of an island
				if((*cItr)->getFlag(Contact::Island)) { continue; }

				// Skip contacts that are not touching
				if(!(*cItr)->getFlag(Contact::Touching)) { continue; }

				// Add the contact to the island
				island.addContact(*cItr);
				(*cItr)->setFlag(Contact::Island);

				// If the other body is not already part of an island, add it
				other = (*cItr)->other(current);
				if(!other->getFlag(PhysicsBody::Island)) {
					bodyStack.push(other);
					other->setFlag(PhysicsBody::Island);
				}
			}
		}

		// Solve the island
		island.solve(time, _gravity);

		// Clear island flags on static bodies so that they can participate in other islands
		island.clearStaticBodies();
	}

	// Synchronize the bodies with the broad phase
	for(bItr = _bodies.begin(); bItr != _bodies.end(); bItr++) {
		// If a body wasn't part of an island, it was stationary
		if(!(*bItr)->getFlag(PhysicsBody::Island)) { continue; }

		// Static bodies obviously haven't moved
		if((*bItr)->getType() == PhysicsBody::Static) { continue; }

		// Compute an AABB that encompasses the entire sweep of movement
		AABB combined = (*bItr)->getBounds();
		// FIXME - Compute an expansion AABB using the swept motion of the body
		combined.expand(AABB());

		// FIXME - Compute a displacement vector
		Vector2 displacement;

		_broadPhase.moveBody(*bItr, combined, displacement);
	}

	// Find new contacts
	_broadPhase.findNewContacts();
}

void PhysicsSystem::findCollisions(ContactList &contacts) {
	ContactList::iterator current, itr;
	Contact *contact;
	PhysicsBody *first, *second;

	itr = contacts.begin();
	while(itr != contacts.end()) {
		current = itr;
		itr++;
		contact = (*current);

		// Check to see if this contact needs filtering
		if(contact->getFlag(Contact::Filter)) {
			// Can this contact collide?
			if(!contact->canCollide()) {
				contacts.erase(current);
				delete contact;
				continue;
			}
			contact->clearFlag(Contact::Filter);
		}

		// One of the bodies must be alert and non-static
		first = contact->first();
		second = contact->second();
		if(!((first->getFlag(PhysicsBody::Alert)  && first->getType()  != PhysicsBody::Static) ||
			 (second->getFlag(PhysicsBody::Alert) && second->getType() != PhysicsBody::Static))) {
			continue;
		}

		// Check to see if the contact still overlaps in the broad phase
		if(!contact->overlaps()) {
			contacts.erase(current);
			delete contact;
			continue;
		}

		// Update the contact
		contact->update();
	}
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
