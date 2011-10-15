#include <Engine/PlayerController.h>
#include <GitM/Player.h>

PlayerController::PlayerController(Player *player):
	Controller(player), _player(player), _jumpBoxContacts(0)
{
}

void PlayerController::update(int elapsed) {
	b2Body *playerBody = _player->_physicsController->getBody();
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
	if(_jumpBoxContacts > 0) {
		b2Body *playerBody = _player->_physicsController->getBody();
		b2Vec2 v = playerBody->GetLinearVelocity();
		v.y += _player->_speed * 100;
		playerBody->SetLinearVelocity(v);
		Info("Jumping!");
	} else {
		Info("Can't jump - not touching the ground");
	}
}

void PlayerController::contactBegins(Entity *a, Entity *b) {
}

void PlayerController::contactBegins(FixtureID *a) {
	Info("Contact with player begins (" << _jumpBoxContacts+1 << ")");
	// For now, assume the player can jump off of anything
	if(a == "jumpSensor") {
		_jumpBoxContacts++;
	}
}

void PlayerController::contactEnds(Entity *a, Entity *b) {
}

void PlayerController::contactEnds(FixtureID *a) {
	Info("Contact with player ends (" << _jumpBoxContacts-1 << ")");
	// For now, assume the player can jump off of anything
	if(a == "jumpSensor") {
		_jumpBoxContacts--;
	}
}