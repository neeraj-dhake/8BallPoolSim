#include <Windows.h>
#include "IInput.h"
#pragma once
#define Num 5

enum KEY_STATE { KEY_ESCAPE,KEY_W, KEY_A, KEY_S, KEY_D, KEY_SPACEBAR};

class KeyBoardInput : public IInput
{

private:
	MSG msg;
	HWND hwnd;
	bool* keys;
public:
	KeyBoardInput();
	~KeyBoardInput(void);
	virtual bool handle(MSG &msg);
	bool* getKeys(); 

};

