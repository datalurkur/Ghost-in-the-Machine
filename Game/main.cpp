#include <Game/SimpleCore.h>
#include <Game/GameState.h>

int main(int argc, char *argv[]) {
    Core *_gameCore = new SimpleCore();
    _gameCore->start();
    delete _gameCore;

    return 1;
}
