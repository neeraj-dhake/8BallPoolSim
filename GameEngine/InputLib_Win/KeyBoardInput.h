#include <Windows.h>
#include "IInput.h"
#include <vector>
#pragma once
#define Num 6

enum KEY_STATE { KEY_ESCAPE, KEY_W, KEY_A, KEY_S, KEY_D, KEY_SPACEBAR};

class KeyBoardInput : public IInput
{

private:
	MSG msg;
	HWND hwnd;
	std::vector<bool> keys_current;
	std::vector<bool> keys_prev;
public:
	KeyBoardInput();
	~KeyBoardInput(void);
	virtual bool handle(MSG &msg);
	std::vector<bool> getKeys_current();
	std::vector<bool> getKeys_prev();

};

