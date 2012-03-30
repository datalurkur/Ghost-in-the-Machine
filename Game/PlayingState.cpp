#include <Game/PlayingState.h>
#include <Resource/WorldManager.h>
#include <Engine/Core.h>
#include <Engine/OrthoCamera.h>
#include <UI/UIElement.h>

PlayingState::PlayingState() {
}

PlayingState::~PlayingState() {
}

void PlayingState::update(int elapsed) {
    _world->update(elapsed);
    _ui->update();
}

void PlayingState::render(RenderContext *renderContext) {
	_world->render(_camera, renderContext);
	_ui->render(renderContext);
}

void PlayingState::setup(va_list args) {
	Info("Setting up PlayingState");

	// Create a world...
    _world = va_arg(args, GhostWorld*);

	// And a camera with which to observe it
    _camera = _world->createObject<OrthoCamera>("MainCam");
    _core->getViewport()->registerResizeListener(_camera);
	_camera->setZoom(0.1f);

	// Set up the user interface
	_ui = new UIManager();
	// Note: I don't like that this has to be done manually
	_core->getViewport()->registerResizeListener(_ui);

	// DEBUG
	// Add some test UIElements
	_ui->addNode(UIElement::Text(Vector2(-0.5f, -0.5f), "TEST Text!", "acknowledge.ttf"));

	// Update the world and UIManager once with no time to make sure the scene gets populated fully before rendering
	_world->update(0);
	_ui->update();
}

void PlayingState::teardown() {
    Info("Tearing down PlayingState");
    WorldManager::Unload(_world);

    delete _ui;
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
