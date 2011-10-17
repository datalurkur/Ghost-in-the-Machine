#include <Engine/PlayerController.h>
#include <GitM/Player.h>

PlayerController::PlayerController(Player *player):
	Controller(player), _player(player), _movementDirection(None),
    _jumpBoxContacts(0), _extraJumps(0)
{}

void PlayerController::update(int elapsed) {
	b2Body *playerBody = _player->_physicsController->getBody();
	switch(_movementDirection) {
		case Left: {
			b2Vec2 v = playerBody->GetLinearVelocity();
			v.x -= _player->_accel * elapsed;
			if(v.x < -_player->_maxSpeed) { v.x = -_player->_maxSpeed; }
			playerBody->SetLinearVelocity(v);
		} break;
		case Right: {
			b2Vec2 v = playerBody->GetLinearVelocity();
			v.x += _player->_accel * elapsed;
			if(v.x > _player->_maxSpeed) { v.x = _player->_maxSpeed; }
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
	if(_jumpBoxContacts > 0) {
		b2Body *playerBody = _player->_physicsController->getBody();
		playerBody->ApplyLinearImpulse(b2Vec2(0.0f, _player->_jumpPower), playerBody->GetWorldCenter());
	}
}

void PlayerController::contactBegins(Entity *a, Entity *b) {
}

void PlayerController::contactBegins(FixtureID *a) {
	// For now, assume the player can jump off of anything
	if(a == &Player::JumpSensor) {
		_jumpBoxContacts++;
	}
}

void PlayerController::contactEnds(Entity *a, Entity *b) {
}

void PlayerController::contactEnds(FixtureID *a) {
	// For now, assume the player can jump off of anything
	if(a == &Player::JumpSensor) {
		_jumpBoxContacts--;
	}
}