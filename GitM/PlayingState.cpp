#include <GitM/PlayingState.h>
#include <Resource/ThreadedWorldFactory.h>
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

	// Update the world once with no time to make sure the scene gets populated fully before rendering
	_world->update(0);
}

void PlayingState::teardown() {
    Info("Tearing down PlayingState");
    ThreadedWorldFactory::Unload(_world);
}