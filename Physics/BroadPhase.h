#ifndef BROADPHASE_H
#define BROADPHASE_H

#include <Physics/AABBTree.h>
#include <Physics/PhysicsBody.h>
#include <Physics/Contact.h>

// Keeps a list of contacts as bodies are added to the broad phase or moved
// Destroys contact as bodies move or as bodies are removed from the broad phase

// A buffer used to expand the AABBs of objects in the AABBTree, to better detect when bodies will collide
extern const Vector2 aabbBuffer;

class BroadPhase {
public:
	BroadPhase();
	~BroadPhase();

	void addBody(PhysicsBody *body);
	void removeBody(PhysicsBody *body);
	void moveBody(PhysicsBody *body, const AABB& bounds, const Vector2& distance);

	void findNewContacts();

	void getContacts(ContactList &contacts);

private:
	void addContact(PhysicsBody *a, PhysicsBody *b);

	void flagMoving(PhysicsBody *body);

private:
	AABBTree<PhysicsBody> _bodies;

	BodyList _movingBodies;

	// SORTED list of contacts (this is necessary for speed in redundancy checking)
	ContactList _contacts;
};

#endif