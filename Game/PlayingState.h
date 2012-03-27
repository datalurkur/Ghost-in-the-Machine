#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include <Engine/State.h>
#include <Game/GhostWorld.h>
#include <UI/UIManager.h>

class PlayingState: public State {
public:
    PlayingState();
    virtual ~PlayingState();

    void keyDown(KeyboardEvent *event);
    void keyUp(KeyboardEvent *event);

    void update(int elapsed);
    void render(RenderContext *renderContext);

protected:
    void setup(va_list args);
    void teardown();

private:
    GhostWorld *_world;
    Camera *_camera;

    UIManager *_ui;
};

#endif
