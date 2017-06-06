#include<Windows.h>
#pragma once
class IInput
{
public:
	IInput(void);
	~IInput(void);
	virtual bool handle(MSG &msg) = 0;

};

