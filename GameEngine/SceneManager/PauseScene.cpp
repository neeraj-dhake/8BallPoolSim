#include "PauseScene.h"
#include "../GameplayEngine/WorldObject_cuboid.h"


PauseScene::PauseScene() {
	is_active = false;
}

void PauseScene::SetScene() {
	is_active = true;
	WorldObject_cuboid* obj = new WorldObject_cuboid;
	obj->SetCoordinates(20, -20, 0);
	obj->SetDim(10, 10, 10);
	AddObject(obj);
}


PauseScene::~PauseScene() {
}
