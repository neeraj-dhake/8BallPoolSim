#pragma once
#include <Windows.h>
class CUSTOMVERTEX{
	float x, y, z;
	DWORD color;
public:
	CUSTOMVERTEX();
	~CUSTOMVERTEX();
	void set(float, float, float, DWORD);
};

