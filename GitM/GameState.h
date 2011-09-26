#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <Engine/ParentState.h>

class GameState: public ParentState {
public:
    GameState();
    ~GameState();

    void setup(va_list args);
    void teardown();

private:
};

#endif
