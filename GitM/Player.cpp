#include <GitM/Player.h>

#include <Engine/PhysicsEngine.h>
#include <Resource/MaterialManager.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name):
	Entity(name, NodeType), _speed(0.1),
	_height(1.0), _width(1.0), _playerController(0)
{
    recreateRenderables();
	addController(this);
}

Player::~Player() {
}
/*
PlayerController::Direction Player::getMovementDirection() const {
	return _playerController->getMovementDirection();
}

void Player::setMovementDirection(PlayerController::Direction dir) {
	_playerController->setMovementDirection(dir);
}

void Player::jump() {
}
*/
void Player::recreateRenderables() {
    clearRenderables();
    addRenderable(Renderable::Sprite(_position, Vector2(_width, _height), 0, MaterialManager::Get("playerMaterial")));
}

void Player::setupPhysics(PhysicsEngine *physics) {
    addController(physics);
    recreatePhysicsBody();
}

void Player::recreatePhysicsBody() {
    PhysicsEngine *engine = _pController->getEngine();
	b2Body *body = engine->createDynamicBox(_position, Vector2(_width, _height), 1.0, 0.3, false);

	// Add the jump sensor
	b2PolygonShape shape;
	b2FixtureDef sensorDef;
	float sensorHeight = 0.1;

	shape.SetAsBox(_width, sensorHeight, b2Vec2(_position.x, _position.y - ((_height + sensorHeight) / 2.0)), 0);
	sensorDef.isSensor = true;
	sensorDef.shape = &shape;
	body->CreateFixture(&sensorDef);

    _pController->setBody(body);
}

void Player::setPlayerController(PlayerController *controller) {
	_playerController = controller;
}

PlayerController *Player::getPlayerController() const {
	return _playerController;
}