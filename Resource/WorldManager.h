#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include <GitM/World.h>
#include <Resource/ThreadedResourceManager.h>

class WorldManager;

class WorldManager: public ThreadedResourceManager<World, WorldManager> {
protected:
    static void DoLoad(const std::string &name, World *world);
    
    friend class ThreadedResourceManager<World, WorldManager>;
};

#endif
