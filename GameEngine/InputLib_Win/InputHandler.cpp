#include "InputHandler.h"



InputHandler::InputHandler() {
}


InputHandler::~InputHandler() {
}

InputHandler & InputHandler::instance() {
	static InputHandler *instance = new InputHandler();
	return *instance;
}

bool InputHandler::GetKeyState_current(KEY_STATE state) {
	bool x = keys_current[state];
	return keys_current[state];
}

bool InputHandler::GetKeyState_prev(KEY_STATE state) {
	bool x = keys_prev[state];
	return keys_prev[state];
}


void InputHandler::Set(KeyBoardInput* input) {
	keys_current = input->getKeys_current();
	keys_prev = input->getKeys_prev();
	mouseX = input->mouseX;
	mouseY = input->mouseY;


}

std::vector<bool> InputHandler::GetKey_current() {
	return keys_current;
}
std::vector<bool> InputHandler::GetKey_prev() {
	return keys_prev;
}
float InputHandler::GetMouseX()
{
	return mouseX;
}
float InputHandler::GetMouseY()
{
	return mouseY;
}



