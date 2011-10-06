#include <GitM/Player.h>

#include <Resource/MaterialManager.h>
#include <Resource/TextureManager.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name): Entity(name, NodeType) {
    addRenderable(Renderable::Sprite(0.0, 0.0, 1.0, 1.0, 0, MaterialManager::Get("playerMaterial")));
}

Player::~Player() {
}