#include <Game/Terrain.h>
#include <Resource/MaterialManager.h>

const std::string Terrain::NodeType = "Terrain";

Terrain::Terrain(const Vector2 &dims): SceneNode("terrain", NodeType) {
	setDimensions(dims);
	_tileData = (TerrainType*)calloc((size_t)(getDimensions().arraySize()), sizeof(TerrainType));
	populateScene();
}

Terrain::~Terrain() {
	free(_tileData);
}

void Terrain::populateScene() {
	Vector2 dims = getDimensions();

	Renderable *tRend = new Renderable();
	
	float verts[12] = {
		0,      0,      0,
		dims.x, 0,      0,
		dims.x, dims.y, 0,
		0,      dims.y, 0
	};
	unsigned int indices[4] = { 0, 1, 2, 3 };

	tRend->setVertexPointer(&verts[0], 4, 3);
	tRend->setIndexPointer(&indices[0], 4);
	tRend->setMaterial(MaterialManager::Get("debug"));

	addRenderable(tRend);
}