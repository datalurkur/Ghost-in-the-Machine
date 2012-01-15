#include <Game/Terrain.h>
#include <Resource/MaterialManager.h>

#define TILE(i,j) _tileData[((j) * (int)dims.x) + (i)]
#define FLAGS(i,j) _faceFlags[((j) * (int)dims.x) + (i)]

const std::string Terrain::NodeType = "Terrain";

Terrain::Terrain(const Vector2 &dims): SceneNode("Terrain", NodeType) {
	setDimensions(Vector3(dims.x, dims.y, 5.0f));
	generateMap();
	populateScene();
}

Terrain::~Terrain() {
	free(_tileData);
}

/*
Terrain::TerrainType Terrain::getType(int x, int y) const {
	return (TerrainType)_tileData[(x * (int)getDimensions().y) + y];
}

Terrain::FaceFlags Terrain::getFlags(int x, int y) const {
	return (FaceFlags)_faceFlags[(x * (int)getDimensions().y) + y];
}
*/

void Terrain::generateMap() {
	Vector3 dims = getDimensions();

	_tileData = (TerrainType*)calloc((size_t)(dims.x * dims.y), sizeof(TerrainType));
	_faceFlags = (unsigned char*)calloc((size_t)(dims.x * dims.y), sizeof(unsigned char));

	// For now, just seed the map randomly
	for(int i=0; i < dims.x; i++) {
		for(int j=0; j < dims.y; j++) {
			TILE(i,j) = (TerrainType)(rand() % NUM_TILE_TYPES);
		}
	}

	regenFaceFlags();
}

void Terrain::regenFaceFlags() {
	int i, j;
	Vector3 dims;

	dims = getDimensions();

	for(i=0; i<dims.x; i++) {
		for(j=0; j<dims.y; j++) {
			FLAGS(i,j) = 0;
			if(TILE(i,j) == EMPTY) {
				FLAGS(i,j) |= BOTTOM;
			} else {
				FLAGS(i,j) |= TOP;
				if(i == 0          || TILE(i-1, j) == EMPTY) { FLAGS(i,j) |= WEST;  }
				if(j == 0          || TILE(i, j-1) == EMPTY) { FLAGS(i,j) |= SOUTH; }
				if(i == (dims.x-1) || TILE(i+1, j) == EMPTY) { FLAGS(i,j) |= EAST;  }
				if(j == (dims.y-1) || TILE(i, j+1) == EMPTY) { FLAGS(i,j) |= NORTH; }
			}
		}
	}
}

void Terrain::populateScene() {
	Vector3 dims;
	Renderable *topRenderable, *bottomRenderable, *wallRenderable;
	int vertexSize, layers, vertsPerLayer, totalVerts,
		i, j;
	float *verts;
	std::vector<unsigned int> bottomIndices;
	std::vector<unsigned int> topIndices;
	std::vector<unsigned int> wallIndices;

	dims = getDimensions();

	layers		  = 2;
	vertexSize	  = 3;
	vertsPerLayer = ((int)dims.x + 1) * ((int)dims.y + 1);
	totalVerts    = vertsPerLayer * layers;

	// Allocate memory for all the vertices
	verts = (float*)calloc(totalVerts * vertexSize, sizeof(float));

#define INDEX(i,j,k) (((k) * vertsPerLayer) + ((j) * ((int)dims.x+1)) + (i))

	// Define all the vertices, both upper and lower
	// TODO - lots of redundant verts generated here, consider optimising
	for(i=0; i<=dims.x; i++) {
		for(j=0; j<=dims.y; j++) {
			float *top, *bottom;
			top    = &verts[(INDEX(i,j,1)*3)];
			bottom = &verts[(INDEX(i,j,0)*3)];
			top[0] = (float)i;
			top[1] = (float)j;
			top[2] = 0.1f;
			bottom[0] = (float)i;
			bottom[1] = (float)j;
			bottom[2] = 0.0f;
		}
	}

	for(i=0; i<dims.x; i++) {
		for(j=0; j<dims.y; j++) {
			unsigned char flags = FLAGS(i,j);
			if(flags & BOTTOM) {
				bottomIndices.push_back(INDEX(i,  j,  0));
				bottomIndices.push_back(INDEX(i+1,j,  0));
				bottomIndices.push_back(INDEX(i+1,j+1,0));
				bottomIndices.push_back(INDEX(i,  j+1,0));
			} else {
				topIndices.push_back(INDEX(i,  j,  1));
				topIndices.push_back(INDEX(i+1,j,  1));
				topIndices.push_back(INDEX(i+1,j+1,1));
				topIndices.push_back(INDEX(i,  j+1,1));
				
				if(flags & EAST) {
					wallIndices.push_back(INDEX(i+1,j,  1));
					wallIndices.push_back(INDEX(i+1,j,  0));
					wallIndices.push_back(INDEX(i+1,j+1,0));
					wallIndices.push_back(INDEX(i+1,j+1,1));
				}
				if(flags & WEST) {
					wallIndices.push_back(INDEX(i,j,  0));
					wallIndices.push_back(INDEX(i,j,  1));
					wallIndices.push_back(INDEX(i,j+1,1));
					wallIndices.push_back(INDEX(i,j+1,0));
				}
				if(flags & SOUTH) {
					wallIndices.push_back(INDEX(i  ,j,0));
					wallIndices.push_back(INDEX(i  ,j,1));
					wallIndices.push_back(INDEX(i+1,j,1));
					wallIndices.push_back(INDEX(i+1,j,0));
				}
				if(flags & NORTH) {
					wallIndices.push_back(INDEX(i  ,j+1,1));
					wallIndices.push_back(INDEX(i  ,j+1,0));
					wallIndices.push_back(INDEX(i+1,j+1,0));
					wallIndices.push_back(INDEX(i+1,j+1,1));
				}
			}
		}
	}

	clearRenderables();

	bottomRenderable = new Renderable();
	bottomRenderable->setVertexPointer(&verts[0], totalVerts, 3);
	bottomRenderable->setIndexPointer(&bottomIndices[0], bottomIndices.size());
	bottomRenderable->setMaterial(MaterialManager::Get("grass"));
	addRenderable(bottomRenderable);
	topRenderable = new Renderable();
	topRenderable->setVertexPointer(&verts[0], totalVerts, 3);
	topRenderable->setIndexPointer(&topIndices[0], topIndices.size());
	topRenderable->setMaterial(MaterialManager::Get("roof"));
	addRenderable(topRenderable);
	wallRenderable = new Renderable();
	wallRenderable->setVertexPointer(&verts[0], totalVerts, 3);
	wallRenderable->setIndexPointer(&wallIndices[0], wallIndices.size());
	wallRenderable->setMaterial(MaterialManager::Get("wall"));
	addRenderable(wallRenderable);

	free(verts);

#undef INDEX
}

#undef TILE
#undef FLAGS