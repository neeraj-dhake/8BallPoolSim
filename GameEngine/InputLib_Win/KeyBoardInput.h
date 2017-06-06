#include <Windows.h>
#include "IInput.h"
#pragma once
#define No 5
#define esc 0
#define W 1
#define A 2
#define S 3
#define D 4

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

