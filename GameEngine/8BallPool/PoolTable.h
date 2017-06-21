#include "WorldObject_pool.h"
#include "../SceneManager/Scene.h"
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

public:
	PoolTable(property);
	void SetCoordinates(Vector3D);
	void AddObject(Scene*);
	~PoolTable();
};

