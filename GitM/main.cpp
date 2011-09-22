#include <Engine/Core.h>
#include <GitM/GameState.h>

int main(int argc, char *argv[]) {
    Core *_ghostCore = new Core();

    _ghostCore->pushState(new GameState());
    while(true) {
        _ghostCore->update(0);
        _ghostCore->render();
    }

    delete _ghostCore;

    return 1;
}