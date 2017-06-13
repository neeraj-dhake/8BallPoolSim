#include "BodyData.h"
#include "ICollisionObject.h"
#pragma once

class IWorldObject;
class IPhysicsObject {

protected:
	IWorldObject* parent;
	BodyData data;
	ICollisionObject* collision_object;
	
public:
	IPhysicsObject();
	~IPhysicsObject();
	void SetVelocity(Vector3D);
	void SetFriction(Vector3D);
	void SetPosition(Vector3D);
	void SetAccelera(Vector3D);
	void AddVelocity(Vector3D);
	void AddPosition(Vector3D);
	void AddAccelera(Vector3D);

	void SetAngularVelocity(Vector3D);
	void SetAngularAccelera(Vector3D);
	void SetTheta(Vector3D);

	void AddTheta(Vector3D);
	void AddAngularVelocity(Vector3D);
	void AddAngularAccelera(Vector3D);

	Vector3D getPos();
	Vector3D getVel();
	Vector3D getAcc();

	Vector3D getTheta();
	Vector3D getOmega();
	Vector3D getAlpha();

	BodyData& GetData();

	ICollisionObject* GetCollisionObject();
	virtual void SetCollisionObject() = 0;
	void Update(float dt);	// for every player controlable unit just call the inputhandler in it and then define the if else statement;

private:
	
};

