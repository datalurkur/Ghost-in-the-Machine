#include <Resource/WorldManager.h>
#include <Base/Vector2.h>
#include <GitM/Platform.h>
#include <GitM/Wall.h>

void WorldManager::DoLoad(const std::string &name, World *world) {
    UpdateStatus(world, "Creating Player");

    world->_player = Player::DefaultPlayer(); //new Player("herpus");
    world->_player->setPosition(0.5f, 2.0f);
    world->addEntity(world->_player);

	Platform *platform = new Platform("platform01");
	platform->setPosition(0.0f, -2.0f);
	platform->setDimensions(5.0f, 1.0f);
	world->addEntity(platform);

	/*platform = new Platform("platform02");
	platform->setPosition(-4.5, 2.5);
	platform->setDimensions(1, 5);
	world->addEntity(platform);

	platform = new Platform("platform03");
	platform->setPosition(4.5, 2.5);
	platform->setDimensions(1, 5);
	world->addEntity(platform);
    */
    Wall *wallSegment = new Wall("wall01");
    Vector2 verts[4] = {
        Vector2(10.0f, -5.0f),
        Vector2(5.0f, -7.0f),
        Vector2(-5.0f, -7.0f),
        Vector2(-10.0f, -5.0f)
    };
    wallSegment->setVerts(verts, 4);
    wallSegment->recreateRenderables();
    world->addEntity(wallSegment);
}
