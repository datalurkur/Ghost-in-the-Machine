#include <Engine/ParentState.h>

#include <GitM/LoadingState.h>
#include <GitM/PlayingState.h>

#include <Resource/WorldManager.h>

LoadingState::LoadingState() {
}

LoadingState::~LoadingState() {
}

void LoadingState::update(int elapsed) {
    if(WorldManager::IsDone(_world)) {
        _parent->setState(new PlayingState(), _world);
    }
}

void LoadingState::render(RenderContext *renderContext) {
}

void LoadingState::setup(va_list args) {
    Info("Setting up LoadingState");
	std::string *map = va_arg(args, std::string*);
    _world = WorldManager::Load(*map);
}

void LoadingState::teardown() {
    Info("Tearing down LoadingState");
}