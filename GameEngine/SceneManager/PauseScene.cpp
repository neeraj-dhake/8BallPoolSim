#include "PauseScene.h"
#include "../BulletPhysicsEngine/WorldObject_cuboid.h"


PauseScene::PauseScene() {
	is_active = false;
}

void PauseScene::SetScene() {
	is_active = true;
	WorldObject_cuboid* obj = new WorldObject_cuboid(STATIC);
	obj->SetCoordinates(Vector3D(20, -20, 0));
	obj->SetDim(10, 10, 10);
	AddObject(obj);
}


PauseScene::~PauseScene() {
}
