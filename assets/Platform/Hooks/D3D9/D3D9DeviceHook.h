#ifdef _DIRECT_D3D9_

#include "stdafx.h"
           
struct D3D9DeviceHook : IUnknown {

	virtual HRESULT QueryInterface(REFIID riid, LPVOID *ppvObj);
	virtual ULONG AddRef();
	virtual ULONG Release();

	virtual HRESULT TestCooperativeLevel();
	virtual UINT GetAvailableTextureMem();
	virtual HRESULT EvictManagedResources();
	virtual HRESULT GetDirect3D(IDirect3D9** ppD3D9);
	virtual HRESULT GetDeviceCaps(D3DCAPS9* pCaps);
	virtual HRESULT GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode);
	virtual HRESULT GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters);
	virtual HRESULT SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap);
	virtual VOID SetCursorPosition(int X, int Y, DWORD Flags);
	virtual BOOL ShowCursor(BOOL bShow);
	virtual HRESULT CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain);
	virtual HRESULT GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain);
	virtual UINT GetNumberOfSwapChains();
	virtual HRESULT Reset(D3DPRESENT_PARAMETERS* pPresentationParameters);
	virtual HRESULT Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion);
	virtual HRESULT GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer);
	virtual HRESULT GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus);
	virtual HRESULT SetDialogBoxMode(BOOL bEnableDialogs);
	virtual VOID SetGammaRamp(UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp);
	virtual VOID GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp);
	virtual HRESULT CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle);
	virtual HRESULT CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle);
	virtual HRESULT CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle);
	virtual HRESULT CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle);
	virtual HRESULT CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle);
	virtual HRESULT CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle);
	virtual HRESULT CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle);
	virtual HRESULT UpdateSurface(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint);
	virtual HRESULT UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture);
	virtual HRESULT GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface);
	virtual HRESULT GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface);
	virtual HRESULT StretchRect(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter);
	virtual HRESULT ColorFill(IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color);
	virtual HRESULT CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle);
	virtual HRESULT SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget);
	virtual HRESULT GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget);
	virtual HRESULT SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil);
	virtual HRESULT GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface);
	virtual HRESULT BeginScene();
	virtual HRESULT EndScene();
	virtual HRESULT Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil);
	virtual HRESULT SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix);
	virtual HRESULT GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix);
	virtual HRESULT MultiplyTransform(D3DTRANSFORMSTATETYPE, CONST D3DMATRIX*);
	virtual HRESULT SetViewport(CONST D3DVIEWPORT9* pViewport);
	virtual HRESULT GetViewport(D3DVIEWPORT9* pViewport);
	virtual HRESULT SetMaterial(CONST D3DMATERIAL9* pMaterial);
	virtual HRESULT GetMaterial(D3DMATERIAL9* pMaterial);
	virtual HRESULT SetLight(DWORD Index, CONST D3DLIGHT9*);
	virtual HRESULT GetLight(DWORD Index, D3DLIGHT9*);
	virtual HRESULT LightEnable(DWORD Index, BOOL Enable);
	virtual HRESULT GetLightEnable(DWORD Index, BOOL* pEnable);
	virtual HRESULT SetClipPlane(DWORD Index, CONST float* pPlane);
	virtual HRESULT GetClipPlane(DWORD Index, float* pPlane);
	virtual HRESULT SetRenderState(D3DRENDERSTATETYPE State, DWORD Value);
	virtual HRESULT GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue);
	virtual HRESULT CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB);
	virtual HRESULT BeginStateBlock();
	virtual HRESULT EndStateBlock(IDirect3DStateBlock9** ppSB);
	virtual HRESULT SetClipStatus(CONST D3DCLIPSTATUS9* pClipStatus);
	virtual HRESULT GetClipStatus(D3DCLIPSTATUS9* pClipStatus);
	virtual HRESULT GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture);
	virtual HRESULT SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture);
	virtual HRESULT GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue);
	virtual HRESULT SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value);
	virtual HRESULT GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue);
	virtual HRESULT SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value);
	virtual HRESULT ValidateDevice(DWORD* pNumPasses);
	virtual HRESULT SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY* pEntries);
	virtual HRESULT GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries);
	virtual HRESULT SetCurrentTexturePalette(UINT PaletteNumber);
	virtual HRESULT GetCurrentTexturePalette(UINT *PaletteNumber);
	virtual HRESULT SetScissorRect(CONST RECT* pRect);
	virtual HRESULT GetScissorRect(RECT* pRect);
	virtual HRESULT SetSoftwareVertexProcessing(BOOL bSoftware);
	virtual BOOL GetSoftwareVertexProcessing();
	virtual HRESULT SetNPatchMode(float nSegments);
	virtual float GetNPatchMode();
	virtual HRESULT DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount);
	virtual HRESULT DrawIndexedPrimitive(D3DPRIMITIVETYPE, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);
	virtual HRESULT DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride);
	virtual HRESULT DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride);
	virtual HRESULT ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags);
	virtual HRESULT CreateVertexDeclaration(CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl);
	virtual HRESULT SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl);
	virtual HRESULT GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl);
	virtual HRESULT SetFVF(DWORD FVF);
	virtual HRESULT GetFVF(DWORD* pFVF);
	virtual HRESULT CreateVertexShader(CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader);
	virtual HRESULT SetVertexShader(IDirect3DVertexShader9* pShader);
	virtual HRESULT GetVertexShader(IDirect3DVertexShader9** ppShader);
	virtual HRESULT SetVertexShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount);
	virtual HRESULT GetVertexShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount);
	virtual HRESULT SetVertexShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount);
	virtual HRESULT GetVertexShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount);
	virtual HRESULT SetVertexShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount);
	virtual HRESULT GetVertexShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount);
	virtual HRESULT SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride);
	virtual HRESULT GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride);
	virtual HRESULT SetStreamSourceFreq(UINT StreamNumber, UINT Setting);
	virtual HRESULT GetStreamSourceFreq(UINT StreamNumber, UINT* pSetting);
	virtual HRESULT SetIndices(IDirect3DIndexBuffer9* pIndexData);
	virtual HRESULT GetIndices(IDirect3DIndexBuffer9** ppIndexData);
	virtual HRESULT CreatePixelShader(CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader);
	virtual HRESULT SetPixelShader(IDirect3DPixelShader9* pShader);
	virtual HRESULT GetPixelShader(IDirect3DPixelShader9** ppShader);
	virtual HRESULT SetPixelShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount);
	virtual HRESULT GetPixelShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount);
	virtual HRESULT SetPixelShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount);
	virtual HRESULT GetPixelShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount);
	virtual HRESULT SetPixelShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount);
	virtual HRESULT GetPixelShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount);
	virtual HRESULT DrawRectPatch(UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo);
	virtual HRESULT DrawTriPatch(UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo);
	virtual HRESULT DeletePatch(UINT Handle);
	virtual HRESULT CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery);
};

#endif