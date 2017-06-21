#pragma once
#include "../BulletPhysicsEngine/IWorldObject.h"
#include "GraphicsObject_pool.h"



class WorldObject_pool : public IWorldObject {
protected:
public:
	WorldObject_pool(property,kind);
	void CreateObject(BulletWorld*);
	~WorldObject_pool();
};

