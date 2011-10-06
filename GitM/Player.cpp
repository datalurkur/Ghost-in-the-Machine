#include <GitM/Player.h>

#include <Resource/MaterialManager.h>
#include <Resource/TextureManager.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name): Entity(name, NodeType) {
    addRenderable(Renderable::Sprite(0.0, 0.0, 1.0, 1.0, 0, MaterialManager::Get("playerMaterial")));
}

Player::~Player() {
}

void Player::moveLeft() {
    moveRelative(Vector2(-0.1, 0.0));
}

void Player::moveRight() {
    moveRelative(Vector2(0.1, 0.0));
}

void Player::moveUp() {
    moveRelative(Vector2(0.0, 0.1));
}

void Player::moveDown() {
    moveRelative(Vector2(0.0, -0.1));
}