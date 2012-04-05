#include <Engine/ParentState.h>

#include <Game/LoadingState.h>
#include <Game/PlayingState.h>

#include <Resource/WorldManager.h>

LoadingState::LoadingState() {
}

LoadingState::~LoadingState() {
}

bool LoadingState::update(int elapsed) {
    if(WorldManager::IsDone(_world)) {
        _parent->setState(new PlayingState(), _world);
    }

    return true;
}

bool LoadingState::render(RenderContext *renderContext) {
    return true;
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