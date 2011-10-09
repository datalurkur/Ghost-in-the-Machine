#ifndef CONTACT_H
#define CONTACT_H

#include <Base/Base.h>

class PhysicsBody;

class Contact {
public:
	enum Flag {
		Island,
		Filter,
		Touching
	};

	Contact(PhysicsBody *a, PhysicsBody *b);

	void setFlag(Flag flag);
	void clearFlag(Flag flag);
	bool getFlag(Flag flag) const;

	bool canCollide();
	bool overlaps();
	bool involves(PhysicsBody *body);

	bool operator==(const Contact& rhs) const;
	bool operator<(const Contact& rhs) const;

	PhysicsBody* first() const;
	PhysicsBody* second() const;
	PhysicsBody* other(PhysicsBody* body);

	void update();

protected:
	PhysicsBody *_a, *_b;
	bool _island, _filter, _touching;
};

typedef std::list<Contact*> ContactList;

#endif