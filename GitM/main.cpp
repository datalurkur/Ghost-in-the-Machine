#include <Engine/Core.h>
#include <GitM/GameState.h>

int main(int argc, char *argv[]) {
    Core *_ghostCore = new Core();
    GameState *_gameState = new GameState();

    _ghostCore->pushState(_gameState);
    _ghostCore->start();

    delete _gameState;
    delete _ghostCore;

    return 1;
}
