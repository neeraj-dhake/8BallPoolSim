#include "GraphicsObject_plane.h"
#include "../BulletPhysicsEngine/WorldObject_plane.h"
#include <d3d9.h>
#include "../Include/d3dx9.h"
#include "../Include/d3dx9mesh.h"
#include <memory>
#include <string>

GraphicsObject_plane::GraphicsObject_plane(WorldObject_plane* parent_){
	parent = parent_;
}

void GraphicsObject_plane::Init() {
	D3DXLoadMeshFromX("../Resources/Meshes/cuboid_10.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (ID3DXMesh**)&mesh);
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
}

GraphicsObject_plane::~GraphicsObject_plane() {
}
