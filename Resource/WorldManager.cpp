#include <Resource/WorldManager.h>

void WorldManager::DoLoad(const std::string &name, World *world) {
    UpdateStatus(world, "Creating Player");
    world->_player = new Player("derpus");
    world->_scene->addNode(world->_player);
}
