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


void InputHandler::SetKey(std::vector<bool> keys_current_ , std::vector<bool> keys_prev_) {
	keys_current = keys_current_;
	keys_prev = keys_prev_;

}

std::vector<bool> InputHandler::GetKey_current() {
	return keys_current;
}
std::vector<bool> InputHandler::GetKey_prev() {
	return keys_prev;
}


