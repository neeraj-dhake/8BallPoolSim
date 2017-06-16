#pragma once
#include "../BulletPhysicsEngine/Vector3D.h"
#include "IBulletPhysicsObject.h"
#include "../RenderingEngine/IGraphicsObject.h"
#include "BulletWorld.h"



class IWorldObject {
protected:
	property prp;
	Vector3D position;
	Vector3D rotation;
	btRigidBody* pObject;
	IGraphicsObject* gObject;
public:
	IWorldObject();
	~IWorldObject();
	void SetCoordinates(Vector3D);
	void SetRotation(Vector3D);
	virtual void CreateObject(BulletWorld*) ;			// it should be kept a pure virtual have to keep an eye on it
	Vector3D GetPos();
	Vector3D GetRotation();
	btRigidBody* GetpObject();
	IGraphicsObject* GetgObject();
};