#pragma once
#include "../BulletPhysicsEngine/Vector3D.h"
#include "IBulletPhysicsObject.h"
#include "../RenderingEngine/IGraphicsObject.h"
#include "BulletWorld.h"

class IWorldObject {
protected:
	property prp;
	TypeOfObject type;
	Vector3D position;
	Vector3D rotation;
	float w;
	btCollisionObject* pObject;
	IGraphicsObject* gObject;
public:
	IWorldObject();
	~IWorldObject();
	void SetCoordinates(Vector3D);
	void SetRotation(Vector3D);
	void SetW(float);
	virtual void CreateObject(BulletWorld*);
	Vector3D GetPos();
	Vector3D GetRotation();
	btCollisionObject* GetpObject();
	float GetW();
	IGraphicsObject* GetgObject();
};