#include <Simple/SimpleCore.h>
#include <Simple/SimpleState.h>

#include <Resource/WorldManager.h>
#include <Resource/TTFManager.h>
#include <Resource/TextureManager.h>
#include <Resource/ShaderManager.h>
#include <Resource/MaterialManager.h>

#include <Render/GLHelper.h>

SimpleCore::SimpleCore(): _state(Starting) {
    setup();
}

SimpleCore::~SimpleCore() {
    teardown();
}

void SimpleCore::setup() {
    WorldManager::Setup();
    TTFManager::Setup();
    TextureManager::Setup();
    ShaderManager::Setup();
    MaterialManager::Setup();
}

void SimpleCore::teardown() {
    WorldManager::Teardown();
    TTFManager::Teardown();
    TextureManager::Teardown();
    ShaderManager::Teardown();
    MaterialManager::Teardown();
}

bool SimpleCore::keyDown(KeyboardEvent *event) {
    switch(event->key()) {
        case SDLK_F1: {
            stop();
        } break;
        default: {
            Core::keyDown(event);
        } break;
    };

    return true;
}

bool SimpleCore::update(int elapsed) {
    if(ParentState::update(elapsed)) { return true; }

    switch(_state) {
    case Starting:
        pushState(new SimpleState());
        _state = Running;
        break;
    case Running:
        Info("SimpleCore has no behavior for when StartingState is popped!");
        break;
    default:
        return false;
    };

    return true;
}