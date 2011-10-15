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

    void recreateRenderables();

    void setupPhysics(PhysicsEngine *physics);
    void recreatePhysicsBody();

	//void setPlayerController(PlayerController *controller);
	PlayerController* getPlayerController() const;

private:
	PlayerController *_playerController;
	friend class PlayerController;
};

#endif