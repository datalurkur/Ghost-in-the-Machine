#include <GitM/GhostCore.h>
#include <GitM/GameState.h>

int main(int argc, char *argv[]) {
    Core *_ghostCore = new GhostCore();
    _ghostCore->start();
    delete _ghostCore;

    return 1;
}
