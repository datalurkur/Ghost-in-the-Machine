#include <Game/PlayerController.h>
#include <Game/Player.h>

PlayerController::PlayerController(Player *player):
	Controller(player), _player(player), _movementDirection(None),
    _jumpSensorContacts(0), _extraJumpsLeft(0)
{}

void PlayerController::update(int elapsed) {
	b2Body *playerBody = _player->_physicsController->getBody();
	b2Vec2 v = playerBody->GetLinearVelocity();

	switch(_movementDirection) {
		case Left: {
			v.x -= _player->_accel * elapsed;
		} break;
		case Right: {
			v.x += _player->_accel * elapsed;
		} break;
		default: {
			if(isTouchingGround()) {
				// When jumping from a stationary position, the player sleeps before the jump sensor loses contact
				//playerBody->SetAwake(false);
			}
		} break;
	};

	if(v.x < -_player->_maxSpeed) { v.x = -_player->_maxSpeed; }
	if(v.x > _player->_maxSpeed) { v.x = _player->_maxSpeed; }
	playerBody->SetLinearVelocity(v);
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
	if(!isTouchingGround() && _extraJumpsLeft == 0) { return; }
	if(!isTouchingGround()) { _extraJumpsLeft--; }

	b2Body *playerBody = _player->_physicsController->getBody();
	b2Vec2 v = playerBody->GetLinearVelocity();
	v.y = _player->_jumpSpeed;
	playerBody->SetLinearVelocity(v);
}

void PlayerController::contactBegins(Entity *a, Entity *b) {
}

void PlayerController::contactBegins(FixtureID *trigger, FixtureID *other) {
	// For now, assume the player can jump off of anything
	if(trigger == &Player::JumpSensor) {
		_jumpSensorContacts++;
		_extraJumpsLeft = _player->_extraJumps;
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

template <>
PlayerController* Entity::addController<PlayerController,Player>(Player* player) {
    PlayerController *p = new PlayerController(player);
    _controllers.push_back(p);
    return p;
}