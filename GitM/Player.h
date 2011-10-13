#ifndef PLAYER_H
#define PLAYER_H

#include <Engine/Entity.h>

class Player: public Entity {
public:
	static const std::string NodeType;

public:
    Player(const std::string &name);
	Player(const std::string &name, va_list args);
	virtual ~Player();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void recreateRenderables();

    void setupPhysics(PhysicsEngine *physics);
    void recreatePhysicsBody();

private:
};

#endif