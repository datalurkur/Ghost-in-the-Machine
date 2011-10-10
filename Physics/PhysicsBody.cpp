#include <Physics/PhysicsBody.h>

PhysicsBody::PhysicsBody(const Vector2 &position, const AABB& bounds, BodyType bodyType):
	_bodyType(bodyType), _position(position), _prevPosition(position), _bounds(bounds),
	_velocity(0.0, 0.0), _force(0.0, 0.0), _damping(0.0), _mass(1.0), _inverseMass(1.0)
{

}

PhysicsBody::~PhysicsBody() {
}

PhysicsBody::BodyType PhysicsBody::getType() const { return _bodyType; }
AABB PhysicsBody::getBounds() const { return _bounds; }
Vector2 PhysicsBody::getPosition() const { return _position; }
Vector2 PhysicsBody::getLastPosition() const { return _prevPosition; }
Vector2 PhysicsBody::getVelocity() const { return _velocity; }
Vector2 PhysicsBody::getForce() const {	return _force; }
float PhysicsBody::getMass() const { return _mass; }
float PhysicsBody::getInverseMass() const {	return _inverseMass; }
float PhysicsBody::getDamping() const { return _damping; }

void PhysicsBody::setPosition(const Vector2 &position) {
	_prevPosition = _position;
	_position = position;
}

void PhysicsBody::setVelocity(const Vector2 &velocity) {
	_velocity = velocity;
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