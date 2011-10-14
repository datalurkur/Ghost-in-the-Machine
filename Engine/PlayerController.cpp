#include <Engine/PlayerController.h>
#include <GitM/Player.h>

PlayerController::PlayerController(Player *player):
	Controller(player), _player(player), _canJump(true)
{
}

void PlayerController::update(int elapsed) {
	b2Body *playerBody = _player->_pController->getBody();
	switch(_movementDirection) {
		case Left: {
			b2Vec2 v = playerBody->GetLinearVelocity();
			v.x -= _player->_speed * elapsed;
			playerBody->SetLinearVelocity(v);
		} break;
		case Right: {
			b2Vec2 v = playerBody->GetLinearVelocity();
			v.x += _player->_speed * elapsed;
			playerBody->SetLinearVelocity(v);
		} break;
		default: {
		} break;
	};
}

void PlayerController::setMovementDirection(PlayerController::Direction dir) {
	_movementDirection = dir;
}

PlayerController::Direction PlayerController::getMovementDirection() const {
	return _movementDirection;
}

void PlayerController::jump() {
}