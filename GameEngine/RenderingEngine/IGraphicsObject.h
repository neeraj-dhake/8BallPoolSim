#pragma once
class IWorldObject;
#include "../BulletPhysicsEngine/Vector3D.h"
#include <string>
typedef unsigned long DWORD;

class IGraphicsObject {
protected:
	void* device;
	void* mesh;
	DWORD numMat;
	void* material_buffer;
	void* material;
	void* mesh_material;
	void* mesh_texture;
	void* v_buf;
	void* i_buf;
	IWorldObject* parent;
	int num_primitives;
	int num_vertices;
	Vector3D color;
public:
	IGraphicsObject();
	IWorldObject* GetParent();
	void SetDevice(void*);
	virtual void Init() = 0;
	void* GetMaterial();
	void* GetVBuf();
	void* GetIBuf();
	int GetNumVertices();
	int GetNumPrimitives();
	void* GetMesh();
	void* GetTexture();
	int GetNum();
	// make set and get functions functiions ------------
	~IGraphicsObject();
};

