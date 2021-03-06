#include "SceneManager.h"
#include "../RenderingEngine/RenderEngine_dx9.h"
#include "../BulletPhysicsEngine/IWorldObject.h"



SceneManager::SceneManager(int width, int height, void* HWND) {
	next_scene = nullptr;
	next_state = GAMEPLAY_SCENE;
	render_engine = new RenderEngine_dx9(width, height);
	render_engine->SetHandle(HWND);
	render_engine->SetWindow();
	PhyWorld = new BulletWorld;



}


SceneManager::~SceneManager() {
	delete PhyWorld;
	delete render_engine;
}

void SceneManager::Update() {
	if (next_scene != nullptr)
		current_scene = next_scene;
	else {
		current_scene = all_scenes[GAMEPLAY_SCENE];
	}
	for (size_t i = 0; i < all_scenes.size(); i++)
	{
		if (all_scenes[i] != current_scene)
			all_scenes[i]->DeactivateScene();
	}

	current_state = next_state;
	switch (current_state) {
	case MAIN_MENU:
		if (InputHandler::instance().GetKeyState_current(KEY_SPACEBAR) == 0 && InputHandler::instance().GetKeyState_prev(KEY_SPACEBAR) == 1) {
			next_state = GAMEPLAY_SCENE;
			next_scene = all_scenes[GAMEPLAY_SCENE];
			for (size_t i = 0; i < all_scenes.size(); i++)
			{
				if (all_scenes[i] != next_scene)
					all_scenes[i]->DeactivateScene();
				else
					all_scenes[i]->ActivateScene();
			}
		}
		break;
	case GAMEPLAY_SCENE:
		if (InputHandler::instance().GetKeyState_current(KEY_SPACEBAR) == 0 && InputHandler::instance().GetKeyState_prev(KEY_SPACEBAR) == 1) {
			next_state = PAUSE_MENU;
			next_scene = all_scenes[PAUSE_MENU];
			for (size_t i = 0; i < all_scenes.size(); i++)
			{
				if (all_scenes[i] != next_scene)
					all_scenes[i]->DeactivateScene();
				else
					all_scenes[i]->ActivateScene();
			}
		}
		break;
	case PAUSE_MENU:
		if (InputHandler::instance().GetKeyState_current(KEY_SPACEBAR) == 0 && InputHandler::instance().GetKeyState_prev(KEY_SPACEBAR) == 1) {
			next_state = MAIN_MENU;
			next_scene = all_scenes[MAIN_MENU];
			for (size_t i = 0; i < all_scenes.size(); i++)
			{
				if (all_scenes[i] != next_scene)
					all_scenes[i]->DeactivateScene();
				else
					all_scenes[i]->ActivateScene();
			}
		}
		break;
	default:
		break;
	}

	current_scene->UpdateScene();
}

void SceneManager::SetRenderList(Scene* scene) {
	size_t num = (scene->objects_in_scene).size();
	IWorldObject* RenderList = new IWorldObject[num];

	for (size_t i = 0; i < num; i++) {
		RenderList[i] = *(scene->objects_in_scene[i]);
	}
	render_engine->SetList(RenderList);
	render_engine->SetNum(num);
}

void SceneManager::Draw() {
	SetRenderList(current_scene);
	render_engine->Draw(&(current_scene->GetCameraPosition()), &(current_scene->GetCameraLookAt()), &(current_scene->GetCameraUp()), &(current_scene->GetLight()));
}

void SceneManager::AddScene(Scene* scene) {
	scene->SetManager(this);
	scene->SetScene();
	scene->PhyWorld = PhyWorld;
	all_scenes.push_back(scene);
}
