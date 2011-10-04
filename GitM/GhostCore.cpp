#include <GitM/GhostCore.h>
#include <GitM/GameState.h>

#include <GitM/ThreadedWorldFactory.h>

GhostCore::GhostCore() {
    ThreadedWorldFactory::Setup();

    std::string mapName = "test_world.wld";
    pushState(new GameState(), &mapName);
}

GhostCore::~GhostCore() {
    ThreadedWorldFactory::Teardown();
}
