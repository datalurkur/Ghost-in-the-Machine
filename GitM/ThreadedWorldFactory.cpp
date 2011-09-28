#include <GitM/ThreadedWorldFactory.h>

int ThreadedWorldFactory::ThreadedLoad(void *data) {
    Info("Beginning Threaded Load");
    World *world = (World*)data;

    UpdateStatus(world, "Creating Player");
    world->_player = new Player("derpus");
    sleep(5);
    
    UpdateStatus(world, "Adding Player To Scene");
    world->_scene->addNode(world->_player);
    sleep(5);

    UpdateStatus(world, "Doing stuff");
    sleep(5);

    Done(world);

    return 1;
}
