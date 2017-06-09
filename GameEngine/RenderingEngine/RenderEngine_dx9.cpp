#include "RenderEngine_dx9.h"
#include <d3d9.h>
#include "../Include/d3dx9.h"
#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)
#include "CUSTOMVERTEX.h"

RenderEngine_dx9::RenderEngine_dx9(int w, int h) {
	SCREEN_WIDTH = w;
	SCREEN_HEIGHT = h;
}

void RenderEngine_dx9::SetHandle(void* HWND) {
	hwnd = HWND;
}

void RenderEngine_dx9::SetWindow() {
	intrfc = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = (HWND)hwnd;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

	((LPDIRECT3D9)intrfc)->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, (HWND)hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, (LPDIRECT3DDEVICE9*)&device);
	((LPDIRECT3DDEVICE9)device)->SetRenderState(D3DRS_LIGHTING, FALSE);
	((LPDIRECT3DDEVICE9)device)->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	((LPDIRECT3DDEVICE9)device)->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	((LPDIRECT3DDEVICE9)device)->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	((LPDIRECT3DDEVICE9)device)->SetRenderState(D3DRS_ZENABLE, TRUE);    // turn on the z-buffer
}

void RenderEngine_dx9::clean() {
	((LPDIRECT3DDEVICE9)device)->Release();
	((LPDIRECT3D9)intrfc)->Release();
}

void RenderEngine_dx9::init_frame(void* pos, void* look, void* up) {
	((LPDIRECT3DDEVICE9)device)->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	((LPDIRECT3DDEVICE9)device)->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView, (D3DXVECTOR3*)pos, (D3DXVECTOR3*)look, (D3DXVECTOR3*)up);
	D3DXMATRIX matProjection;
	D3DXMatrixPerspectiveFovLH(&matProjection, D3DXToRadian(45), (FLOAT)SCREEN_WIDTH / (FLOAT)SCREEN_HEIGHT, -100.0f, 100.0f);
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
		((LPDIRECT3DDEVICE9)device)->SetTexture(0, (IDirect3DTexture9*)(gObject->GetTexture()));
		((LPDIRECT3DDEVICE9)device)->SetFVF(CUSTOMFVF);
		D3DXMATRIX matTranslate;
		Vector3D pos = gObject->GetParent()->GetPos();
		D3DXMatrixTranslation(&matTranslate, pos.x, pos.y, pos.z);
		D3DXMATRIX matRotateX;
		D3DXMatrixRotationX(&matRotateX, D3DXToRadian(45));
		((LPDIRECT3DDEVICE9)device)->SetTransform(D3DTS_WORLD, &(matRotateX*matTranslate));
		((LPDIRECT3DDEVICE9)device)->SetStreamSource(0, (LPDIRECT3DVERTEXBUFFER9)(gObject->GetVBuf()), 0, sizeof(CUSTOMVERTEX));
		((LPDIRECT3DDEVICE9)device)->SetIndices((LPDIRECT3DINDEXBUFFER9)(gObject->GetIBuf()));
		((LPDIRECT3DDEVICE9)device)->SetFVF(CUSTOMFVF);
		((LPDIRECT3DDEVICE9)device)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, gObject->GetNumVertices(), 0, gObject->GetNumPrimitives());
		((LPDIRECT3DDEVICE9)device)->EndScene();
	}
}

void RenderEngine_dx9::Draw(void* pos, void* look, void* up) {
	init_frame(pos, look, up);
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
