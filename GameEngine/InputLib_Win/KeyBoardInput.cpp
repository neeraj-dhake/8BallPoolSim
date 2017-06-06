#include "KeyBoardInput.h"


LRESULT CALLBACK process(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam,bool* getkey)
{
	bool* keys =getkey;

	switch(message)
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


		default: 
			break; 
		}
		break;
	case WM_KEYUP: 
		/*switch (wParam) 
		{ 
		default: 
		break; 
		}*/
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
}
KeyBoardInput::~KeyBoardInput(void)
{
	delete keys;
}

bool KeyBoardInput::handle(MSG &msg)
{
	bool quit = false;
	while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
			
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if(process(msg.hwnd,msg.message,msg.wParam,msg.lParam,keys) == -1)	 // normally DefWindowProc is zero
				return false;
		}	

	return true;
}
bool* KeyBoardInput::getKeys()
{
	return keys;
}

