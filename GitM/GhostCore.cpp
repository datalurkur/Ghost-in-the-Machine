#include <GitM/GhostCore.h>
#include <GitM/GameState.h>

GhostCore::GhostCore() {
    std::string mapName = "test_world.wld";
    pushState(new GameState(), &mapName);
}

GhostCore::~GhostCore() {
}
