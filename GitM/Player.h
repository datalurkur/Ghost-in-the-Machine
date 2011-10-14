#ifndef PLAYER_H
#define PLAYER_H

#include <Engine/Entity.h>
#include <Engine/PlayerController.h>

class Player: public Entity {
public:
	static const std::string NodeType;

public:
    Player(const std::string &name);
	virtual ~Player();

	void update(int elapsed);

/*	PlayerController::Direction getMovementDirection() const;
	void setMovementDirection(PlayerController::Direction dir);
	void jump();
*/

    void recreateRenderables();

    void setupPhysics(PhysicsEngine *physics);
    void recreatePhysicsBody();

	void setPlayerController(PlayerController *controller);
	PlayerController* getPlayerController() const;

private:
	PlayerController *_playerController;

	float _speed;
	float _height, _width;

	friend class PlayerController;
};

#endif