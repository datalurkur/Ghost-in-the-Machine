#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <Engine/State.h>

class UIManager;

class MenuState: public State {
public:
    MenuState();
    virtual ~MenuState();

    bool update(int elapsed);
    bool render(RenderContext *renderContext);

protected:
    void setup(va_list args);
    void teardown();

private:
    UIManager *_ui;
};

#endif
