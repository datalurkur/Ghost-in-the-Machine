#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H

#include <Base/Vector2.h>
#include <Physics/AABB.h>
#include <Physics/Contact.h>

class PhysicsBody;

typedef std::list<PhysicsBody*> BodyList;

class PhysicsBody {
public:
	enum BodyType {
		Static,		// Immovable, massless bodies (static world data, terrain, etc)
		Dynamic,	// Bodies affected by all aspects of the simulation (forces, impulses, collisions, etc)
		Artificial	// Bodies that generate collision callbacks but are not affected by collisions (attack volumes, etc)
	};

	enum Flag {
		Island,
		Alert
	};

    PhysicsBody(const Vector2 &position, const AABB& bounds, BodyType bodyType);
    ~PhysicsBody();

	BodyType getType() const;
	AABB getBounds() const;

	Vector2 getPosition() const;
	Vector2 getLastPosition() const;
	Vector2 getVelocity() const;
	Vector2 getForce() const;

	float getMass() const;
	float getInverseMass() const;
	float getDamping() const;

	void setPosition(const Vector2 &position);
	void setVelocity(const Vector2 &velocity);

	void setFlag(Flag flag);
	void clearFlag(Flag flag);
	bool getFlag(Flag flag) const;

	void addContact(Contact *contact);
	ContactList* getContacts();

	bool canCollideWith(PhysicsBody *body);

private:
	// Deterines the type of physical simulation that this body undergoes
	BodyType _bodyType;

	// Physical definition and current modifiers
	Vector2 _prevPosition, _position, _velocity, _force;
	float _mass, _inverseMass, _friction, _density, _damping;

	// The bounding box of this body
	AABB _bounds;

	// A list of bodies this body will not collide with
	BodyList _ignoreList;

	// A list of contacts this body is involved in
	ContactList _contacts;

	// Is this body possibly contacting another?
	bool _alert, _island;
};

#endif
