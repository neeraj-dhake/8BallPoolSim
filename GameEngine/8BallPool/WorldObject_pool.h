#pragma once
#include "../BulletPhysicsEngine/IWorldObject.h"
#include "GraphicsObject_pool.h"



class WorldObject_pool : public IWorldObject {
protected:
	kind Kind;
public:
	WorldObject_pool(property,kind,TypeOfObject type_ = RIGID_BODY);
	void CreateObject(BulletWorld*);
	~WorldObject_pool();
};

