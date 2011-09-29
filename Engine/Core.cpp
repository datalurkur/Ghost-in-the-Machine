#include <Engine/Core.h>
#include <Base/Log.h>
#include <SDL.h>

Core::Core(): _running(false) {
    Log::EnableAllChannels();

    // FIXME - Set this with an options class
	_window = new Window(640, 480);
}

Core::~Core() {
    if(_window) { 
        delete _window;
    }
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
        render();
        
        _window->swapBuffers();

        lastTime = currentTime;
    }

    // Cleanup
    Info("Main loop halted, exiting.");
}

void Core::stop() {
    _running = false;
}

int Core::getTime() {
    return SDL_GetTicks();
}
