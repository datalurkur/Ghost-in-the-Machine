#ifndef BROADPHASE_H
#define BROADPHASE_H

#include <Physics/AABBTree.h>
#include <Physics/PhysicsBody.h>

typedef std::pair<PhysicsBody*,PhysicsBody*> Contact;
typedef std::list<Contact> ContactList;

// Keeps a list of contacts as bodies are added to the broad phase or moved
// Destroys contact as bodies move or as bodies are removed from the broad phase

class BroadPhase {
public:
	BroadPhase();
	~BroadPhase();

	void addBody(PhysicsBody *body);
	void removeBody(PhysicsBody *body);

	void getContacts(ContactList &contacts);

private:
	AABBTree<PhysicsBody> _bodies;
	ContactList _contacts;
};

#endif