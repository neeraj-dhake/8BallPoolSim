#include "GraphicsObject_sphere.h"
#include "../BulletPhysicsEngine/WorldObject_sphere.h"
#include <d3d9.h>
#include "../Include/d3dx9.h"
#include "../Include/d3dx9mesh.h"
#include <memory>
#include <string>

GraphicsObject_sphere::GraphicsObject_sphere(WorldObject_sphere * par, std::string address_ ) {
	parent = par;
	address = address_;	
}


GraphicsObject_sphere::~GraphicsObject_sphere(){	
}

void GraphicsObject_sphere::Init() {

	std::string temp = std::string("../Resources/Meshes/MyPoolAssets/") + address;
	D3DXLoadMeshFromX(temp.c_str(), D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (LPD3DXMESH*)&mesh);
	material = (D3DXMATERIAL*)((LPD3DXBUFFER)(material_buffer))->GetBufferPointer();
	mesh_material = new D3DMATERIAL9[numMat];
	mesh_texture = new LPDIRECT3DTEXTURE9[numMat];
	for (size_t i = 0; i < numMat; i++) {
		((D3DMATERIAL9*)mesh_material)[i] = ((D3DXMATERIAL*)material)[i].MatD3D;
		((D3DMATERIAL9*)mesh_material)[i].Ambient = ((D3DMATERIAL9*)mesh_material)[i].Diffuse;
		((LPDIRECT3DTEXTURE9*)mesh_texture)[i] = nullptr;
		std::string path;
		if (((D3DXMATERIAL*)material)[i].pTextureFilename) {
			path = "../Resources/Meshes/MyPoolAssets/" + (std::string)((D3DXMATERIAL*)material)[i].pTextureFilename;
			D3DXCreateTextureFromFile(((LPDIRECT3DDEVICE9)device), path.c_str(), &((LPDIRECT3DTEXTURE9*)mesh_texture)[i]);
		}
	}
	((LPD3DXBUFFER)material_buffer)->Release();
}
