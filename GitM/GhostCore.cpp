#include <GitM/GhostCore.h>
#include <GitM/GameState.h>

#include <Resource/WorldManager.h>
#include <Resource/TTFManager.h>
#include <Resource/TextureManager.h>
#include <Resource/MaterialManager.h>

GhostCore::GhostCore() {
    setup();
}

GhostCore::~GhostCore() {
    teardown();
}

void GhostCore::setup() {
    WorldManager::Setup();
    TTFManager::Setup();
    TextureManager::Setup();
    MaterialManager::Setup();
    
	// TEMP
	Texture *playerTexture = TextureManager::Load("grass.png");
    Material *playerMaterial = new Material();
    playerMaterial->setTexture(playerTexture);
    MaterialManager::Register("playerMaterial", playerMaterial);

	Material *debugMaterial = new Material();
	debugMaterial->setColor(1.0f, 1.0f, 1.0f, 0.5f);
	MaterialManager::Register("debugMaterial", debugMaterial);
    
    std::string mapName = "test_world";
    pushState(new GameState(), &mapName);
}

void GhostCore::teardown() {
    Core::teardown();

    WorldManager::Teardown();
    TTFManager::Teardown();
    TextureManager::Teardown();
    MaterialManager::Teardown();
}

void GhostCore::keyDown(KeyboardEvent *event) {
    switch(event->key()) {
        case KeyboardEvent::KEY_F1: {
            stop();
        } break;
        default: {
            Core::keyDown(event);
        } break;
    };
}