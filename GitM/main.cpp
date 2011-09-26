#include <Engine/Core.h>
#include <GitM/GameState.h>

int main(int argc, char *argv[]) {
    Core *_ghostCore = new Core();

    _ghostCore->pushState(new GameState(), "test_world.wld");
    _ghostCore->start();

    delete _ghostCore;

    return 1;
}
