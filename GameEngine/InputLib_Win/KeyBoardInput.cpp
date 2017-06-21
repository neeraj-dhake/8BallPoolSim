#include "KeyBoardInput.h"
#include "windowsx.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

LRESULT CALLBACK process(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, std::vector<bool>& keys, float &mouseX, float &mouseY) {

	switch (message)
	{
	case WM_LBUTTONDOWN:
		// Capture mouse input. 


		// Retrieve the screen coordinates of the client area, 
		// and convert them into client coordinates. 

		//mouseX = GET_X_LPARAM(lParam) - SCREEN_WIDTH / 2;
		//mouseY = GET_Y_LPARAM(lParam) - SCREEN_HEIGHT / 2;


	case WM_MOUSEMOVE:

		mouseX = GET_X_LPARAM(lParam) - SCREEN_WIDTH / 2;
		mouseY = GET_Y_LPARAM(lParam) - SCREEN_HEIGHT / 2;
		char msgbuf[200];
		sprintf_s(msgbuf, 200, "%f %f \n", mouseX, mouseY);
		OutputDebugString(msgbuf);


		break;

	case WM_LBUTTONUP:
		return 0;


	case WM_KEYDOWN:
		switch (wParam) {

		case VK_ESCAPE:
			keys[KEY_ESCAPE] = 1;
			return -1;
			break;
		case 0x57:
			keys[KEY_W] = 1;
			break;
		case 0x41:
			keys[KEY_A] = 1;
			break;
		case 0x53:
			keys[KEY_S] = 1;
			break;
		case 0x44:
			keys[KEY_D] = 1;
			break;
		case VK_UP:
			keys[KEY_UP] = 1;
			break;
		case VK_DOWN:
			keys[KEY_DOWN] = 1;
			break;
		case VK_LEFT:
			keys[KEY_LEFT] = 1;
			break;
		case VK_RIGHT:
			keys[KEY_RIGHT] = 1;
			break;

		case VK_SPACE:
			keys[KEY_SPACEBAR] = 1;
			break;

		default:
			break;
		}
		break;
	case WM_KEYUP:
		switch (wParam) {
		case 0x57:
			keys[KEY_W] = 0;
			break;
		case 0x41:
			keys[KEY_A] = 0;
			break;
		case 0x53:
			keys[KEY_S] = 0;
			break;
		case 0x44:
			keys[KEY_D] = 0;
			break;
		case VK_UP:
			keys[KEY_UP] = 0;
			break;
		case VK_DOWN:
			keys[KEY_DOWN] = 0;
			break;
		case VK_LEFT:
			keys[KEY_LEFT] = 0;
			break;
		case VK_RIGHT:
			keys[KEY_RIGHT] = 0;
			break;
		case VK_SPACE:
			keys[KEY_SPACEBAR] = 0;
			break;
		default:
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return -1;
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}


KeyBoardInput::KeyBoardInput() {
	keys_current.resize(Num, false);
	keys_prev.resize(Num, false);
	mark_for_death = false;
}

KeyBoardInput::~KeyBoardInput(void) {
}

bool KeyBoardInput::handle(MSG &msg) {
	keys_prev = keys_current;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (process(msg.hwnd, msg.message, msg.wParam, msg.lParam, keys_current, mouseX, mouseY) == -1)	 // normally DefWindowProc is zero
			return false;
	}
	return true;
}

std::vector<bool> KeyBoardInput::getKeys_current() {
	return keys_current;
}

std::vector<bool> KeyBoardInput::getKeys_prev()
{
	return keys_prev;
}


