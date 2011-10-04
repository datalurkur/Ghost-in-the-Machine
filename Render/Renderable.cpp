#include <Render/Renderable.h>

Renderable::Renderable():
	_viewMatrix(Matrix4::Identity), _material(0),
	_indexPointer(0), _numIndices(0),
	_vertexPointer(0), _vertSize(3),
	_texCoordPointer(0), _texCoordSize(2),
	_normalPointer(0),
	_drawMode(GL_QUADS)
{
}

Renderable::~Renderable() {
	if(_indexPointer) { free(_indexPointer); }
	if(_vertexPointer) { free(_vertexPointer); }
	if(_texCoordPointer) { free(_texCoordPointer); }
	if(_normalPointer) { free(_normalPointer); }
}

void Renderable::setViewMatrix(const Matrix4 &matrix) {
	_viewMatrix = matrix;
}

const Matrix4& Renderable::getViewMatrix() const {
	return _viewMatrix;
}

void Renderable::setVertexPointer(float *vertexPointer, const unsigned int numVerts, const unsigned int vertSize) {
	size_t byteSize = numVerts * vertSize * sizeof(float);
	_vertexPointer = (float*)malloc(byteSize);
	memcpy(_vertexPointer, vertexPointer, byteSize);
	_vertSize = vertSize;
}

void Renderable::setTexCoordPointer(float *texCoordPointer, const unsigned int numTexCoords, const unsigned int texCoordSize) {
	size_t byteSize = numTexCoords * texCoordSize * sizeof(float);
	_texCoordPointer = (float*)malloc(byteSize);
	memcpy(_texCoordPointer, texCoordPointer, byteSize);
	_texCoordSize = texCoordSize;
}

void Renderable::setNormalPointer(float *normalPointer, const unsigned int numNormals) {
	size_t byteSize = numNormals * 3 * sizeof(float);
	_normalPointer = (float*)malloc(byteSize);
	memcpy(_normalPointer, normalPointer, byteSize);
}

void Renderable::setIndexPointer(unsigned int *indexPointer, const unsigned int numIndices) {
	size_t byteSize = numIndices * sizeof(unsigned int);
	_indexPointer = (unsigned int *)malloc(byteSize);
	memcpy(_indexPointer, indexPointer, byteSize);
	_numIndices = numIndices;
}

void Renderable::setMaterial(Material *material) {
	_material = material;
}

void Renderable::render() {
	if(_material) {
		_material->enable();
	}

	if(_indexPointer) {
		if(_vertexPointer) {
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(_vertSize, GL_FLOAT, 0, _vertexPointer);
		}

		if(_texCoordPointer) {
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(_texCoordSize, GL_FLOAT, 0, _texCoordPointer);
		}

		if(_normalPointer) {
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, 0, _normalPointer);
		}
		glDrawElements(_drawMode, _numIndices, GL_UNSIGNED_INT, _indexPointer);
	}
}

Renderable* Renderable::OrthoBox(const float x, const float y, const float w, const float h, const float z, bool texCoords, bool normals) {
	Renderable *renderable = new Renderable();
	renderable->setViewMatrix(Matrix4::MakeTranslation(x, y, z));

	float verts[4 * 3] = {
		0, 0, 0,
		w, 0, 0,
		w, h, 0,
		0, h, 0
	};
	renderable->setVertexPointer(&verts[0], 4, 3);

	if(texCoords) {
		float texCoords[4 * 2] = {
			0, 0,
			1, 0,
			1, 1,
			0, 1
		};
		renderable->setTexCoordPointer(&texCoords[0], 4, 2);
	}

	if(normals) {
		float normals[4 * 3] = {
			0, 0, 1,
			0, 0, 1,
			0, 0, 1,
			0, 0, 1
		};
		renderable->setNormalPointer(&normals[0], 4);
	}

	unsigned int indices[4] = { 0, 1, 2, 3 };
	renderable->setIndexPointer(&indices[0], 4);

	return renderable;
}