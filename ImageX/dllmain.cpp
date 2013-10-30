// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "ImageX_i.h"
#include "dllmain.h"

CImageXModule _AtlModule;

class CImageXApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CImageXApp, CWinApp)
END_MESSAGE_MAP()

CImageXApp theApp;

BOOL CImageXApp::InitInstance()
{
	return CWinApp::InitInstance();
}

int CImageXApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}