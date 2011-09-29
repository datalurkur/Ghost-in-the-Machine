#ifndef CORE_H
#define CORE_H

#include <Engine/ParentState.h>
#include <Engine/Window.h>

class Core: public ParentState {
public:
    Core();
    ~Core();

    void start();
    void stop();

protected:
    int getTime();

private:
    bool _running;
	Window *_window;
	RenderContext *_renderContext;
};

#endif
