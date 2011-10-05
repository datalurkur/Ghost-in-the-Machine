#include <GitM/GhostCore.h>
#include <GitM/GameState.h>

#include <Resource/WorldManager.h>
#include <Resource/TTFManager.h>
#include <Resource/TextureManager.h>

GhostCore::GhostCore() {
    WorldManager::Setup();
    TTFManager::Setup();
    TextureManager::Setup();

    std::string mapName = "test_world";
    pushState(new GameState(), &mapName);
}

GhostCore::~GhostCore() {
    WorldManager::Teardown();
    TTFManager::Teardown();
    TextureManager::Teardown();
}
