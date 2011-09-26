#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include <Engine/State.h>
#include <GitM/World.h>

class PlayingState: public State {
public:
    PlayingState();
    virtual ~PlayingState();

    void update(int elapsed);
    void render();

protected:
    void setup(va_list args);
    void teardown();
    
private:
    World *_world;
};

#endif
