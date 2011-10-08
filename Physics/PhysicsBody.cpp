#include <Physics/PhysicsBody.h>

PhysicsBody::PhysicsBody(const Vector2 &position, const AABB& bounds, BodyType bodyType):
	_bodyType(bodyType), _position(position), _bounds(bounds),
	_velocity(0.0, 0.0), _force(0.0, 0.0)
{

}

PhysicsBody::~PhysicsBody() {
}

const AABB& PhysicsBody::getBounds() const {
	return _bounds;
}