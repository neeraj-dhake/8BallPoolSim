#pragma once
#include "IWorldObject.h"
#include "Vector3D.h"

class WorldObject_plane : public IWorldObject {
protected:
	Vector3D normal;
	float dist;
public:
	WorldObject_plane(property, bool need_graphics = true);
	Vector3D GetNormal();
	void SetPlane(Vector3D, float);
	void CreateObject(BulletWorld*);
	float GetDist();
	~WorldObject_plane();
};

