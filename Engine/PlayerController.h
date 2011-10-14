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

	void setMovementDirection(Direction dir);
	Direction getMovementDirection() const;
	void jump();
    
    bool canJump();
    void setCanJump(bool canJump);
    
    void contactBegins(Entity *a, Entity *b);
    void contactEnds(Entity *a, Entity *b);

private:
	Direction _movementDirection;
	Player *_player;
	bool _canJump;
};

#endif