#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H

#include <Engine/State.h>
#include <Game/GhostWorld.h>

class LoadingState: public State {
public:
    LoadingState();
    virtual ~LoadingState();

    bool update(int elapsed);
    bool render(RenderContext *renderContext);

protected:
    void setup(va_list args);
    void teardown();

private:
    GhostWorld *_world;
    bool _doneLoading;
};

#endif
