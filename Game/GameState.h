#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <Engine/ParentState.h>

class Camera;
class GhostWorld;
class UIManager;

class GameState: public ParentState {
public:
    GameState();
    ~GameState();

    void setup(va_list args);
    void teardown();

    bool update(int elapsed);

    bool mouseMoved(MouseMovedEvent *event);
    bool mouseButton(MouseButtonEvent *event);

private:
    GhostWorld *_world;
    UIManager *_ui;
};

#endif
