#include "SceneManager.h"



SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
	if (state == MAIN_MENU && InputHandler::instance().GetKeyState(KEY_SPACEBAR))
	{
		// do properl changes
	}
}

void SceneManager::Render()
{
	switch (state)
	{
	case MAIN_MENU:
		// ---->
		break;
	case PAUSE_MENU:
		// ---->
		break;
	case GAMEPLAY_SCENE:
		// ---->
		break;
	case HELP_SCENE:
		// ---->

		break;
	}
}
