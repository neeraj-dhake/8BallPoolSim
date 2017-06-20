#include "GraphicsObject_railing.h"
#include "WorldObject_railing.h"
#include <d3d9.h>
#include "../Include/d3dx9.h"
#include "../Include/d3dx9mesh.h"
#include <memory>
#include <string>
#include <vector>

GraphicsObject_railing::GraphicsObject_railing(WorldObject_railing* parent_) {
	parent = parent_;
}

void GraphicsObject_railing::Init() {
	D3DXLoadMeshFromX("../Resources/Meshes/PoolAssets/a.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (ID3DXMesh**)&mesh);
	material = (D3DXMATERIAL*)((LPD3DXBUFFER)(material_buffer))->GetBufferPointer();
	mesh_material = new D3DMATERIAL9[numMat];
	mesh_texture = new LPDIRECT3DTEXTURE9[numMat];
	for (size_t i = 0; i < numMat; i++) {
		((D3DMATERIAL9*)mesh_material)[i] = ((D3DXMATERIAL*)material)[i].MatD3D;
		((D3DMATERIAL9*)mesh_material)[i].Ambient = ((D3DMATERIAL9*)mesh_material)[i].Diffuse;
		((LPDIRECT3DTEXTURE9*)mesh_texture)[i] = nullptr;
		std::string path;
		if (((D3DXMATERIAL*)material)[i].pTextureFilename) {
			path = "../Resources/Meshes/" + (std::string)((D3DXMATERIAL*)material)[i].pTextureFilename;
			D3DXCreateTextureFromFile(((LPDIRECT3DDEVICE9)device), path.c_str(), &((LPDIRECT3DTEXTURE9*)mesh_texture)[i]);
		}
	}
	((LPD3DXBUFFER)material_buffer)->Release();

	num_vertices = ((ID3DXMesh*)mesh)->GetNumVertices();
	num_primitives = ((ID3DXMesh*)mesh)->GetNumFaces();

	std::vector<D3DXVECTOR3> vecVertices;
	vecVertices.reserve(num_vertices);
	BYTE* pVerts;
	unsigned int uiSize = ((ID3DXMesh*)mesh)->GetNumBytesPerVertex();
	((ID3DXMesh*)mesh)->LockVertexBuffer(0, (void**)&pVerts);
	D3DXVECTOR3 vec3Vertice;
	for (size_t i = 0;i < num_vertices;i++) {
		vec3Vertice = *((D3DXVECTOR3*)(pVerts + i*uiSize));
		vecVertices.push_back(vec3Vertice);
	}
	((ID3DXMesh*)mesh)->UnlockVertexBuffer();

	std::vector<short> indices;
	indices.reserve(3 * num_primitives);
	BYTE* pIndices;
	unsigned int isize = sizeof(short);
	((ID3DXMesh*)mesh)->LockIndexBuffer(0, (void**)&pIndices);
	for (size_t i = 0;i < 3 * num_primitives;i++) {
		short vec3Vertice1 = *((short*)(pIndices + i*isize));
		indices.push_back(vec3Vertice1);
	}
	((ID3DXMesh*)mesh)->UnlockIndexBuffer();

	v_buf = new D3DXVECTOR3[num_vertices];
	i_buf = new short[3 * num_primitives];
	for (size_t i = 0;i < num_vertices;i++) {
		((D3DXVECTOR3*)v_buf)[i] = vecVertices[i];
	}

	for (size_t i = 0; i < 3 * num_primitives; i++) {
		((short*)i_buf)[i] = indices[i];
	}
}


GraphicsObject_railing::~GraphicsObject_railing() {
	delete[] mesh_material;
	delete[] mesh_texture;
}
