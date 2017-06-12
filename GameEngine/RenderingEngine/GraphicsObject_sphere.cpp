#include "GraphicsObject_sphere.h"
#include "../GameplayEngine/WorldObject_sphere.h"
#include <d3d9.h>
#include "../Include/d3dx9.h"
#include "../Include/d3dx9mesh.h"
#include <memory>

GraphicsObject_sphere::GraphicsObject_sphere(WorldObject_sphere * par)
{
	parent = par;
	
}

GraphicsObject_sphere::~GraphicsObject_sphere()
{	
}

void GraphicsObject_sphere::Init()
{
	D3DXLoadMeshFromX("../Resources/Meshes/sphere.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (LPD3DXMESH*)&mesh);
	SetMesh();
}

void GraphicsObject_sphere::SetMesh()
{
	material = (D3DXMATERIAL*)((LPD3DXBUFFER)(material_buffer))->GetBufferPointer();

	mesh_material = new D3DMATERIAL9[numMat];
	LPDIRECT3DTEXTURE9* g_pMeshTextures = new LPDIRECT3DTEXTURE9[numMat];

	for (unsigned int i = 0; i < numMat; i++)
	{
		((D3DMATERIAL9*)mesh_material)[i] = ((D3DXMATERIAL*)material)[i].MatD3D;
		((D3DMATERIAL9*)mesh_material)[i].Ambient = ((D3DMATERIAL9*)mesh_material)[i].Diffuse;
		D3DXCreateTextureFromFile(((LPDIRECT3DDEVICE9)device), ((D3DXMATERIAL*)material)[i].pTextureFilename, &g_pMeshTextures[i]);
	}
	((LPD3DXBUFFER)material_buffer)->Release();
}