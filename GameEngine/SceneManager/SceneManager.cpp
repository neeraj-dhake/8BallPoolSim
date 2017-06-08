#include "SceneManager.h"
#include "../RenderingEngine/RenderEngine_dx9.h"
#include "../GameplayEngine/IWorldObject.h"

typedef std::list<IWorldObject*>::const_iterator list_object_iterator;

SceneManager::SceneManager(int width, int height, void* HWND) {
	//current_key_state = InputHandler::instance().GetKey();
	//prev_key_state = nullptr;
	next_scene = nullptr;
	next_state = MAIN_MENU;
	render_engine = new RenderEngine_dx9(width, height);
	render_engine->SetHandle(HWND);
	render_engine->SetWindow();
}


SceneManager::~SceneManager() {
}

void SceneManager::Update() {
	if (next_scene!=nullptr)
		current_scene = next_scene;
	else {
		current_scene = all_scenes[MAIN_MENU];
	}
	current_state = next_state;

	/*prev_key_state = current_key_state;
	current_key_state = InputHandler::instance().GetKey();*/
	//char msgbuf[200];
	//sprintf_s(msgbuf, 200, "%d, %d\n", prev_key_state(KEY_W), current_key_state(KEY_W));
	//OutputDebugString(msgbuf);
	switch (current_state) {
		case MAIN_MENU:
			if (InputHandler::instance().GetKeyState_current(KEY_W) == 1 && InputHandler::instance().GetKeyState_prev(KEY_W) == 0) {
				next_state = GAMEPLAY_SCENE;
				next_scene = all_scenes[GAMEPLAY_SCENE];
			}
			break;
		case GAMEPLAY_SCENE:
			if (InputHandler::instance().GetKeyState_current(KEY_W) == 1 && InputHandler::instance().GetKeyState_prev(KEY_W) == 0) {
				next_state = PAUSE_MENU;
				next_scene = all_scenes[PAUSE_MENU];
			}
			break;
		case PAUSE_MENU:
			if (InputHandler::instance().GetKeyState_current(KEY_W) == 1 && InputHandler::instance().GetKeyState_prev(KEY_W) == 0) {
				next_state = MAIN_MENU;
				next_scene = all_scenes[MAIN_MENU];
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
		i++;
	}
	render_engine->SetList(RenderList);
	render_engine->SetNum(num);
}

void SceneManager::Draw() {
	SetRenderList(current_scene);
	render_engine->Draw(&(current_scene->GetCameraPosition()), &(current_scene->GetCameraLookAt()), &(current_scene->GetCameraUp()));
}

void SceneManager::AddScene(Scene* scene) {
	scene->SetManager(this);
	all_scenes.push_back(scene);
}
