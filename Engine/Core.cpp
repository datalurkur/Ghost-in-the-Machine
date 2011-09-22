#include <Engine/Core.h>
#include <SDL.h>

Core::Core(): _running(false) {
}

Core::~Core() {
}

void Core::start() {
    int lastTime, elapsedTime;

    lastTime = getTime();
    _running = true;

    while(_running) {
        int currentTime = getTime();
        elapsedTime = currentTime - lastTime;

        // FIXME - Handle events here

        update(elapsedTime);
        render();

        lastTime = currentTime;
    }

    // Cleanup
}

void Core::stop() {
    _running = false;
}

int Core::getTime() {
    return SDL_GetTicks();
}
