#include <GitM/Player.h>

#include <Engine/PhysicsEngine.h>
#include <Resource/MaterialManager.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name):
	Entity(name, NodeType), _speed(100.0)
{
    recreateRenderables();
}

Player::~Player() {
}

void Player::moveLeft() {
	_pController->getBody()->ApplyForceToCenter(b2Vec2(-_speed, 0));
}

void Player::moveRight() {
	_pController->getBody()->ApplyForceToCenter(b2Vec2(_speed, 0));
}

void Player::moveUp() {
	_pController->getBody()->ApplyForceToCenter(b2Vec2(0, _speed*10));
}

void Player::moveDown() {
	_pController->getBody()->ApplyForceToCenter(b2Vec2(0, -_speed*10));
}

void Player::recreateRenderables() {
    clearRenderables();
    addRenderable(Renderable::Sprite(_position, Vector2(1.0, 1.0), 0, MaterialManager::Get("playerMaterial")));
}

void Player::setupPhysics(PhysicsEngine *physics) {
    addController(physics);
    recreatePhysicsBody();
}

void Player::recreatePhysicsBody() {
    PhysicsEngine *engine = _pController->getEngine();
    _pController->setBody(engine->createDynamicBox(_position, Vector2(1.0, 1.0), 1.0, 0.3, false));
}