#include <Game/GhostCore.h>
#include <Game/GameState.h>

int main(int argc, char *argv[]) {
    Core *_ghostCore = new GhostCore();
    _ghostCore->start();
    delete _ghostCore;

    return 1;
}
