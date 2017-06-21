#pragma once
#include "../RenderingEngine/IGraphicsObject.h"
enum kind { base, right_cushion, left_cushion };
class WorldObject_railing;
class GraphicsObject_railing : public IGraphicsObject {
	kind Kind;

public:
	GraphicsObject_railing(WorldObject_railing*,kind);
	void Init();
	~GraphicsObject_railing();
};

