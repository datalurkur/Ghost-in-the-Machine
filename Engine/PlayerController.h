#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <Engine/Controller.h>
#include <Engine/ContactListener.h>

class Player;

class PlayerController: public Controller, public ContactListener {
public:
	enum Direction { Left, Right, None };
	
	enum Parts {
		PlayerBody,
		JumpVolume
	};

public:
	PlayerController(Player *player);

	void update(int elapsed);

	void setMovementDirection(Direction dir);
	Direction getMovementDirection() const;
	void jump();
    
    void contactBegins(Entity *a, Entity *b);
    void contactBegins(FixtureID *a);
    void contactEnds(Entity *a, Entity *b);
    void contactEnds(FixtureID *a);

private:
	Direction _movementDirection;
	Player *_player;
	int _jumpBoxContacts;
};

#endif