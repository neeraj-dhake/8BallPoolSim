#include "GraphicsObject_pool.h"
#include "WorldObject_pool.h"
#include <d3d9.h>
#include "../Include/d3dx9.h"
#include "../Include/d3dx9mesh.h"
#include <memory>
#include <string>
#include <vector>



GraphicsObject_pool::GraphicsObject_pool(WorldObject_pool* parent_,kind Kind_) {
	parent = parent_;
	Kind = Kind_;
}

void GraphicsObject_pool::Init() {

	isConcave = false;
	if (Kind == base)
	{
		isConcave = true;
		D3DXLoadMeshFromX("../Resources/Meshes/MyPoolAssets/PoolBase.blend.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (ID3DXMesh**)&mesh);
	}
	else if (Kind == right_cushion)
	{
		D3DXLoadMeshFromX("../Resources/Meshes/MyPoolAssets/PoolRightCushion.blend.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (ID3DXMesh**)&mesh);
	}

	else if (Kind == left_cushion)
	{
		D3DXLoadMeshFromX("../Resources/Meshes/MyPoolAssets/PoolLeftCushion.blend.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (ID3DXMesh**)&mesh);
	}
	else if (Kind == top_left_cushion)
	{
		D3DXLoadMeshFromX("../Resources/Meshes/MyPoolAssets/PoolTop1Cushion.blend.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (ID3DXMesh**)&mesh);
	}
	else if (Kind == bottom_left_cushion)
	{
		D3DXLoadMeshFromX("../Resources/Meshes/MyPoolAssets/PoolBottom1Cushion.blend.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (ID3DXMesh**)&mesh);
	}
	else if (Kind == top_right_cushion)
	{
		D3DXLoadMeshFromX("../Resources/Meshes/MyPoolAssets/PoolTop2Cushion.blend.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (ID3DXMesh**)&mesh);
	}
	else if (Kind == bottom_right_cushion)
	{
		D3DXLoadMeshFromX("../Resources/Meshes/MyPoolAssets/PoolBottom2Cushion.blend.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (ID3DXMesh**)&mesh);
	}
	else if (Kind == stick)
	{
		D3DXLoadMeshFromX("../Resources/Meshes/MyPoolAssets/PoolStick.blend.x", D3DXMESH_SYSTEMMEM, (LPDIRECT3DDEVICE9)device, NULL, (LPD3DXBUFFER*)&material_buffer, NULL, &numMat, (ID3DXMesh**)&mesh);
	}
	else
	{
		/// error choose some default shape
	}





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

	BYTE* pVerts;
	unsigned int uiSize = ((ID3DXMesh*)mesh)->GetNumBytesPerVertex();
	v_buf = new D3DXVECTOR3[num_vertices];
	((ID3DXMesh*)mesh)->LockVertexBuffer(0, (void**)&pVerts);
	for (size_t i = 0;i < num_vertices;i++) {
		((D3DXVECTOR3*)v_buf)[i] = *((D3DXVECTOR3*)(pVerts + i*uiSize));
	}
	((ID3DXMesh*)mesh)->UnlockVertexBuffer();

	BYTE* pIndices;
	unsigned int isize = sizeof(short);
	i_buf = new short[3 * num_primitives];
	((ID3DXMesh*)mesh)->LockIndexBuffer(0, (void**)&pIndices);
	for (size_t i = 0;i < 3 * num_primitives;i++) {
		((short*)i_buf)[i] = *((short*)(pIndices + i*isize));
	}
	((ID3DXMesh*)mesh)->UnlockIndexBuffer();

}


GraphicsObject_pool::~GraphicsObject_pool() {
	delete[] mesh_material;
	delete[] mesh_texture;
}
