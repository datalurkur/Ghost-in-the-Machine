#include <Engine/Core.h>
#include <Base/Log.h>
#include <SDL.h>

Core::Core(): _running(false) {
    _core = this;

    Log::EnableAllChannels();

    // FIXME - Set this with an options class
	_window = new Window();
    _viewport = new Viewport();
	_renderContext = new RenderContext();
    
    resizeWindow(640, 480);
}

Core::~Core() {
	delete _renderContext;
    delete _viewport;
	delete _window;
}

void Core::start() {
    int lastTime, elapsedTime;

    lastTime = getTime();
    _running = true;

    Info("Main loop starting.");
    while(_running) {
        int currentTime = getTime();
        elapsedTime = currentTime - lastTime;

        // FIXME - Handle events here

        update(elapsedTime);
		_renderContext->clear();
        render(_renderContext);
        _window->swapBuffers();

        lastTime = currentTime;
    }

    // Cleanup
    Info("Main loop halted, exiting.");
}

void Core::stop() {
    _running = false;
}

void Core::resizeWindow(const int w, const int h) {
    _window->resize(w, h);
    _viewport->resize(0, 0, w, h);
    _renderContext->setViewport(_viewport);
}

int Core::getTime() {
    return SDL_GetTicks();
}

Viewport* Core::getViewport() const {
    return _viewport;
}
