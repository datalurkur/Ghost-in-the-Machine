#include <GitM/PlayingState.h>
#include <GitM/ThreadedWorldFactory.h>
#include <Engine/Core.h>
#include <Engine/OrthoCamera.h>

PlayingState::PlayingState() {
}

PlayingState::~PlayingState() {
}

void PlayingState::update(int elapsed) {
    _world->update(elapsed);
}

void PlayingState::render(RenderContext *renderContext) {
	_world->render(_camera, renderContext);
}

void PlayingState::setup(va_list args) {
	Info("Setting up PlayingState");
    _world = va_arg(args, World*);

    _camera = _world->createObject<OrthoCamera>("MainCam");
    _core->getViewport()->registerCamera(_camera);
}

void PlayingState::teardown() {
    Info("Tearing down PlayingState");
    ThreadedWorldFactory::Unload(_world);
}