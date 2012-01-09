#ifndef TERRAIN_H
#define TERRAIN_H

#include <Base/Vector2.h>
#include <Engine/SceneNode.h>

class Terrain: public SceneNode {
public:
	static const std::string NodeType;

public:
	Terrain(const Vector2 &dims);
	~Terrain();

public:
	enum TerrainType {
		EMPTY = 0,
		WALL,
		IMPENETRABLE
	};

private:
	void populateScene();

private:
	TerrainType *_tileData;
};

#endif