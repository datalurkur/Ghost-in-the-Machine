#include <Game/DebugVolume.h>

#include <Resource/ShaderManager.h>

const std::string DebugVolume::NodeType = "DebugVolume";

DebugVolume::DebugVolume(const std::string &name):
	SceneNode(name, NodeType)
{
    recreateRenderables();
}

DebugVolume::~DebugVolume() {
}

void DebugVolume::recreateRenderables() {
    clearRenderables();
    addRenderable(Renderable::Sprite(Vector2(_position.x, _position.y), Vector2(_dimensions.x, _dimensions.y), 0, ShaderManager::Get("debug")));
}