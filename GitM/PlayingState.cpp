#include <GitM/PlayingState.h>
#include <Resource/WorldManager.h>
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
    WorldManager::Unload(_world);
}

void PlayingState::keyDown(KeyboardEvent *event) {
    switch(event->key()) {
        case KeyboardEvent::KEY_a: {
			PlayerController *p = _world->getPlayer()->getPlayerController();
            p->setMovementDirection(PlayerController::Left);
        } break;
        case KeyboardEvent::KEY_d: {
			PlayerController *p = _world->getPlayer()->getPlayerController();
            p->setMovementDirection(PlayerController::Right);
        } break;
        case KeyboardEvent::KEY_w: {
			PlayerController *p = _world->getPlayer()->getPlayerController();
            p->jump();
        } break;
        case KeyboardEvent::KEY_s: {
        } break;
    };
}

void PlayingState::keyUp(KeyboardEvent *event) {
	switch(event->key()) {
        case KeyboardEvent::KEY_a: {
			PlayerController *p = _world->getPlayer()->getPlayerController();
			if(p->getMovementDirection() == PlayerController::Left) {
				p->setMovementDirection(PlayerController::None);
			}
        } break;
        case KeyboardEvent::KEY_d: {
			PlayerController *p = _world->getPlayer()->getPlayerController();
			if(p->getMovementDirection() == PlayerController::Right) {
				p->setMovementDirection(PlayerController::None);
			}
        } break;
    };
}