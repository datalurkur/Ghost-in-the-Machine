#include <Physics/PhysicsBody.h>

PhysicsBody::PhysicsBody(const Vector2 &position, const AABB& bounds, BodyType bodyType):
	_bodyType(bodyType), _position(position), _bounds(bounds),
	_velocity(0.0, 0.0), _force(0.0, 0.0)
{

}

PhysicsBody::~PhysicsBody() {
}

PhysicsBody::BodyType PhysicsBody::getType() const {
	return _bodyType;
}

AABB PhysicsBody::getBounds() const {
	return _bounds;
}

void PhysicsBody::setFlag(PhysicsBody::Flag flag) {
	switch(flag) {
		case Island: _island = true; return;
		case Alert:  _alert  = true; return;
	}
}

void PhysicsBody::clearFlag(PhysicsBody::Flag flag) {
	switch(flag) {
		case Island: _island = false; return;
		case Alert:  _alert  = false; return;
	}
}

bool PhysicsBody::getFlag(PhysicsBody::Flag flag) const {
	switch(flag) {
		case Island: return _island;
		case Alert:  return _alert;
	}
	ASSERT(0);
	return false;
}

void PhysicsBody::addContact(Contact *contact) {
	ContactList::iterator itr = _contacts.begin();
	for(; itr != _contacts.end(); itr++) {
		if(*contact == *(*itr)) { return; }
	}
	_contacts.push_back(contact);
}

ContactList* PhysicsBody::getContacts() {
	return &_contacts;
}

bool PhysicsBody::canCollideWith(PhysicsBody *body) {
	BodyList::iterator itr = _ignoreList.begin();
	for(; itr != _ignoreList.end(); itr++) {
		if((*itr) == body) { return false; }
	}
	return true;
}

void PhysicsBody::synchronize() {
	// FIXME
}