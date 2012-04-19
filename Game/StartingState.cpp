#include <Engine/ParentState.h>

#include <Resource/TextureManager.h>
#include <Resource/ShaderManager.h>
#include <Resource/MaterialManager.h>
#include <Resource/TTFManager.h>

#include <Game/StartingState.h>
#include <Game/GameState.h>

#include <Base/SDLHelper.h>
#include <Render/GLHelper.h>

StartingState::StartingState() {
}

StartingState::~StartingState() {
}

bool StartingState::update(int elapsed) {
    CheckSDLErrors();
    CheckGLErrors();
    switch(_stage) {
        case Start: {
            Info("Start stage done");
            incrementStage();
        } break;
        case TextureLoading: {
            if((_left = TextureManager::LoadNextFromPath_r(_progress)) == 0) {
                Info("Texture loading stage done");
                incrementStage();
            }
        } break;
        case ShaderLoading: {
            if((_left = ShaderManager::LoadNextFromPath_r(_progress)) == 0) {
                Info("Shader loading stage done");
                incrementStage();
            }
        } break;
        case MaterialLoading: {
            if((_left = MaterialManager::LoadNextFromPath_r(_progress)) == 0) {
                Info("Material loading stage done");
                incrementStage();
            }
        } break;
		case TTFLoading: {
			if((_left = TTFManager::LoadNextFromPath_r(_progress)) == 0) {
				Info("TTF loading stage done");
				incrementStage();
			}
		} break;
        case Done: {
            Info("StartingState is done entirely");
            // FIXME - Move this into a menustate
            _parent->popState();
        }
    };

    return true;
}

bool StartingState::render(RenderContext *renderContext) {
    return true;
}

void StartingState::setup(va_list args) {
    Info("Setting up StartingState");
    _stage = Start;
}

void StartingState::teardown() {
    Info("Tearing down StartingState");
}

void StartingState::incrementStage() {
    _stage++;
    _progress = 0;
}