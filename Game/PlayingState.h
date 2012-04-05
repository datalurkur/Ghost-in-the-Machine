#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include <Engine/State.h>

class Camera;
class GhostWorld;
class UIManager;

class PlayingState: public State {
public:
    PlayingState();
    virtual ~PlayingState();

    bool keyDown(KeyboardEvent *event);
    bool keyUp(KeyboardEvent *event);

    bool update(int elapsed);
    bool render(RenderContext *renderContext);

protected:
    void setup(va_list args);
    void teardown();

private:
    GhostWorld *_world;
    Camera *_camera;

    UIManager *_ui;
};

#endif
