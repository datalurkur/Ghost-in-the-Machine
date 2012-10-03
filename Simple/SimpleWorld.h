#ifndef SIMPLEWORLD_H
#define SIMPLEWORLD_H

#include <Engine/World.h>

class SimpleWorld: public World {
public:
	SimpleWorld();
	virtual ~SimpleWorld();

	void update(int elapsed);
};

#endif
