#include "Scene.h"
#include "../GameplayEngine/PhysicsEngine.h"
#pragma once

class GamePlayScene : public Scene
{
	PhysicsEngine* phy;
	enum GamePlayObjects {obj1,obj2};	// write some sensible names next time
public:
	GamePlayScene();
	void SetScene();
	~GamePlayScene();
	void UpdateScene();
};

