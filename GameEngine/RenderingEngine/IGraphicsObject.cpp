#include "IGraphicsObject.h"
#include "../GameplayEngine/IWorldObject.h"


IGraphicsObject::IGraphicsObject() {
}

IGraphicsObject::~IGraphicsObject() {
}

void IGraphicsObject::SetDevice(void* dev) {
	device = dev;
}

void * IGraphicsObject::GetMaterial()
{
	return mesh_material;
}

void * IGraphicsObject::GetMesh()
{
	return mesh;
}

void * IGraphicsObject::GetTexture()
{
	return mesh_texture;
}

int IGraphicsObject::GetNum()
{
	return numMat;
}

IWorldObject* IGraphicsObject::GetParent() {
	return parent;
}
