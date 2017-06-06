#pragma once
#include "KeyBoardInput.h"
class InputHandler
{
public:
	
	~InputHandler();
	static InputHandler& instance();

	bool GetKeyState(KEY_STATE state);
	void SetKey(bool* keys_);
	bool* GetKey();


private:
	InputHandler();
	bool* keys;

};

