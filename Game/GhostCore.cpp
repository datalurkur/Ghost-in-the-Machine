#include <Game/GhostCore.h>
#include <Game/StartingState.h>
#include <Game/GameState.h>

#include <Resource/WorldManager.h>
#include <Resource/TTFManager.h>
#include <Resource/TextureManager.h>
#include <Resource/ShaderManager.h>
#include <Resource/MaterialManager.h>

#include <Render/GLHelper.h>

GhostCore::GhostCore(): _state(Starting) {
    CheckGLErrors();
    setup();
}

GhostCore::~GhostCore() {
    teardown();
}

void GhostCore::setup() {
    CheckGLErrors();
    WorldManager::Setup();
    TTFManager::Setup();
    TextureManager::Setup();
    ShaderManager::Setup();
    MaterialManager::Setup();
    CheckGLErrors();
}

void GhostCore::teardown() {
    //Core::teardown();

    WorldManager::Teardown();
    TTFManager::Teardown();
    TextureManager::Teardown();
    ShaderManager::Teardown();
    MaterialManager::Teardown();
}

bool GhostCore::keyDown(KeyboardEvent *event) {
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

bool GhostCore::update(int elapsed) {
    if(ParentState::update(elapsed)) { return true; }

    switch(_state) {
    case Starting:
        pushState(new StartingState());
        _state = Established;
        break;
    case Established:
        pushState(new GameState());
        _state = Running;
        break;
    case Running:
        Info("GhostCore has no behavior for when GameState is popped!");
        break;
    default:
        return false;
    };

    return true;
}