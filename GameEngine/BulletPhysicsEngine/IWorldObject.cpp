#include "IWorldObject.h"

IWorldObject::IWorldObject() {
	position = Vector3D(0, 0, 0);
	rotation = Vector3D(0, 0, 0);
}


IWorldObject::~IWorldObject() {
}

Vector3D IWorldObject::GetPos() {
	return position;
}

Vector3D IWorldObject::GetRotation() {
	return rotation;
}

float IWorldObject::GetW() {
	return w;
}

void IWorldObject::SetCoordinates(Vector3D pos) {
	position = pos;
}

void IWorldObject::SetRotation(Vector3D rot) {
	rotation = rot;
}

void IWorldObject::SetW(float ww) {
	w = ww;
}

void IWorldObject::CreateObject(BulletWorld *)
{
	// kept for allowing craetion of abstaract class since can't create class of virtual type
}

btCollisionObject* IWorldObject::GetpObject() {
	return pObject;
}

IGraphicsObject* IWorldObject::GetgObject() {
	return gObject;
}