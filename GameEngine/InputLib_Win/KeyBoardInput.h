#include <Windows.h>
#include "IInput.h"
#include <vector>
#pragma once
#define Num 10

enum KEY_STATE { KEY_ESCAPE, KEY_W, KEY_A, KEY_S, KEY_D, KEY_SPACEBAR,KEY_UP,KEY_DOWN,KEY_RIGHT,KEY_LEFT,LEFT_CLICK};


class KeyBoardInput : public IInput
{

private:
	MSG msg;
	HWND hwnd;
	std::vector<bool> keys_current;
	std::vector<bool> keys_prev;
	bool mark_for_death;
public:
	KeyBoardInput();
	~KeyBoardInput(void);
	virtual bool handle(MSG &msg);
	std::vector<bool> getKeys_current();
	std::vector<bool> getKeys_prev();
	float mouseX, mouseY;

	

};

