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
	keys_current = new bool[Num];
	keys_prev = new bool[Num];
	for (size_t i = 0; i < Num; i++)
	{
		keys_current[i] = false;
		keys_prev[i] = false;

	}
}
KeyBoardInput::~KeyBoardInput(void)
{
	delete keys_current;
	delete keys_prev;

}

bool KeyBoardInput::handle(MSG &msg)
{
	keys_prev = keys_current;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (process(msg.hwnd, msg.message, msg.wParam, msg.lParam, keys_current) == -1)	 // normally DefWindowProc is zero
			return false;
	}
	return true;
}
bool* KeyBoardInput::getKeys_current()
{
	return keys_current;
}

bool* KeyBoardInput::getKeys_prev()
{
	return keys_prev;
}


