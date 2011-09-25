#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <Engine/State.h>
#include <GitM/World.h>

class GameState: public State {
public:
    GameState();
    ~GameState();

    void setup(va_list args);
    void teardown();

    void update(int elapsed);
    void render();

private:
	World *_world;
};

#endif
