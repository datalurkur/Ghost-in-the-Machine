#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H

#include <Engine/State.h>
#include <Game/GhostWorld.h>

class LoadingState: public State {
public:
    LoadingState();
    virtual ~LoadingState();

    void update(int elapsed);
    void render(RenderContext *renderContext);

protected:
    void setup(va_list args);
    void teardown();

private:
    GhostWorld *_world;
    bool _doneLoading;
};

#endif
