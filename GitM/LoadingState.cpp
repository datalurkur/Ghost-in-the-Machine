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
    _world = WorldManager::Load("test_world.wld");
}

void LoadingState::teardown() {
    Info("Tearing down LoadingState");
}