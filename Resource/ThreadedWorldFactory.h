#ifndef THREADEDWORLDFACTORY_H
#define THREADEDWORLDFACTORY_H

#include <GitM/World.h>
#include <Resource/ThreadedFactory.h>

class ThreadedWorldFactory;

class ThreadedWorldFactory: public ThreadedFactory<World, ThreadedWorldFactory> {
protected:
    static int ThreadedLoad(void *data);
    
    friend class ThreadedFactory<World, ThreadedWorldFactory>;
};

#endif
