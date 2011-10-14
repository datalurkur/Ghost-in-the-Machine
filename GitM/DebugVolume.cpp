#include <GitM/DebugVolume.h>

#include <Resource/MaterialManager.h>

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
    addRenderable(Renderable::Sprite(_position, _dimensions, 0, MaterialManager::Get("debugMaterial")));
}