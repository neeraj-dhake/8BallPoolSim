#pragma once
#include "Vector3D.h"
#include "IPhysicsObject.h"
#include "../RenderingEngine/IGraphicsObject.h"
#include <Windows.h>

class IWorldObject {
protected:
	float x, y, z;
	IPhysicsObject* pObject;
	IGraphicsObject* gObject;
public:
	IWorldObject();
	~IWorldObject();
	void SetCoordinates(float, float, float);
	Vector3D GetPos();
	IPhysicsObject* GetpObject();
	IGraphicsObject* GetgObject();
};