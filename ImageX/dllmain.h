// dllmain.h : Declaration of module class.

class CImageXModule : public ATL::CAtlDllModuleT< CImageXModule >
{
public :
	DECLARE_LIBID(LIBID_ImageXLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_IMAGEX, "{DC76423D-D591-42CC-9B65-4CD8BC0CF7FE}")
};

extern class CImageXModule _AtlModule;
