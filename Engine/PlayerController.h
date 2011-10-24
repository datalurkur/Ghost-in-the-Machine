#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <Engine/Controller.h>
#include <Engine/ContactListener.h>

class Player;

class PlayerController: public Controller, public ContactListener {
public:
	enum Direction { Left, Right, None };

public:
	PlayerController(Player *player);

	void update(int elapsed);

	bool isTouchingGround();

	void setMovementDirection(Direction dir);
	Direction getMovementDirection() const;
	void jump();
    
    void contactBegins(Entity *a, Entity *b);
    void contactBegins(FixtureID *trigger, FixtureID *other);
    void contactEnds(Entity *a, Entity *b);
    void contactEnds(FixtureID *trigger, FixtureID *other);

private:
	Player *_player;
	Direction _movementDirection;
	int _jumpSensorContacts;
	int _extraJumpsLeft;
};

#endif
