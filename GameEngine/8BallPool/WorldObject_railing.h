#pragma once
#include "../BulletPhysicsEngine/IWorldObject.h"
#include "GraphicsObject_railing.h"



class WorldObject_railing : public IWorldObject {
protected:
public:
	WorldObject_railing(property,kind);
	void CreateObject(BulletWorld*);
	int GetNumPoints();
	~WorldObject_railing();
};

