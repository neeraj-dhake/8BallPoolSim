#include "KeyBoardInput.h"


LRESULT CALLBACK process(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, bool* keys)
{
	

	switch (message)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			return -1;
			keys[KEY_ESCAPE] = 1;
			break;
			// add other buttons implemntations
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
		case VK_SPACE:
			keys[KEY_SPACEBAR] = 1;
			break;

		default:
			break;
		}
		break;
	case WM_KEYUP:
		switch (wParam)
		{
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


KeyBoardInput::KeyBoardInput()
{
	keys = new bool[Num];
	for (size_t i = 0; i < Num; i++)
		keys[i] = false;
}
KeyBoardInput::~KeyBoardInput(void)
{
	delete keys;
}

bool KeyBoardInput::handle(MSG &msg)
{
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (process(msg.hwnd, msg.message, msg.wParam, msg.lParam, keys) == -1)	 // normally DefWindowProc is zero
			return false;
	}

	return true;
}
bool* KeyBoardInput::getKeys()
{
	return keys;
}

