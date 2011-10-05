#include <Resource/WorldManager.h>

int WorldManager::ThreadedLoad(void *data) {
    World *world = ((ResourceThreadParams<World>*)data)->ptr;
	std::string name = ((ResourceThreadParams<World>*)data)->name;

    UpdateStatus(world, "Creating Player");
    world->_player = new Player("derpus");
    world->_scene->addNode(world->_player);

	Finish(world);

    return 1;
}
