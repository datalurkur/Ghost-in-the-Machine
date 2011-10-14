#include <Resource/WorldManager.h>
#include <Base/Vector2.h>
#include <GitM/Platform.h>

void WorldManager::DoLoad(const std::string &name, World *world) {
    UpdateStatus(world, "Creating Player");

    world->_player = new Player("herpus");
    world->_player->setPosition(0.5, 2);
    world->addEntity(world->_player);

	Platform *platform = new Platform("platform01");
	platform->setPosition(0, -0.5);
	platform->setDimensions(10, 1);
	world->addEntity(platform);

	platform = new Platform("platform02");
	platform->setPosition(-4.5, 2.5);
	platform->setDimensions(1, 5);
	world->addEntity(platform);

	platform = new Platform("platform03");
	platform->setPosition(4.5, 2.5);
	platform->setDimensions(1, 5);
	world->addEntity(platform);
}
