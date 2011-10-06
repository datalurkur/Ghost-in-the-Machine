#include <GitM/GhostCore.h>
#include <GitM/GameState.h>

#include <Resource/WorldManager.h>
#include <Resource/TTFManager.h>
#include <Resource/TextureManager.h>
#include <Resource/MaterialManager.h>

GhostCore::GhostCore() {
    WorldManager::Setup();
    TTFManager::Setup();
    TextureManager::Setup();
    MaterialManager::Setup();

	// TEMP
	//TextureManager::Load("C:/GitM/grass.png");
	// FIXME - Add loading of resources based on directories

    std::string mapName = "test_world";
    pushState(new GameState(), &mapName);
}

GhostCore::~GhostCore() {
    WorldManager::Teardown();
    TTFManager::Teardown();
    TextureManager::Teardown();
    MaterialManager::Teardown();
}
