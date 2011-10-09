#include <Physics/BroadPhase.h>

const Vector2 aabbBuffer(0.1, 0.1);

BroadPhase::BroadPhase() {
}

BroadPhase::~BroadPhase() {
}

void BroadPhase::addBody(PhysicsBody *body) {
	_bodies.insert(body, body->getBounds() + aabbBuffer);

	// Flag this body as moving to make sure it gets checked for contact creation later
	flagMoving(body);
}

void BroadPhase::removeBody(PhysicsBody *body) {
	_bodies.remove(body);

	ContactList::iterator prev, current;
	current = _contacts.begin();
	while(current != _contacts.end()) {
		prev = current;
		current++;

		if((*prev)->involves(body)) {
			delete (*prev);
			_contacts.erase(prev);
		}
	}
}

void BroadPhase::moveBody(PhysicsBody *body, const AABB& bounds, const Vector2& distance) {
	// FIXME - Write this function

	flagMoving(body);
}

void BroadPhase::findNewContacts() {
	// Query the AABBTree for each moving body
	BodyList::iterator i, j;
	for(i = _movingBodies.begin(); i != _movingBodies.end(); i++) {
		BodyList newContacts;
		_bodies.query((*i)->getBounds() + aabbBuffer, newContacts);
		for(j = newContacts.begin(); j != newContacts.end(); j++) {
			// A body should not collide with itself
			if((*i) != (*j)) {
				addContact(*i, *j);
			}
		}
	}
	_movingBodies.clear();
}

void BroadPhase::getContacts(ContactList &contacts) {
	contacts.insert(contacts.end(), _contacts.begin(), _contacts.end());
}

void BroadPhase::addContact(PhysicsBody *a, PhysicsBody *b) {
	Contact *contact;
	ContactList::iterator itr, prev;

	// Check to see if these two bodies should not collide
	// At least one body must be dynamic
	if(a->getType() != PhysicsBody::Dynamic && b->getType() != PhysicsBody::Dynamic) {
		return;
	}

	// See if either one of the bodies is in the other's ignore list
	if(!a->canCollideWith(b) || b->canCollideWith(a)) { return; }

	// Create the contact object
	contact = new Contact(a, b)

	// Find the location this contact should be inserted into the sorted list, and check for redundancy while we're at it
	for(itr = _contacts.begin(); itr != _contacts.end(); itr++) {
		if(*contact < *(*itr)) {
			if(itr != _contacts.begin() && (*prev) == (*contact)) {
				// This contact is redundant
				delete contact;
				return;
			}
			break;
		}
		prev = itr;
	}

	// Insert the contact into the sorted list
	_contacts.insert(itr, contact);

	// Add a reference to the contact in both bodies
	a->addContact(contact);
	b->addContact(contact);

	// Set the bodies at alert
	a->setAlert();
	b->setAlert();

	// Add the contact to the contacts list
	_contacts.push_back(contact);
}

void BroadPhase::flagMoving(PhysicsBody *body) {
	_movingBodies.push_back(body);
}