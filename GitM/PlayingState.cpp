#include <GitM/PlayingState.h>

PlayingState::PlayingState() {
}

PlayingState::~PlayingState() {
}

void PlayingState::update(int elapsed) {
}

void PlayingState::render(RenderContext *renderContext) {
	RenderableList list;
	renderContext->render(list);
}

void PlayingState::setup(va_list args) {
	Info("Setting up PlayingState");
    _world = va_arg(args, World*);
}

void PlayingState::teardown() {
    if(_world) {
        delete _world;
    }
}