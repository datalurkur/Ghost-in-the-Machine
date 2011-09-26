#include <Engine/Core.h>
#include <Base/Log.h>
#include <SDL.h>

Core::Core(): _running(false) {
    Log::EnableAllChannels();
}

Core::~Core() {
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
