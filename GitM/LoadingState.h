#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H

#include <Engine/State.h>
#include <GitM/World.h>

class LoadingState: public State {
public:
    LoadingState();
    virtual ~LoadingState();

    void update(int elapsed);
    void render();

protected:
    void setup(va_list args);
    void teardown();

private:
    World *_world;
    bool _doneLoading;
};

#endif