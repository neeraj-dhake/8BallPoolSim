#include "IGraphicsObject.h"
#include "../GameplayEngine/IWorldObject.h"


IGraphicsObject::IGraphicsObject() {
}


IGraphicsObject::~IGraphicsObject() {
}

void IGraphicsObject::SetDevice(void* dev) {
	device = dev;
}

int IGraphicsObject::GetNumPrimitives() {
	return num_primitives;
}

int IGraphicsObject::GetNumVertices() {
	return num_vertices;
}

IWorldObject* IGraphicsObject::GetParent() {
	return parent;
}

void* IGraphicsObject::GetTexture() {
	return texture;
}

void* IGraphicsObject::GetVBuf() {
	return vertex_buffer;
}

void* IGraphicsObject::GetIBuf() {
	return index_buffer;
}

void IGraphicsObject::SetColor(Vector3D col) {
	color = col;
}

Vector3D IGraphicsObject::GetColor() {
	return color;
}