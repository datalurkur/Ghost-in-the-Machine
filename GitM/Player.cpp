#include <GitM/Player.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name): Entity(name, NodeType) {
}

Player::~Player() {
}