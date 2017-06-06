#include "Scene.h"
#include "../InputLib_Win/InputHandler.h"
#pragma once
class SceneManager
{
	
	enum SCENE_STATE {MAIN_MENU,PAUSE_MENU,GAMEPLAY_SCENE,HELP_SCENE};

public:
	SceneManager();
	~SceneManager();
	void Update();
	void Render();

private:
	Scene* currentScene;
	Scene* nextScene;
	SCENE_STATE state;
};

