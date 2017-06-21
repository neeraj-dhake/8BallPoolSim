#include "RenderEngine_dx9.h"
#include <d3d9.h>
#include "../Include/d3dx9.h"
#include "../Include/d3dx9math.h"


RenderEngine_dx9::RenderEngine_dx9(int w, int h) {
	SCREEN_WIDTH = w;
	SCREEN_HEIGHT = h;
}

void RenderEngine_dx9::SetHandle(void* HWND) {
	hwnd = HWND;
}

void RenderEngine_dx9::SetWindow() {
	intrfc = Direct3DCreate9(D3D_SDK_VERSION);

	

	

	light = new D3DLIGHT9;
	ZeroMemory(light, sizeof(D3DLIGHT9));
	((D3DLIGHT9*)(light))->Type = D3DLIGHT_DIRECTIONAL;
	((D3DLIGHT9*)(light))->Diffuse.r = 1.0f;
	((D3DLIGHT9*)(light))->Diffuse.g = 1.0f;
	((D3DLIGHT9*)(light))->Diffuse.b = 1.0f;

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = (HWND)hwnd;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

	((LPDIRECT3D9)intrfc)->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, (HWND)hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, (LPDIRECT3DDEVICE9*)&device);
	((LPDIRECT3DDEVICE9)device)->SetRenderState(D3DRS_LIGHTING, TRUE);
	((LPDIRECT3DDEVICE9)device)->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	((LPDIRECT3DDEVICE9)device)->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	((LPDIRECT3DDEVICE9)device)->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	((LPDIRECT3DDEVICE9)device)->SetRenderState(D3DRS_ZENABLE, TRUE);    // turn on the z-buffer

	((LPDIRECT3DDEVICE9)device)->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);


}

void RenderEngine_dx9::clean() {
	((LPDIRECT3DDEVICE9)device)->Release();
	((LPDIRECT3D9)intrfc)->Release();
}

void RenderEngine_dx9::init_frame(void* pos, void* look, void* up, void* _light) {
	((LPDIRECT3DDEVICE9)device)->Clear(0, NULL, D3DCLEAR_TARGET,  D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);
	((LPDIRECT3DDEVICE9)device)->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);

	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView, (D3DXVECTOR3*)pos, (D3DXVECTOR3*)look, (D3DXVECTOR3*)up);

	

	((D3DLIGHT9*)(light))->Direction.x = ((D3DXVECTOR3*)_light)->x;
	((D3DLIGHT9*)(light))->Direction.y = ((D3DXVECTOR3*)_light)->y;
	((D3DLIGHT9*)(light))->Direction.z = ((D3DXVECTOR3*)_light)->z;

	((LPDIRECT3DDEVICE9)device)->LightEnable(0, TRUE);
	((LPDIRECT3DDEVICE9)device)->SetLight(0, ((D3DLIGHT9*)(light)));


	D3DXMATRIX matProjection;
	D3DXMatrixPerspectiveFovLH(&matProjection, D3DXToRadian(45), (FLOAT)SCREEN_WIDTH / (FLOAT)SCREEN_HEIGHT, 10.0f, 1000.0f);

	((LPDIRECT3DDEVICE9)device)->SetTransform(D3DTS_PROJECTION, &(matView * matProjection));

	HRESULT Result = ((LPDIRECT3DDEVICE9)device)->TestCooperativeLevel();
	if (FAILED(Result)) {
		if (Result == D3DERR_DEVICELOST)
			return;
		if (Result == D3DERR_DEVICENOTRESET)
			clean();
	}
}

void RenderEngine_dx9::end_frame() {
	((LPDIRECT3DDEVICE9)device)->Present(NULL, NULL, NULL, NULL);
	delete[] list_to_render;
	list_to_render = NULL;
}

void RenderEngine_dx9::Render(IGraphicsObject* gObject) {
	if ((SUCCEEDED(((LPDIRECT3DDEVICE9)device)->BeginScene()))) {
		//((LPDIRECT3DDEVICE9)device)->SetTexture(0, (IDirect3DTexture9*)(gObject->GetTexture()));

		D3DXMATRIX matTranslate;
		Vector3D pos = gObject->GetParent()->GetPos();
		D3DXMatrixTranslation(&matTranslate, pos.x, pos.y, pos.z);

		D3DXMATRIX matRotate;
		Vector3D rotation = gObject->GetParent()->GetRotation();
		D3DXMatrixRotationYawPitchRoll(&matRotate, rotation.y, rotation.x, rotation.z);
		((LPDIRECT3DDEVICE9)device)->SetTransform(D3DTS_WORLD, &(matRotate*matTranslate));

		/*((LPDIRECT3DDEVICE9)device)->SetStreamSource(0, (LPDIRECT3DVERTEXBUFFER9)(gObject->GetVBuf()), 0, sizeof(CUSTOMVERTEX));
		((LPDIRECT3DDEVICE9)device)->SetIndices((LPDIRECT3DINDEXBUFFER9)(gObject->GetIBuf()));
		((LPDIRECT3DDEVICE9)device)->SetFVF(CUSTOMFVF);
		((LPDIRECT3DDEVICE9)device)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, gObject->GetNumVertices(), 0, gObject->GetNumPrimitives());
		*/

		for (int i = 0; i < gObject->GetNum(); i++) {
			((LPDIRECT3DDEVICE9)device)->SetMaterial(&((D3DMATERIAL9*)(gObject->GetMaterial()))[i]);
			((LPDIRECT3DDEVICE9)device)->SetTexture(0,((LPDIRECT3DTEXTURE9*)(gObject->GetTexture()))[i]);
			((ID3DXMesh*)(gObject->GetMesh()))->DrawSubset(i);
		}

		((LPDIRECT3DDEVICE9)device)->EndScene();

	}
}

void RenderEngine_dx9::Draw(void* pos, void* look, void* up,void* light) {
	init_frame(pos, look, up,light);
	for (int i = 0; i < num_objects; i++)
		Render(list_to_render[i].GetgObject());
	end_frame();
}

void RenderEngine_dx9::SetNum(size_t n) {
	num_objects = n;
}

void* RenderEngine_dx9::GetDevice() {
	return device;
}

void RenderEngine_dx9::SetList(IWorldObject* list) {
	list_to_render = list;
}

RenderEngine_dx9::~RenderEngine_dx9() {
	clean();
}