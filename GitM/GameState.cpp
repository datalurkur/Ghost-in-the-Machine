#include <GitM/GameState.h>
#include <GitM/LoadingState.h>

GameState::GameState() {
}

GameState::~GameState() {
}

void GameState::setup(va_list args) {
    std::string *map = va_arg(args, std::string*);
    pushState(new LoadingState(), map);
}

void GameState::teardown() {
}
