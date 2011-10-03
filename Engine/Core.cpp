#include <Engine/Core.h>
#include <Base/Log.h>

Core::Core(): _running(false) {
    _core = this;

    Log::EnableAllChannels();

    // FIXME - Set this with an options class
	_window = new Window();
    _viewport = new Viewport();
	_renderContext = new RenderContext();
    
	_eventHandler = new EventHandler();
	_eventHandler->addWindowListener(this);

    resizeWindow(640, 480);
}

Core::~Core() {
	delete _eventHandler;

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

        _eventHandler->handleEvents();

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

void Core::closeWindow() {
	stop();
    flushStates();
}

int Core::getTime() {
    return SDL_GetTicks();
}

Viewport* Core::getViewport() const {
    return _viewport;
}
