#ifndef ISLAND_H
#define ISLAND_H

#include <Base/Vector2.h>
#include <Physics/PhysicsBody.h>

class Island {
public:
	Island();
	~Island();

	void addBody(PhysicsBody *body);
	void addContact(Contact *contact);

	void solve(float time, const Vector2 &gravity);

	void clearStaticBodies();

private:
	BodyList _bodies;
	ContactList _contacts;
};

#endif