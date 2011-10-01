#include <GitM/PlayingState.h>
#include <Engine/Core.h>
#include <Engine/OrthoCamera.h>

PlayingState::PlayingState() {
}

PlayingState::~PlayingState() {
}

void PlayingState::update(int elapsed) {
}

void PlayingState::render(RenderContext *renderContext) {
	_world->render(_camera, renderContext);
}

void PlayingState::setup(va_list args) {
	Info("Setting up PlayingState");
    _world = va_arg(args, World*);

    _camera = _world->create<OrthoCamera>("MainCam");
    _core->getViewport()->registerCamera(_camera);
}

void PlayingState::teardown() {
    if(_world) {
        delete _world;
    }
    if(_camera) {
        delete _camera;
    }
}