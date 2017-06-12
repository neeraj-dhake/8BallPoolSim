#include "GraphicsObject_cuboid.h"
#include "../GameplayEngine/WorldObject_cuboid.h"
#include <d3d9.h>
#include "../Include/d3dx9.h"
#include "../Include/d3dx9mesh.h"
#include <memory>

GraphicsObject_cuboid::GraphicsObject_cuboid(WorldObject_cuboid* par) {
	parent = par;
}

void GraphicsObject_cuboid::Init() {
	D3DXLoadMeshFromX("../Resources/Meshes/cuboid_10.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (LPD3DXMESH*)&mesh);
	SetMesh();

}

void GraphicsObject_cuboid::SetMesh()
{
	material = (D3DXMATERIAL*)((LPD3DXBUFFER)(material_buffer))->GetBufferPointer();

	mesh_material = new D3DMATERIAL9[numMat];
	mesh_texture = new LPDIRECT3DTEXTURE9[numMat];

	for (unsigned int i = 0; i < numMat; i++) 
	{
		((D3DMATERIAL9*)mesh_material)[i] = ((D3DXMATERIAL*)material)[i].MatD3D;
		((D3DMATERIAL9*)mesh_material)[i].Ambient = ((D3DMATERIAL9*)mesh_material)[i].Diffuse;

		((LPDIRECT3DTEXTURE9*)mesh_texture)[i] = nullptr;
		if (((D3DXMATERIAL*)material)[i].pTextureFilename)
			D3DXCreateTextureFromFile(((LPDIRECT3DDEVICE9)device), ((D3DXMATERIAL*)material)[i].pTextureFilename, &((LPDIRECT3DTEXTURE9*)mesh_texture)[i]);
	}
	((LPD3DXBUFFER)material_buffer)->Release();
}

GraphicsObject_cuboid::~GraphicsObject_cuboid() {
}
