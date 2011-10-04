#include <Resource/ThreadedWorldFactory.h>

int ThreadedWorldFactory::ThreadedLoad(void *data) {
    World *world = (World*)data;

    UpdateStatus(world, "Creating Player");
    world->_player = new Player("derpus");
    world->_scene->addNode(world->_player);

	Finish(world);

    return 1;
}
