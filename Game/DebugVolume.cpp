#include <Game/DebugVolume.h>

#include <Resource/MaterialManager.h>

const std::string DebugVolume::NodeType = "DebugVolume";

DebugVolume::DebugVolume(const std::string &name):
	SceneNode<float>(name, NodeType)
{
    recreateRenderables();
}

DebugVolume::~DebugVolume() {
}

void DebugVolume::recreateRenderables() {
    clearRenderables();
    addRenderable(Renderable::Sprite(Vector2<float>(_position.x, _position.y), Vector2<float>(_dimensions.x, _dimensions.y), MaterialManager::Get("debug")));
}