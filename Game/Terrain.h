#ifndef TERRAIN_H
#define TERRAIN_H

#include <Base/Vector2.h>
#include <Engine/SceneNode.h>

class Terrain: public SceneNode {
public:
	static const std::string NodeType;

public:
	enum TerrainType {
		EMPTY = 0,
		WALL,
		IMPENETRABLE,
		NUM_TILE_TYPES
	};
	enum FaceFlags {
		TOP    = 0x01,
		BOTTOM = 0x02,
		NORTH  = 0x04,
		SOUTH  = 0x08,
		EAST   = 0x10,
		WEST   = 0x20
	};

public:
	Terrain(const Vector2 &dims);
	~Terrain();

	/*
	TerrainType getType(int x, int y) const;
	FaceFlags getFlags(int x, int y) const;
	*/

private:
	void generateMap();
	void regenFaceFlags();
	void populateScene();

private:
	TerrainType *_tileData;
	unsigned char *_faceFlags;
};

#endif