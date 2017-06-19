#pragma once
#include "../BulletPhysicsEngine/IWorldObject.h"
#include "GraphicsObject_railing.h"

class WorldObject_railing : public IWorldObject {
protected:
public:
	WorldObject_railing(property);
	void CreateObject(BulletWorld*);
	btVector3* GetPoints();
	int GetNumPoints();
	~WorldObject_railing();
};

