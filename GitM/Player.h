#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player();
	virtual ~Player();

private:
	Entity *_entity;
};

#endif