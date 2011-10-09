#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <Physics/PhysicsBody.h>
#include <Physics/BroadPhase.h>
#include <Physics/Island.h>

class PhysicsSystem {
public:
    PhysicsSystem();
    ~PhysicsSystem();

    void step(float time, bool clearWhenDone = true);
	void solve(float time);
    void clearForces();

    PhysicsBody* createBody(const Vector2 &pos, const AABB &bounds, PhysicsBody::BodyType type = PhysicsBody::Static);
    void destroyBody(PhysicsBody *body);

    void setGravity(const Vector2 &gravity);
    const Vector2& getGravity() const;

private:
	void findCollisions(const ContactList &contacts);

private:
	bool _newBodies;

    Vector2 _gravity;
	BroadPhase _broadPhase;
	BodyList _bodies;
};

#endif
