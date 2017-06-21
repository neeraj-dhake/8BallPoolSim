#include "WorldObject_pool.h"
#include "../SceneManager/Scene.h"
#include "../BulletPhysicsEngine/WorldObject_sphere.h"

const unsigned int PoolBall1 = 8;
const unsigned int PoolBall2 = 7;
#pragma once
class PoolTable
{
	WorldObject_pool* baseObj;
	WorldObject_pool* leftCushionObj;
	WorldObject_pool* rightCushionObj;
	WorldObject_pool* topleftCushionObj;
	WorldObject_pool* toprightCushionObj;
	WorldObject_pool* bottomleftCushionObj;
	WorldObject_pool* bottomrightCushionObj;
	WorldObject_sphere* PoolBall1;
	WorldObject_sphere* PoolBall2;

public:
	PoolTable();
	void SetCoordinates(Vector3D);
	void AddObject(Scene*);
	~PoolTable();
};

