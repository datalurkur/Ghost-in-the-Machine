#ifndef GHOSTWORLD_H
#define GHOSTWORLD_H

#include <Engine/World.h>
#include <Game/Player.h>

class GhostWorld: public World {
public:
	GhostWorld();
	virtual ~GhostWorld();

	void load(const std::string &name);

    // Return the player object
    Player *getPlayer();

protected:
	Player *_player;
};

#endif
