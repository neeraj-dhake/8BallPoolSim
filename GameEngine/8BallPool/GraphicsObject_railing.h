#pragma once
#include "../RenderingEngine/IGraphicsObject.h"
class GraphicsObject_railing : public IGraphicsObject {
public:
	GraphicsObject_railing(WorldObject_railing*);
	void Init();
	~GraphicsObject_railing();
};
