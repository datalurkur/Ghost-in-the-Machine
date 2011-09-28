#ifndef THREADEDWORLDFACTORY_H
#define THREADEDWORLDFACTORY_H

#include <GitM/World.h>
#include <GitM/ThreadedFactory.h>

class ThreadedWorldFactory: public ThreadedFactory<World> {
    static int ThreadedLoad(void *data);
};

#endif
