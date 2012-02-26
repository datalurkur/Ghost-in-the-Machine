#include <Game/PlayingState.h>
#include <Resource/WorldManager.h>
#include <Engine/Core.h>
#include <Engine/OrthoCamera.h>
#include <Engine/IsoCamera.h>

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
    _world = va_arg(args, SlugWorld*);

    _camera = _world->createObject<IsoCamera>("MainCam");
    _core->getViewport()->registerCamera(_camera);

	// Update the world once with no time to make sure the scene gets populated fully before rendering
	_world->update(0);
}

void PlayingState::teardown() {
    Info("Tearing down PlayingState");
    WorldManager::Unload(_world);
}

void PlayingState::keyDown(KeyboardEvent *event) {
    switch(event->key()) {
	/* EXAMPLE:
    case KeyboardEvent::KEY_s: {
    } break;
	*/
	default: break;
    };
}

void PlayingState::keyUp(KeyboardEvent *event) {
	switch(event->key()) {
	default: break;
    };
}