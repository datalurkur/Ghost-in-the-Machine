#include <GitM/GhostCore.h>
#include <GitM/GameState.h>

#include <GitM/ThreadedWorldFactory.h>

GhostCore::GhostCore() {
    std::string mapName = "test_world.wld";
    pushState(new GameState(), &mapName);
    
    ThreadedWorldFactory::Setup();
}

GhostCore::~GhostCore() {
    ThreadedWorldFactory::Teardown();
}
