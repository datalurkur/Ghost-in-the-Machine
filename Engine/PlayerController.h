#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <Engine/Controller.h>

class Player;

class PlayerController: public Controller {
public:
	enum Direction { Left, Right, None };

public:
	PlayerController(Player *player);

	void update(int elapsed);

	void setMovementDirection(Direction dir);
	Direction getMovementDirection() const;
	void jump();

private:
	Direction _movementDirection;
	Player *_player;
	bool _canJump;
};

#endif