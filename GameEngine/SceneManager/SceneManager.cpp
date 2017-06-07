#include "SceneManager.h"
#include "../RenderingEngine/RenderEngine_dx9.h"
#include "../GameplayEngine/IWorldObject.h"

typedef std::list<IWorldObject*>::const_iterator list_object_iterator;

SceneManager::SceneManager(int width, int height, void* HWND) {
	next_scene = 0;
	next_state = MAIN_MENU;
	render_engine = new RenderEngine_dx9(width, height);
	render_engine->SetHandle(HWND);
	render_engine->SetWindow();
}


SceneManager::~SceneManager() {
}

void SceneManager::Update() {
	if (next_scene)
		current_scene = next_scene;
	else
		current_scene = all_scenes[0];
	current_state = next_state;
	switch (current_state) {
		case MAIN_MENU:
			if (InputHandler::instance().GetKeyState(KEY_SPACEBAR)) {
				next_state = GAMEPLAY_SCENE;
				next_scene = all_scenes[1];
			}
			break;
		case GAMEPLAY_SCENE:
			if (InputHandler::instance().GetKeyState(KEY_SPACEBAR)) {
				next_state = PAUSE_MENU;
				next_scene = all_scenes[2];
			}
			break;
		case PAUSE_MENU:
			if (InputHandler::instance().GetKeyState(KEY_SPACEBAR)) {
				next_state = MAIN_MENU;
				next_scene = all_scenes[0];
			}
			break;
		default:
			break;
	}
}

void SceneManager::SetRenderList(Scene* scene) {
	size_t num = (scene->objects_in_scene).size();
	IWorldObject* RenderList = new IWorldObject[num];
	int i = 0;
	for (list_object_iterator it = (scene->objects_in_scene).begin(); it != (scene->objects_in_scene).end(); ++it) {
		RenderList[i] = **it;
		(RenderList[i].GetgObject())->SetDevice(render_engine->GetDevice());
		(RenderList[i].GetgObject())->Init();
		i++;
	}
	render_engine->SetList(RenderList);
	render_engine->SetNum(num);
}

void SceneManager::Draw() {
	current_scene->SetScene();
	SetRenderList(current_scene);
	render_engine->Draw(&(current_scene->GetCameraPosition()), &(current_scene->GetCameraLookAt()), &(current_scene->GetCameraUp()));
}

void SceneManager::AddScene(Scene* scene) {
	all_scenes.push_back(scene);
}
