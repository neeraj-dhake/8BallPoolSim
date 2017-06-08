#pragma once
#include "KeyBoardInput.h"
#include <vector>
class InputHandler final
{
public:
	
	~InputHandler();
	static InputHandler& instance();

	bool GetKeyState_current(KEY_STATE state);
	bool GetKeyState_prev(KEY_STATE state);
	void SetKey(std::vector<bool>, std::vector<bool>);
	std::vector<bool> GetKey_current();
	std::vector<bool> GetKey_prev();


private:
	InputHandler();
	std::vector<bool> keys_current;
	std::vector<bool> keys_prev;

};

