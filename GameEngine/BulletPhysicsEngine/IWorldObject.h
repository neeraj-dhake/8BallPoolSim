#pragma once
#include "../GameplayEngine/Vector3D.h"
#include "IBulletPhysicsObject.h"
#include "../RenderingEngine/IGraphicsObject.h"
#include "BulletWorld.h"

class IWorldObject {
protected:
	Vector3D position;
	Vector3D rotation;
	IBulletPhysicsObject* pObject;
	IGraphicsObject* gObject;
public:
	IWorldObject();
	~IWorldObject();
	void SetCoordinates(Vector3D);
	void SetRotation(Vector3D);
	virtual void Create(BulletWorld*) = 0;
	Vector3D GetPos();
	Vector3D GetRotation();
	IBulletPhysicsObject* GetpObject();
	IGraphicsObject* GetgObject();
};