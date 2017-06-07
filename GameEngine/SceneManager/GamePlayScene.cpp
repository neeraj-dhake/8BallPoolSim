#include "GamePlayScene.h"
#include "../GameplayEngine/WorldObject_cuboid.h"

GamePlayScene::GamePlayScene() {
	is_active = false;
}

void GamePlayScene::SetScene() {
	is_active = true;
	WorldObject_cuboid* obj = new WorldObject_cuboid;
	obj->SetCoordinates(30, 30, 30);
	obj->SetDim(10, 10, 10);
	AddObject(obj);
}

GamePlayScene::~GamePlayScene() {
}
