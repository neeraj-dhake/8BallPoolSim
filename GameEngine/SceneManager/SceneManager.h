#include "Scene.h"
#include "../InputLib_Win/InputHandler.h"
#include "../RenderingEngine/IRenderer.h"
#include <vector>
#pragma once
class SceneManager {
	
	enum SCENE_STATE { MAIN_MENU, PAUSE_MENU, GAMEPLAY_SCENE, HELP_SCENE };

public:
	SceneManager(int width, int height, void* HWND);
	~SceneManager();
	void Update();
	void SetRenderList(Scene*);
	void Draw();
	void AddScene(Scene*);

private:
	Scene* current_scene;
	Scene* next_scene;
	std::vector<Scene*> all_scenes;
	SCENE_STATE current_state;
	SCENE_STATE next_state;
	IRenderer* render_engine;
};

