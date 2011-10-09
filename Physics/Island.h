#ifndef ISLAND_H
#define ISLAND_H

class PhysicsBody;
class Contact;

class Island {
public:
	Island();
	~Island();

	void addBody(PhysicsBody *body);
	void addContact(Contact *contact);

	void solve(float time);

	void clearStaticBodies();

private:
};

#endif