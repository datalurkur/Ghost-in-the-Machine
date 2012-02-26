#ifndef SLUGWORLD_H
#define SLUGWORLD_H

#include <Game/World.h>
#include <Game/Terrain.h>

class SlugWorld: public World {
public:
    SlugWorld();
    virtual ~SlugWorld();

protected:
    Terrain *_terrain;
};

#endif
