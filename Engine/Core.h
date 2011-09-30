#ifndef CORE_H
#define CORE_H

#include <Engine/ParentState.h>
#include <Engine/Window.h>
#include <Render/Viewport.h>

class Core: public ParentState {
public:
    Core();
    ~Core();

    void start();
    void stop();

    void resizeWindow(const int w, const int h);

    Viewport *getViewport() const;

protected:
    int getTime();

private:
    bool _running;

	Window *_window;
    Viewport *_viewport;
	RenderContext *_renderContext;
};

#endif
