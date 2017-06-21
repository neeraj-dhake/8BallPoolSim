#include "IGraphicsObject.h"
#include "../BulletPhysicsEngine/IWorldObject.h"


IGraphicsObject::IGraphicsObject() {
	isConcave = false;
}

IGraphicsObject::~IGraphicsObject() {
}

void IGraphicsObject::SetDevice(void* dev) {
	device = dev;
}

void * IGraphicsObject::GetMaterial() {
	return mesh_material;
}

void* IGraphicsObject::GetMesh() {
	return mesh;
}

void* IGraphicsObject::GetVBuf() {
	return v_buf;
}

void* IGraphicsObject::GetIBuf() {
	return i_buf;
}

int IGraphicsObject::GetNumVertices() {
	return num_vertices;
}

int IGraphicsObject::GetNumPrimitives() {
	return num_primitives;
}

void * IGraphicsObject::GetTexture() {
	return mesh_texture;
}

int IGraphicsObject::GetNum() {
	return numMat;
}

IWorldObject* IGraphicsObject::GetParent() {
	return parent;
}
