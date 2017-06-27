#include "Scene.h"
#pragma once

class GamePlayScene : public Scene {
	bool StickPlaced;
public:
	GamePlayScene();
	void SetScene();
	~GamePlayScene();
	void UpdateScene();
};

