#include <GitM/GhostCore.h>
#include <GitM/GameState.h>

#include <Resource/ThreadedWorldFactory.h>

GhostCore::GhostCore() {
    ThreadedWorldFactory::Setup();

    std::string mapName = "test_world";
    pushState(new GameState(), &mapName);
}

GhostCore::~GhostCore() {
    ThreadedWorldFactory::Teardown();
}
