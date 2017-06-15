#include "Scene.h"
#pragma once

class GamePlayScene : public Scene {
	enum GamePlayObjects {obj1,obj2,obj3};	// write some sensible names next time
public:
	GamePlayScene();
	void SetScene();
	~GamePlayScene();
	void UpdateScene();
};

