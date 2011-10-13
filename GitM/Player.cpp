#include <GitM/Player.h>

#include <Engine/PhysicsEngine.h>
#include <Resource/MaterialManager.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name):
Entity(name, NodeType)
{
    recreateRenderables();
}

Player::Player(const std::string &name, va_list args):
    Entity(name, NodeType)
{
    _position = *va_arg(args, Vector2*);
    recreateRenderables();
}

Player::~Player() {
}

void Player::moveLeft() {
}

void Player::moveRight() {
}

void Player::moveUp() {
}

void Player::moveDown() {
}

void Player::recreateRenderables() {
    clearRenderables();
    addRenderable(Renderable::Sprite(_position.x, _position.y, 1.0, 1.0, 0, MaterialManager::Get("playerMaterial")));
}

void Player::setupPhysics(PhysicsEngine *physics) {
    addController(physics);
    recreatePhysicsBody();
}

void Player::recreatePhysicsBody() {
    PhysicsEngine *engine = _pController->getEngine();
    _pController->setBody(engine->createDynamicBox(_position, Vector2(1.0, 1.0), 1.0, 0.3, false));
}