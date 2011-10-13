#include <Resource/WorldManager.h>
#include <Base/Vector2.h>
#include <GitM/Platform.h>

void WorldManager::DoLoad(const std::string &name, World *world) {
    UpdateStatus(world, "Creating Player");

    Vector2 platformPosition(0, 0), platformDimension(10, 1);
    Player *player = new Player("herpus");
    player->setPosition(5, 3);
    world->addEntity(player);

    world->createEntity<Platform>("Platform01", &platformPosition, &platformDimension);

}
