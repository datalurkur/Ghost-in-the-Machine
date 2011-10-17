#ifndef PLAYER_H
#define PLAYER_H

#include <Engine/Mob.h>
#include <Engine/PlayerController.h>

class Player: public Mob {
public:
	static const std::string NodeType;
    static const char PlayerBody, JumpSensor;

public:
    Player(const std::string &name);
	virtual ~Player();

    void recreateRenderables();

    void setupPhysics(PhysicsEngine *physics);
    void createPhysicsBody();

	void setPlayerController(PlayerController *controller);
	PlayerController* getPlayerController() const;

public:
    static Player* DefaultPlayer();
    
protected:
    float _jumpPower;
    Vector2 _jumpSensorDimensions, _jumpSensorOffset;

private:
	PlayerController *_playerController;
	friend class PlayerController;
};

#endif