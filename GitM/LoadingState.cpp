#include <Engine/ParentState.h>

#include <GitM/LoadingState.h>
#include <GitM/PlayingState.h>

#include <GitM/ThreadedWorldFactory.h>

LoadingState::LoadingState() {
}

LoadingState::~LoadingState() {
}

void LoadingState::update(int elapsed) {
    if(ThreadedWorldFactory::IsDone(_world)) {
        ThreadedWorldFactory::Finish(_world);
        _parent->setState(new PlayingState(), _world);
    } else {
        //Info("Status: " << ThreadedWorldFactory::Status(_world));
    }
}

void LoadingState::render(RenderContext *renderContext) {
}

void LoadingState::setup(va_list args) {
    _world = ThreadedWorldFactory::Load("test_world.wld");
}

void LoadingState::teardown() {
}