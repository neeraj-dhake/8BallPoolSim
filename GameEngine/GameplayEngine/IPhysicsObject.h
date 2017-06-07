#include "Vector3D.h"
#pragma once

class IWorldObject;
class IPhysicsObject
{

protected:
	IWorldObject* parent;
	Vector3D position;
	Vector3D velocity;
	Vector3D friction;
	Vector3D accelera;
	float dt;
	bool onGroundX, onGroundY, onGroundZ, isFixed;

public:
	IPhysicsObject();
	~IPhysicsObject();
	void SetVelocity(float vx, float vy, float vz);
	void SetFriction(float fx, float fy, float fz);
	void SetPosition(float  x, float  y, float  z);
	void Setaccelera(float ax, float ay, float az);
	Vector3D getPos();
	Vector3D getVel();
	Vector3D getAcc();


	virtual void Update(float dt) = 0;	// for every player controlable unit just call the inputhandler in it and then define the if else statement;

private:
	
};

