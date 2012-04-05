#include <Game/PlayingState.h>
#include <Game/GhostWorld.h>

#include <Resource/WorldManager.h>

#include <Engine/Camera.h>
#include <Engine/Core.h>
#include <Engine/OrthoCamera.h>

#include <UI/UIManager.h>
#include <UI/UIElement.h>
#include <UI/Text.h>
#include <UI/UIBox.h>

PlayingState::PlayingState() {
}

PlayingState::~PlayingState() {
}

bool PlayingState::update(int elapsed) {
    _world->update(elapsed);
    _ui->update();

    return true;
}

bool PlayingState::render(RenderContext *renderContext) {
	_world->render(_camera, renderContext);
	_ui->render(renderContext);

    return true;
}

void PlayingState::setup(va_list args) {
	Info("Setting up PlayingState");

	// Get the world from the varargs
    _world = va_arg(args, GhostWorld*);

	// And a camera with which to observe it
    _camera = _world->createObject<OrthoCamera>("MainCam");
    _core->getViewport()->registerResizeListener(_camera);
	_camera->setZoom(0.1f);

    // Get the UI from the varargs
    _ui = va_arg(args, UIManager*);
}

void PlayingState::teardown() {
    Info("Tearing down PlayingState");
    WorldManager::Unload(_world);

    delete _ui;
}

bool PlayingState::keyDown(KeyboardEvent *event) {
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
        default:
            return false;
    };

    return true;
}

bool PlayingState::keyUp(KeyboardEvent *event) {
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
        default:
            return false;
    };

    return true;
}
