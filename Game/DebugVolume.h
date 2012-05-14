#ifndef DEBUGVOLUME_H
#define DEBUGVOLUME_H

#include <Engine/SceneNode.h>

class DebugVolume: public SceneNode<float> {
public:
	static const std::string NodeType;

public:
    DebugVolume(const std::string &name);
	virtual ~DebugVolume();

    void recreateRenderables();

private:
};

#endif