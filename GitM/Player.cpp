#include <GitM/Player.h>

#include <Resource/MaterialManager.h>
#include <Resource/TextureManager.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name): Entity(name, NodeType) {
    // FIXME - The player should just Get a material, rather than loading it here
    Material *playerMaterial = new Material();
    playerMaterial->setTexture(TextureManager::Load("/Users/ajean/personal/GitM/OSX/beach_ball.png"));
    MaterialManager::Register("playermaterial", playerMaterial);
    addRenderable(Renderable::Sprite(0, 0, 1.0, 1.0, 0, playerMaterial));
}

Player::~Player() {
}