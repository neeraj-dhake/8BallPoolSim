#include "GraphicsObject_cuboid.h"
#include "../GameplayEngine/WorldObject_cuboid.h"
#include "CUSTOMVERTEX.h"
#include <d3d9.h>
#include "../Include/d3dx9.h"

#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)

GraphicsObject_cuboid::GraphicsObject_cuboid(WorldObject_cuboid* par) {
	parent = par;
	num_primitives = 12;
	num_vertices = 8;
}

void GraphicsObject_cuboid::SetIndices(void* indices) {
	short temp_indices[] = {
		0, 1, 2,    // side 1
		2, 1, 3,
		4, 0, 6,    // side 2
		6, 0, 2,
		7, 5, 6,    // side 3
		6, 5, 4,
		3, 1, 7,    // side 4
		7, 1, 5,
		4, 5, 0,    // side 5
		0, 5, 1,
		3, 7, 2,    // side 6
		2, 7, 6,
	};
	memcpy(indices, temp_indices, 36 * sizeof(short));
}

void GraphicsObject_cuboid::SetVertices(void* vertices) {
	float width = ((WorldObject_cuboid*)parent)->GetDim().x;
	float height = ((WorldObject_cuboid*)parent)->GetDim().y;
	float depth = ((WorldObject_cuboid*)parent)->GetDim().z;
	((CUSTOMVERTEX*)vertices)[0].set(-width / 2, height / 2, -depth / 2, D3DCOLOR_XRGB(0, 255, 255));
	((CUSTOMVERTEX*)vertices)[1].set(width / 2, height / 2, -depth / 2, D3DCOLOR_XRGB(0, 255, 255));
	((CUSTOMVERTEX*)vertices)[2].set(-width / 2, -height / 2, -depth / 2, D3DCOLOR_XRGB(0, 255, 255));
	((CUSTOMVERTEX*)vertices)[3].set(width / 2, -height / 2, -depth / 2, D3DCOLOR_XRGB(0, 255, 255));
	((CUSTOMVERTEX*)vertices)[4].set(-width / 2, height / 2, depth / 2, D3DCOLOR_XRGB(0, 255, 255));
	((CUSTOMVERTEX*)vertices)[5].set(width / 2, height / 2, depth / 2, D3DCOLOR_XRGB(0, 0, 0));
	((CUSTOMVERTEX*)vertices)[6].set(-width / 2, -height / 2, depth / 2, D3DCOLOR_XRGB(0, 255, 255));
	((CUSTOMVERTEX*)vertices)[7].set(width / 2, -height / 2, depth / 2, D3DCOLOR_XRGB(0, 255, 255));
}

void GraphicsObject_cuboid::SetVBuf(void* vertices, int num_vertices) {
	VOID* pVoid;
	((LPDIRECT3DDEVICE9)device)->CreateVertexBuffer(num_vertices * sizeof(CUSTOMVERTEX), 0, CUSTOMFVF, D3DPOOL_MANAGED, (LPDIRECT3DVERTEXBUFFER9*)&vertex_buffer, NULL);
	((LPDIRECT3DVERTEXBUFFER9)vertex_buffer)->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, num_vertices * sizeof(CUSTOMVERTEX));
	((LPDIRECT3DVERTEXBUFFER9)vertex_buffer)->Unlock();
}

void GraphicsObject_cuboid::SetIBuf(void* indices, int num_indices) {
	VOID* pVoid;
	((LPDIRECT3DDEVICE9)device)->CreateIndexBuffer(num_indices * sizeof(short), 0, D3DFMT_INDEX16, D3DPOOL_MANAGED, (LPDIRECT3DINDEXBUFFER9*)&index_buffer, NULL);
	((LPDIRECT3DINDEXBUFFER9)index_buffer)->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, indices, num_indices * sizeof(short));
	((LPDIRECT3DINDEXBUFFER9)index_buffer)->Unlock();
}

void GraphicsObject_cuboid::SetTexture(void* src) {
	D3DXCreateTextureFromFile((LPDIRECT3DDEVICE9)device, (LPCSTR)src, (IDirect3DTexture9**)&texture);
}

void GraphicsObject_cuboid::Init() {
	CUSTOMVERTEX vertices[8];
	SetVertices(vertices);
	SetVBuf(vertices, 8);
	short indices[36];
	SetIndices(indices);
	SetIBuf(indices, 36);
}

GraphicsObject_cuboid::~GraphicsObject_cuboid() {
}
