#pragma once
#include "../RenderingEngine/IGraphicsObject.h"
enum kind { base, right_cushion, left_cushion,top_left_cushion,top_right_cushion, bottom_right_cushion , bottom_left_cushion};

class WorldObject_pool;
class GraphicsObject_pool : public IGraphicsObject {
	kind Kind;

public:
	GraphicsObject_pool(WorldObject_pool*,kind);
	void Init();
	~GraphicsObject_pool();
};

