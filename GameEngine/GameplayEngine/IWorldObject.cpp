#include "IWorldObject.h"

IWorldObject::IWorldObject() {
}


IWorldObject::~IWorldObject() {
}

Vector3D IWorldObject::GetPos() {
	return Vector3D(x, y, z);
}
void IWorldObject::SetCoordinates(float X,float Y,float Z) {
	x = X;y = Y;z = Z;
}

IPhysicsObject* IWorldObject::GetpObject() {
	return pObject;
}

IGraphicsObject* IWorldObject::GetgObject() {
	return gObject;
}