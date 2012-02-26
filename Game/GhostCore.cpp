#include <Game/GhostCore.h>
#include <Game/StartingState.h>

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

    pushState(new StartingState());
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