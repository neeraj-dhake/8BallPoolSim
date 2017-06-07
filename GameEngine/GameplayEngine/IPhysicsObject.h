#include "BodyData.h"
#pragma once

class IWorldObject;
class IPhysicsObject
{

protected:
	IWorldObject* parent;
	BodyData data;

	

public:
	IPhysicsObject();
	~IPhysicsObject();
	void SetVelocity(float vx, float vy, float vz);
	void SetFriction(float fx, float fy, float fz);
	void SetPosition(float  x, float  y, float  z);
	void SetAccelera(float ax, float ay, float az);
	Vector3D getPos();
	Vector3D getVel();
	Vector3D getAcc();


	virtual void Update(float dt) = 0;	// for every player controlable unit just call the inputhandler in it and then define the if else statement;

private:
	
};

