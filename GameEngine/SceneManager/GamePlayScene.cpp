#include "GamePlayScene.h"
#include "../GameplayEngine/WorldObject_cuboid.h"
#include "../InputLib_Win/InputHandler.h"



GamePlayScene::GamePlayScene() {
	phy = new PhysicsEngine;
	is_active = false;
}

void GamePlayScene::SetScene() {
	is_active = true;
	WorldObject_cuboid* obj1 = new WorldObject_cuboid;
	obj1->SetCoordinates(10, -10, 0);
	obj1->SetDim(10, 10, 10);
	AddObject(obj1);

	WorldObject_cuboid* obj2 = new WorldObject_cuboid;
	obj2->SetCoordinates(-10, 10, 0);
	obj2->SetDim(10, 10, 10);
	AddObject(obj2);
}

GamePlayScene::~GamePlayScene() {
	delete phy;
}

void GamePlayScene::UpdateScene()
{
	if (InputHandler::instance().GetKeyState_current(KEY_D))
		(objects_in_scene[obj1]->GetpObject())->AddVelocity(-5.0f, 0, 0);

	if (InputHandler::instance().GetKeyState_current(KEY_A))
		(objects_in_scene[obj1]->GetpObject())->AddVelocity(+5.0f, 0, 0);

	if (InputHandler::instance().GetKeyState_current(KEY_W))
		(objects_in_scene[obj1]->GetpObject())->AddVelocity(0, 5.0f, 0);

	if (InputHandler::instance().GetKeyState_current(KEY_S))
		(objects_in_scene[obj1]->GetpObject())->AddVelocity(0, -5.0f, 0);

	if(InputHandler::instance().GetKeyState_current(KEY_UP))
		(objects_in_scene[obj2]->GetpObject())->AddVelocity(0, 5.0f, 0);

	if (InputHandler::instance().GetKeyState_current(KEY_DOWN))
		(objects_in_scene[obj2]->GetpObject())->AddVelocity(0, -5.0f, 0);

	if (InputHandler::instance().GetKeyState_current(KEY_LEFT))
		(objects_in_scene[obj2]->GetpObject())->AddVelocity(+5.0f, 0, 0);

	if (InputHandler::instance().GetKeyState_current(KEY_RIGHT))
		(objects_in_scene[obj2]->GetpObject())->AddVelocity(-5.0f, 0, 0);




	for (unsigned int i = 0;i < objects_in_scene.size();i++)
	{
		for (size_t j = i + 1; j < objects_in_scene.size(); j++)
		{
			AABB a = ((WorldObject_cuboid*)objects_in_scene[i])->GetAABB();
			AABB b = ((WorldObject_cuboid*)objects_in_scene[j])->GetAABB();
			if (phy->DetectCollision(a, b))
				phy->CollisionResponse(((WorldObject_cuboid*)objects_in_scene[i])->GetpObject()->GetData(), ((WorldObject_cuboid*)objects_in_scene[j])->GetpObject()->GetData());


			float x = ((WorldObject_cuboid*)objects_in_scene[i])->GetpObject()->GetData().velocity.y;
		}

		(objects_in_scene[i])->GetpObject()->Update(dt);
	}
}
