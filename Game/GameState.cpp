#include <Game/GameState.h>
#include <Game/MenuState.h>
#include <Game/LoadingState.h>

#include <Engine/Core.h>

#include <UI/UIManager.h>

GameState::GameState() {
    _ui = new UIManager();
}

GameState::~GameState() {
    if(_ui) { delete _ui; }
}

void GameState::setup(va_list args) {
    Info("Setting up GameState");

    // Set up the UI
	// Note: I don't like that this has to be done manually
	_core->getViewport()->registerResizeListener(_ui);
}

void GameState::teardown() {
    Info("Tearing down GameState");
}

bool GameState::update(int elapsed) {
    if(ParentState::update(elapsed)) { return true; }

    if(!activeState()) {
        pushState(new MenuState(), _ui);
        return true;
    } else {
        return false;
    }
}