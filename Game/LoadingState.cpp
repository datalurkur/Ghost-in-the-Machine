#include <Engine/ParentState.h>

#include <Game/LoadingState.h>
#include <Game/PlayingState.h>

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
	GhostWorld *ghostWorld = new GhostWorld();
    _world = (GhostWorld*)WorldManager::Load(*map, (World*)ghostWorld);
}

void LoadingState::teardown() {
    Info("Tearing down LoadingState");
}