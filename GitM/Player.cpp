#include <GitM/Player.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name): Entity(name, NodeType) {
    addRenderable(Renderable::Sprite(0, 0, 1.0, 1.0, 0, "/Users/ajean/personal/GitM/OSX/beach_ball.png"));
}

Player::~Player() {
}