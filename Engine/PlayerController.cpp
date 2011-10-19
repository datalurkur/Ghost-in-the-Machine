#include <Engine/PlayerController.h>
#include <GitM/Player.h>

PlayerController::PlayerController(Player *player):
	Controller(player), _player(player), _movementDirection(None),
    _jumpSensorContacts(0), _extraJumps(0)
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
			if(isTouchingGround()) {
			}
		} break;
	};
}

bool PlayerController::isTouchingGround() {
	return (_jumpSensorContacts > 0);
}

void PlayerController::setMovementDirection(PlayerController::Direction dir) {
	_movementDirection = dir;
}

PlayerController::Direction PlayerController::getMovementDirection() const {
	return _movementDirection;
}

void PlayerController::jump() {
	if(isTouchingGround()) {
		b2Body *playerBody = _player->_physicsController->getBody();
		playerBody->ApplyLinearImpulse(b2Vec2(0.0f, _player->_jumpPower), playerBody->GetWorldCenter());
	}
}

void PlayerController::contactBegins(Entity *a, Entity *b) {
}

void PlayerController::contactBegins(FixtureID *trigger, FixtureID *other) {
	// For now, assume the player can jump off of anything
	if(trigger == &Player::JumpSensor) {
		_jumpSensorContacts++;
	}
}

void PlayerController::contactEnds(Entity *a, Entity *b) {
}

void PlayerController::contactEnds(FixtureID *trigger, FixtureID *other) {
	// For now, assume the player can jump off of anything
	if(trigger == &Player::JumpSensor) {
		_jumpSensorContacts--;
	}
}