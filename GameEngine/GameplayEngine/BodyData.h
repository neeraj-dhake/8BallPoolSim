#include "Vector3D.h"
#pragma once
struct BodyData
{
public:
	//	BodyData(const BodyData &obj);  // copy constructor
	Vector3D position;
	Vector3D velocity;
	Vector3D friction;
	Vector3D accelera;
	float dt;
	bool onGroundX, onGroundY, onGroundZ, isFixed;
	float restitution, invMass;
	//BodyData();
	//~BodyData();
};

