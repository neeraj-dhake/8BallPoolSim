#include "InputHandler.h"



InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

InputHandler & InputHandler::instance()
{
	static InputHandler *instance = new InputHandler();
	return *instance;
}

bool InputHandler::GetKeyState(KEY_STATE state)
{
	return keys[state];
}

void InputHandler::SetKey(bool * keys_)
{
	keys = keys_;
}

bool* InputHandler::GetKey()
{
	return keys;
}

