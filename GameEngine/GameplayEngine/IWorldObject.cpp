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

void IWorldObject::SetCoordinates(Vector3D pos) {
	position = pos;
	pObject->SetPosition(pos.x, pos.y, pos.z);
}

void IWorldObject::SetRotation(Vector3D rot) {
	rotation = rot;
}

IPhysicsObject* IWorldObject::GetpObject() {
	return pObject;
}

IGraphicsObject* IWorldObject::GetgObject() {
	return gObject;
}