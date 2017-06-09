#pragma once
#include "Scene.h"
class GamePlayScene : public Scene
{
	enum GamePlayObjects {obj1,obj2};	// write some sensible names next time
public:
	GamePlayScene();
	void SetScene();
	~GamePlayScene();
	void UpdateScene();
};

