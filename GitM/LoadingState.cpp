#include <Engine/ParentState.h>

#include <GitM/LoadingState.h>
#include <GitM/PlayingState.h>

LoadingState::LoadingState() {
}

LoadingState::~LoadingState() {
}

void LoadingState::update(int elapsed) {
    if(_doneLoading) {
        _parent->setState(new PlayingState(), _world);
    }
}

void LoadingState::render() {
}

void LoadingState::setup(va_list args) {
    _world = new World();
    _world->load(va_arg(args, std::string));
}

void LoadingState::teardown() {
}
