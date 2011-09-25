#include <GitM/GameState.h>

GameState::GameState(): _world(0) {
}

GameState::~GameState() {
}

void GameState::setup(va_list args) {
	_world = new World();
}

void GameState::teardown() {
	if(_world) { delete _world; }
}

void GameState::update(int elapsed) {
}

void GameState::render() {
}
