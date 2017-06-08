#pragma once
#include "KeyBoardInput.h"
class InputHandler
{
public:
	
	~InputHandler();
	static InputHandler& instance();

	bool GetKeyState_current(KEY_STATE state);
	bool GetKeyState_prev(KEY_STATE state);
	void SetKey(bool* ,bool*);
	bool* GetKey_current();
	bool* GetKey_prev();


private:
	InputHandler();
	bool* keys_current;
	bool* keys_prev;

};

