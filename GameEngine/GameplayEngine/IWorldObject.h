#pragma once
#include "Vector3D.h"
#include "IPhysicsObject.h"
#include "../RenderingEngine/IGraphicsObject.h"
#include <Windows.h>

class IWorldObject {
protected:
	Vector3D position;
	Vector3D rotation;
	IPhysicsObject* pObject;
	IGraphicsObject* gObject;
public:
	IWorldObject();
	~IWorldObject();
	void SetCoordinates(Vector3D);
	void SetRotation(Vector3D);
	Vector3D GetPos();
	Vector3D GetRotation();
	IPhysicsObject* GetpObject();
	IGraphicsObject* GetgObject();
};