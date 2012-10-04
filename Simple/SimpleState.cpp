#include <Engine/ParentState.h>

#include <Resource/TextureManager.h>
#include <Resource/ShaderManager.h>
#include <Resource/MaterialManager.h>
#include <Resource/TTFManager.h>

#include <Simple/SimpleWorld.h>
#include <Simple/SimpleState.h>

SimpleState::SimpleState() {
}

SimpleState::~SimpleState() {
}

bool SimpleState::update(int elapsed) {
    switch(_stage) {
        case Start:
            Info("Start stage done");
            incrementStage();
			break;

        case TextureLoading:
            if((_left = TextureManager::LoadNextFromPath_r(_progress)) == 0) {
                Info("Texture loading stage done");
                incrementStage();
            }
			break;

        case ShaderLoading:
            if((_left = ShaderManager::LoadNextFromPath_r(_progress)) == 0) {
                Info("Shader loading stage done");
                incrementStage();
            }
			break;

        case MaterialLoading:
            if((_left = MaterialManager::LoadNextFromPath_r(_progress)) == 0) {
                Info("Material loading stage done");
                incrementStage();
            }
			break;

		case TTFLoading:
			if((_left = TTFManager::LoadNextFromPath_r(_progress)) == 0) {
				Info("TTF loading stage done");
				incrementStage();
			}
			break;

		case WorldSetup:
			_world = new SimpleWorld();
			// Create a camera
			_world->update(0);
			break;

		case Running:
			_world->update(elapsed);
			break;
    };

    return true;
}

bool SimpleState::render(RenderContext *renderContext) {
	switch(_stage) {
	case Running:
		// Call this with a camera
		//_world->render(_camera, renderContext);
		break;
	};

	return true;
}

void SimpleState::setup(va_list args) {
    Info("Setting up SimpleState");
    _stage = Start;
	_world = 0;
}

void SimpleState::teardown() {
    Info("Tearing down SimpleState");
	if(_world) { delete _world; }
}

void SimpleState::incrementStage() {
    _stage++;
    _progress = 0;
}