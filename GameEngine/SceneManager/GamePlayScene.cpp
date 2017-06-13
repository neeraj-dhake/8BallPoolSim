#include "GamePlayScene.h"
#include "../GameplayEngine/WorldObject_cuboid.h"
#include "../GameplayEngine/WorldObject_sphere.h"
#include "../InputLib_Win/InputHandler.h"
#include "../GameplayEngine/Vector3D.h"
#include "SceneManager.h"

GamePlayScene::GamePlayScene() {
	is_active = false;
}

void GamePlayScene::SetScene() {
	is_active = true;
	WorldObject_cuboid* obj1 = new WorldObject_cuboid;
	obj1->SetCoordinates(Vector3D(10, -10, 0));
	obj1->SetDim(10.0f, 10.0f, 10.0f);
	AddObject(obj1);

	WorldObject_cuboid* obj2 = new WorldObject_cuboid;
	obj2->SetCoordinates(Vector3D(-10, 10, 0));
	obj2->SetDim(10.0f, 10.0f, 10.0f);
	AddObject(obj2);

	WorldObject_sphere* obj3 = new WorldObject_sphere;
	obj3->SetCoordinates(Vector3D(10.0f, 10.0f, 0.0f));
	obj3->SetRadius(10.0f);
	AddObject(obj3);
}

GamePlayScene::~GamePlayScene() {
}

void GamePlayScene::UpdateScene() {
	if (InputHandler::instance().GetKeyState_current(KEY_D))
		(objects_in_scene[obj1]->GetpObject())->AddVelocity(Vector3D(-5.0f, 0, 0));

	if (InputHandler::instance().GetKeyState_current(KEY_A))
		(objects_in_scene[obj1]->GetpObject())->AddVelocity(Vector3D(+5.0f, 0, 0));

	if (InputHandler::instance().GetKeyState_current(KEY_W))
		(objects_in_scene[obj1]->GetpObject())->AddVelocity(Vector3D(0, 5.0f, 0));

	if (InputHandler::instance().GetKeyState_current(KEY_S))
		(objects_in_scene[obj1]->GetpObject())->AddVelocity(Vector3D(0, -5.0f, 0));

	if(InputHandler::instance().GetKeyState_current(KEY_UP))
		(objects_in_scene[obj2]->GetpObject())->AddVelocity(Vector3D(0, 5.0f, 0));

	if (InputHandler::instance().GetKeyState_current(KEY_DOWN))
		(objects_in_scene[obj2]->GetpObject())->AddVelocity(Vector3D(0, -5.0f, 0));

	if (InputHandler::instance().GetKeyState_current(KEY_LEFT))
		(objects_in_scene[obj2]->GetpObject())->AddVelocity(Vector3D(+5.0f, 0, 0));

	if (InputHandler::instance().GetKeyState_current(KEY_RIGHT))
		(objects_in_scene[obj2]->GetpObject())->AddVelocity(Vector3D(-5.0f, 0, 0));

	for (size_t i = 0;i < objects_in_scene.size(); i++) {
		for (size_t j = i + 1; j < objects_in_scene.size(); j++) {
			ICollisionObject* a = (objects_in_scene[i])->GetpObject()->GetCollisionObject();
			ICollisionObject* b = (objects_in_scene[j])->GetpObject()->GetCollisionObject();
			if (Manager->physics_engine->DetectCollision(a, b)) {
				Manager->physics_engine->CollisionResponse( (objects_in_scene[i])->GetpObject()->GetData(),
															(objects_in_scene[j])->GetpObject()->GetData() );
			}
		}
		(objects_in_scene[i])->GetpObject()->Update(dt);
	}
}
