#pragma once
class IWorldObject;

class IGraphicsObject {
protected:
	void* device;
	void* index_buffer;
	void* vertex_buffer;
	void* texture;
	IWorldObject* parent;
	int num_primitives;
	int num_vertices;
public:
	IGraphicsObject();
	IWorldObject* GetParent();
	void SetDevice(void*);
	virtual void SetIndices(void*) = 0;
	virtual void SetVertices(void*) = 0;
	virtual void SetVBuf(void*, int) = 0;
	virtual void SetIBuf(void*, int) = 0;
	virtual void SetTexture(void*) = 0;
	virtual void Init() = 0;
	void* GetTexture();
	void* GetVBuf();
	void* GetIBuf();
	int GetNumPrimitives();
	int GetNumVertices();
	~IGraphicsObject();
};

