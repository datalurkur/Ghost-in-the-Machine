#include <Game/SimpleCore.h>
#include <Game/StartingState.h>

#include <Resource/WorldManager.h>
#include <Resource/TTFManager.h>
#include <Resource/TextureManager.h>
#include <Resource/MaterialManager.h>

SimpleCore::SimpleCore() {
    setup();
}

SimpleCore::~SimpleCore() {
    teardown();
}

void SimpleCore::setup() {
    WorldManager::Setup();
    TTFManager::Setup();
    TextureManager::Setup();
    MaterialManager::Setup();

    pushState(new StartingState());
}

void SimpleCore::teardown() {
    Core::teardown();

    WorldManager::Teardown();
    TTFManager::Teardown();
    TextureManager::Teardown();
    MaterialManager::Teardown();
}

void SimpleCore::keyDown(KeyboardEvent *event) {
    switch(event->key()) {
        case KeyboardEvent::KEY_F1: {
            stop();
        } break;
        default: {
            Core::keyDown(event);
        } break;
    };
}