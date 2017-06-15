#include <Windows.h>
#include "../BulletPhysicsEngine/WorldObject_cuboid.h"
#include "../Include/d3dx9.h"
#include "../InputLib_Win/KeyBoardInput.h"
#include "../SceneManager/Scene.h"
#include "../SceneManager/SceneManager.h"
#include "../SceneManager/GamePlayScene.h"
#include "../SceneManager/PauseScene.h"
#include "../SceneManager/MenuScene.h"
#include "../Include/btBulletDynamicsCommon.h"
#include "../BulletPhysicsEngine/BulletWorld.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

#pragma comment (lib, "BulletPhysicsEngine.lib")
#pragma comment (lib, "RenderingEngine.lib")
#pragma comment (lib, "InputLib_Win.lib")
#pragma comment (lib, "BulletPhysicsEngine")
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

#pragma comment (lib, "BulletDynamics_vs2010_x64_debug.lib")
#pragma comment (lib, "BulletCollision_vs2010_x64_debug.lib")
#pragma comment (lib, "Bullet3Collision_vs2010_x64_debug.lib")
#pragma comment (lib, "LinearMath_vs2010_x64_debug.lib")


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_QUIT:
			PostQuitMessage(0);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
			break;
			return FALSE;
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "myClass";
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	HWND hwnd;
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "myClass", "3DGame", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);


	KeyBoardInput *input = new KeyBoardInput;
	InputHandler::instance().SetKey(input->getKeys_current(), input->getKeys_prev());



	Scene* menu_scene = new MenuScene;
	Scene* pause_scene = new PauseScene;
	Scene* gameplay_scene = new GamePlayScene;

	SceneManager* scene_manager = new SceneManager(SCREEN_WIDTH, SCREEN_HEIGHT, hwnd);
	
	D3DXVECTOR3 pos(0, 0, 150), lookat(0, 0, 0), up(0, 1, 0);

	menu_scene->SetCamera(pos, lookat, up);
	pause_scene->SetCamera(pos, lookat, up);
	gameplay_scene->SetCamera(pos, lookat, up);

	scene_manager->AddScene(menu_scene);
	scene_manager->AddScene(gameplay_scene);
	scene_manager->AddScene(pause_scene);

	MSG msg;
	while (TRUE) {
		if (!input->handle(msg) || msg.message == WM_QUIT)
			break;
		InputHandler::instance().SetKey(input->getKeys_current(), input->getKeys_prev());
		scene_manager->Update();
		scene_manager->Draw();
	}

	delete input;
	return 0;
}