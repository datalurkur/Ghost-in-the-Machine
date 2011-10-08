#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H

#include <Base/Vector2.h>
#include <Physics/AABB.h>

class PhysicsBody {
public:
	enum BodyType {
		Static,		// Immovable, massless bodies (static world data, terrain, etc)
		Dynamic,	// Bodies affected by all aspects of the simulation (forces, impulses, collisions, etc)
		Artificial	// Bodies that generate collision callbacks but are not affected by collisions (attack volumes, etc)
	};

    PhysicsBody(const Vector2 &position, const AABB& bounds, BodyType bodyType);
    ~PhysicsBody();

	const AABB& getBounds() const;

private:
	// Deterines the type of physical simulation that this body undergoes
	BodyType _bodyType;

	// Physical definition and current modifiers
	Vector2 _position, _velocity, _force;
	float _mass, _friction, _density;

	// The bounding box of this body
	AABB _bounds;

	// A list of bodies this body will not collide with
	std::list<PhysicsBody*> _ignoreList;
};

#endif
