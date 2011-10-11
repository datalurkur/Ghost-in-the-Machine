#include <Physics/Contact.h>
#include <Physics/PhysicsBody.h>

Contact::Contact(PhysicsBody *a, PhysicsBody *b) {
	// Use the pointers to order the bodies (for comparison)
	if(a < b) {
		_a = a;
		_b = b;
	} else {
		_a = b;
		_b = a;
	}
}

void Contact::setFlag(Flag flag) {
	switch(flag) {
		case Island:   _island   = true; return;
		case Filter:   _filter   = true; return;
		case Touching: _touching = true; return;
	};
}

void Contact::clearFlag(Flag flag) {
	switch(flag) {
		case Island:   _island   = false; return;
		case Filter:   _filter   = false; return;
		case Touching: _touching = false; return;
	};
}

bool Contact::getFlag(Flag flag) const {
	switch(flag) {
		case Island:   return _island;
		case Filter:   return _filter;
		case Touching: return _touching;
	};
	ASSERT(0);
	return false;
}

bool Contact::canCollide() {
	return (_a->canCollideWith(_b) && _b->canCollideWith(_a));
}

bool Contact::overlaps() {
	return _a->getBounds().overlaps(_b->getBounds());
}

bool Contact::involves(PhysicsBody *body) {
	return (_a == body || _b == body);
}

bool Contact::operator==(const Contact& rhs) const {
	return (_a == rhs._a && _b == rhs._b);
}

bool Contact::operator<(const Contact& rhs) const {
	if     (_a < rhs._a) { return true;  }
	else if(_a > rhs._a) { return false; }
	else if(_b < rhs._b) { return true;  }
	else                 { return false; }
}

PhysicsBody* Contact::first() const { return _a; }

PhysicsBody* Contact::second() const { return _b; }

PhysicsBody* Contact::other(PhysicsBody* body) {
	ASSERT(body == _a || body == _b);
	return (body == _a) ? _b : _a;
}

void Contact::update() {
	bool isTouching, wasTouching;
	
	wasTouching = getFlag(Touching);

	// Find the collision manifold
	isTouching = computeManifold();

	// Update the alert status of the bodies
	if(wasTouching != isTouching) {
		_a->setFlag(PhysicsBody::Alert);
		_b->setFlag(PhysicsBody::Alert);
	}

	// Set the touching flag appropriately
	if(isTouching) {
		setFlag(Touching);
	} else {
		clearFlag(Touching);
	}

	// Handle events
	if(wasTouching && !isTouching) {
		// Contact ended
	} else if(!wasTouching && isTouching) {
		// Contact started
	}
}

bool Contact::computeManifold() {
	AABB b1, b2;
	float centerDistance, maxDistance1, maxDistance2;

	_manifoldPoints = 0;

	b1 = first()->getBounds();
	b2 = second()->getBounds();

	maxDistance1 = 
}