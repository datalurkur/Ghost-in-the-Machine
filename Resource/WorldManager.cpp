#include <Resource/WorldManager.h>

int WorldManager::ThreadedLoad(void *data) {
    ResourceThreadParams *params = (ResourceThreadParams*)data;

    World *world = (World*)params->ptr;
	std::string name = params->name;

    UpdateStatus(world, "Creating Player");
    world->_player = new Player("derpus");
    world->_scene->addNode(world->_player);

	Finish(world);

    return 1;
}
