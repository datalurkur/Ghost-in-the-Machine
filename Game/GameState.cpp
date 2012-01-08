#include <Game/GameState.h>
#include <Game/LoadingState.h>

GameState::GameState() {
}

GameState::~GameState() {
}

void GameState::setup(va_list args) {
    Info("Setting up GameState");
    std::string *map = va_arg(args, std::string*);
    pushState(new LoadingState(), map);
}

void GameState::teardown() {
    Info("Tearing down GameState");
}
