#ifndef CONTACT_H
#define CONTACT_H

#include <Physics/PhysicsBody.h>

class Contact {
public:
	inline Contact(PhysicsBody *a, PhysicsBody *b) {
		// Use the pointers to order the bodies (for comparison)
		if(a < b) {
			_a = a;
			_b = b;
		} else {
			_a = b;
			_b = a;
		}
	}

	inline void setIslandFlag() { _island = true; }
	inline bool getIslandFlag() const { return _island; }

	inline bool involves(PhysicsBody *body) {
		return (_a == body || _b == body);
	}

	inline bool operator==(const Contact& rhs) const {
		return (_a == rhs._a && _b == rhs._b);
	}

	inline bool operator<(const Contact& rhs) const {
		if     (_a < rhs._a) { return true;  }
		else if(_a > rhs._a) { return false; }
		else if(_b < rhs._b) { return true;  }
		else                 { return false; }
	}

	inline PhysicsBody* first() const { return _a; }
	inline PhysicsBody* second() const { return _b; }

	inline PhysicsBody* other(PhysicsBody* body) {
		ASSERT(body == _a || body == _b);
		return (body == _a) ? _b : _a;
	}

protected:
	PhysicsBody *_a, *_b;
	bool _island;
};

typedef std::list<Contact*> ContactList;

#endif