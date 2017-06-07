#include "MenuScene.h"
#include "../GameplayEngine/WorldObject_cuboid.h"

MenuScene::MenuScene() {
	is_active = false;
}

void MenuScene::SetScene() {
	is_active = true;
	WorldObject_cuboid* obj = new WorldObject_cuboid;
	obj->SetCoordinates(0, 0, 0);
	obj->SetDim(10, 10, 10);
	AddObject(obj);
}

MenuScene::~MenuScene() {
}
