#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <Engine/ParentState.h>

class Camera;

class GameState: public ParentState {
public:
    GameState();
    ~GameState();

    void setup(va_list args);
    void teardown();
};

#endif
