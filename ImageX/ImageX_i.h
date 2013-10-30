

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Oct 30 15:03:47 2013
 */
/* Compiler settings for ImageX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ImageX_i_h__
#define __ImageX_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IImage_FWD_DEFINED__
#define __IImage_FWD_DEFINED__
typedef interface IImage IImage;
#endif 	/* __IImage_FWD_DEFINED__ */


#ifndef __IDEM_FWD_DEFINED__
#define __IDEM_FWD_DEFINED__
typedef interface IDEM IDEM;
#endif 	/* __IDEM_FWD_DEFINED__ */


#ifndef __ImageDriver_FWD_DEFINED__
#define __ImageDriver_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImageDriver ImageDriver;
#else
typedef struct ImageDriver ImageDriver;
#endif /* __cplusplus */

#endif 	/* __ImageDriver_FWD_DEFINED__ */


#ifndef __DEMDriver_FWD_DEFINED__
#define __DEMDriver_FWD_DEFINED__

#ifdef __cplusplus
typedef class DEMDriver DEMDriver;
#else
typedef struct DEMDriver DEMDriver;
#endif /* __cplusplus */

#endif 	/* __DEMDriver_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IImage_INTERFACE_DEFINED__
#define __IImage_INTERFACE_DEFINED__

/* interface IImage */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("889C2904-3AFE-4920-A659-E7DC85753E0A")
    IImage : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR bstrPathName,
            /* [in] */ UINT uMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateImg( 
            /* [in] */ BSTR bstrFilePath,
            /* [in] */ UINT uMode,
            /* [in] */ int Cols,
            /* [in] */ int Rows,
            /* [in] */ UINT DataType,
            /* [in] */ int nBandNum,
            /* [in] */ UINT BandType,
            /* [in] */ DOUBLE xStart,
            /* [in] */ DOUBLE yStart,
            /* [in] */ DOUBLE cellSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsGeoCoded( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBandFormat( 
            /* [out] */ UINT *pBandFormat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBandNum( 
            /* [out] */ int *pBandNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRows( 
            /* [out] */ int *pRows) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCols( 
            /* [out] */ int *pCols) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDataType( 
            /* [out] */ UINT *pDataType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetByteOrder( 
            /* [out] */ UINT *pByteOrder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetScale( 
            /* [out] */ FLOAT *pScale) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetScale( 
            /* [in] */ FLOAT Scale) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGrdInfo( 
            /* [out] */ DOUBLE *xStart,
            /* [out] */ DOUBLE *yStart,
            /* [out] */ DOUBLE *cellSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGrdInfo( 
            /* [in] */ DOUBLE xStart,
            /* [in] */ DOUBLE yStart,
            /* [in] */ DOUBLE cellSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HaveColorTable( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEntryNum( 
            /* [out] */ int *pEntryNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetColorTable( 
            /* [out] */ BYTE *pColorTable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetColorTable( 
            /* [in] */ BYTE *pColorTable,
            /* [in] */ int nEntryNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResampleMethod( 
            /* [out] */ int *pResampleMethod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetResampleMethod( 
            /* [in] */ int nResampleMethod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetScanSize( 
            /* [out] */ FLOAT *pScanSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetScanSize( 
            /* [in] */ FLOAT ScanSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBPB( 
            /* [out] */ int *pBPB) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBPP( 
            /* [out] */ int *pBPP) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPathName( 
            /* [out] */ BSTR *bstrPathName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPixel( 
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [out] */ BYTE *pPixel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPixel( 
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [in] */ BYTE *pPixel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGray( 
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [in] */ int nBand,
            /* [out] */ BYTE *gray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGray( 
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [in] */ int nBand,
            /* [out] */ BYTE *gray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPixelF( 
            /* [in] */ FLOAT x,
            /* [in] */ FLOAT y,
            /* [out] */ BYTE *pPixel,
            /* [in] */ UINT nResampleMethod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGrayF( 
            /* [in] */ FLOAT x,
            /* [in] */ FLOAT y,
            /* [in] */ int nBand,
            /* [out] */ BYTE *pGray,
            /* [in] */ int nResampleMethod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadImg( 
            /* [in] */ int nSrcLeft,
            /* [in] */ int nSrcTop,
            /* [in] */ int nSrcRight,
            /* [in] */ int nSrcBottom,
            /* [out] */ BYTE *pBuf,
            /* [in] */ int nBufWid,
            /* [in] */ int nBufHeight,
            /* [in] */ int nBandNum,
            /* [in] */ int nDestLeft,
            /* [in] */ int nDestTop,
            /* [in] */ int nDestRight,
            /* [in] */ int nDestBottom,
            /* [in] */ int nSrcSkip,
            /* [in] */ int nDestSkip) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteImg( 
            /* [in] */ int nSrcLeft,
            /* [in] */ int nSrcTop,
            /* [in] */ int nSrcRight,
            /* [in] */ int nSrcBottom,
            /* [out] */ BYTE *pBuf,
            /* [in] */ int nBufWid,
            /* [in] */ int nBufHeight,
            /* [in] */ int nBandNum,
            /* [in] */ int nDestLeft,
            /* [in] */ int nDestTop,
            /* [in] */ int nDestRight,
            /* [in] */ int nDestBottom,
            /* [in] */ int nSrcSkip,
            /* [in] */ int nDestSkip) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetProgressInterface( 
            IUnknown *pIUnknown) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSupExts( 
            /* [out] */ BYTE *lpszExts,
            /* [in] */ UINT flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Image2World( 
            /* [in] */ FLOAT x,
            /* [in] */ FLOAT y,
            /* [out] */ DOUBLE *pX,
            /* [out] */ DOUBLE *pY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE World2Image( 
            /* [in] */ DOUBLE X,
            /* [in] */ DOUBLE Y,
            /* [out] */ FLOAT *px,
            /* [out] */ FLOAT *py) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDefaultBand( 
            /* [out] */ int *nBandIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCamera( 
            /* [out] */ BSTR *bstrCamera) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCamera( 
            /* [in] */ BSTR bstrCamera) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSensorType( 
            /* [out] */ int *pSensorType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSensorType( 
            /* [in] */ int nSensorType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDPI( 
            /* [out] */ FLOAT *pxDPI,
            /* [out] */ FLOAT *pyDPI) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDPI( 
            /* [in] */ FLOAT xDPI,
            /* [in] */ FLOAT yDPI) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Tiff2JPG( 
            /* [in] */ BSTR bstrTiffPath,
            /* [in] */ BSTR bstrJPGPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IImage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IImage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IImage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IImage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IImage * This,
            /* [in] */ BSTR bstrPathName,
            /* [in] */ UINT uMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateImg )( 
            IImage * This,
            /* [in] */ BSTR bstrFilePath,
            /* [in] */ UINT uMode,
            /* [in] */ int Cols,
            /* [in] */ int Rows,
            /* [in] */ UINT DataType,
            /* [in] */ int nBandNum,
            /* [in] */ UINT BandType,
            /* [in] */ DOUBLE xStart,
            /* [in] */ DOUBLE yStart,
            /* [in] */ DOUBLE cellSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IImage * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsGeoCoded )( 
            IImage * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBandFormat )( 
            IImage * This,
            /* [out] */ UINT *pBandFormat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBandNum )( 
            IImage * This,
            /* [out] */ int *pBandNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRows )( 
            IImage * This,
            /* [out] */ int *pRows);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCols )( 
            IImage * This,
            /* [out] */ int *pCols);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDataType )( 
            IImage * This,
            /* [out] */ UINT *pDataType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetByteOrder )( 
            IImage * This,
            /* [out] */ UINT *pByteOrder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetScale )( 
            IImage * This,
            /* [out] */ FLOAT *pScale);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetScale )( 
            IImage * This,
            /* [in] */ FLOAT Scale);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGrdInfo )( 
            IImage * This,
            /* [out] */ DOUBLE *xStart,
            /* [out] */ DOUBLE *yStart,
            /* [out] */ DOUBLE *cellSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGrdInfo )( 
            IImage * This,
            /* [in] */ DOUBLE xStart,
            /* [in] */ DOUBLE yStart,
            /* [in] */ DOUBLE cellSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HaveColorTable )( 
            IImage * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEntryNum )( 
            IImage * This,
            /* [out] */ int *pEntryNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetColorTable )( 
            IImage * This,
            /* [out] */ BYTE *pColorTable);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetColorTable )( 
            IImage * This,
            /* [in] */ BYTE *pColorTable,
            /* [in] */ int nEntryNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetResampleMethod )( 
            IImage * This,
            /* [out] */ int *pResampleMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetResampleMethod )( 
            IImage * This,
            /* [in] */ int nResampleMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetScanSize )( 
            IImage * This,
            /* [out] */ FLOAT *pScanSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetScanSize )( 
            IImage * This,
            /* [in] */ FLOAT ScanSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBPB )( 
            IImage * This,
            /* [out] */ int *pBPB);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBPP )( 
            IImage * This,
            /* [out] */ int *pBPP);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPathName )( 
            IImage * This,
            /* [out] */ BSTR *bstrPathName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPixel )( 
            IImage * This,
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [out] */ BYTE *pPixel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPixel )( 
            IImage * This,
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [in] */ BYTE *pPixel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGray )( 
            IImage * This,
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [in] */ int nBand,
            /* [out] */ BYTE *gray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGray )( 
            IImage * This,
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [in] */ int nBand,
            /* [out] */ BYTE *gray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPixelF )( 
            IImage * This,
            /* [in] */ FLOAT x,
            /* [in] */ FLOAT y,
            /* [out] */ BYTE *pPixel,
            /* [in] */ UINT nResampleMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGrayF )( 
            IImage * This,
            /* [in] */ FLOAT x,
            /* [in] */ FLOAT y,
            /* [in] */ int nBand,
            /* [out] */ BYTE *pGray,
            /* [in] */ int nResampleMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadImg )( 
            IImage * This,
            /* [in] */ int nSrcLeft,
            /* [in] */ int nSrcTop,
            /* [in] */ int nSrcRight,
            /* [in] */ int nSrcBottom,
            /* [out] */ BYTE *pBuf,
            /* [in] */ int nBufWid,
            /* [in] */ int nBufHeight,
            /* [in] */ int nBandNum,
            /* [in] */ int nDestLeft,
            /* [in] */ int nDestTop,
            /* [in] */ int nDestRight,
            /* [in] */ int nDestBottom,
            /* [in] */ int nSrcSkip,
            /* [in] */ int nDestSkip);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteImg )( 
            IImage * This,
            /* [in] */ int nSrcLeft,
            /* [in] */ int nSrcTop,
            /* [in] */ int nSrcRight,
            /* [in] */ int nSrcBottom,
            /* [out] */ BYTE *pBuf,
            /* [in] */ int nBufWid,
            /* [in] */ int nBufHeight,
            /* [in] */ int nBandNum,
            /* [in] */ int nDestLeft,
            /* [in] */ int nDestTop,
            /* [in] */ int nDestRight,
            /* [in] */ int nDestBottom,
            /* [in] */ int nSrcSkip,
            /* [in] */ int nDestSkip);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetProgressInterface )( 
            IImage * This,
            IUnknown *pIUnknown);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSupExts )( 
            IImage * This,
            /* [out] */ BYTE *lpszExts,
            /* [in] */ UINT flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Image2World )( 
            IImage * This,
            /* [in] */ FLOAT x,
            /* [in] */ FLOAT y,
            /* [out] */ DOUBLE *pX,
            /* [out] */ DOUBLE *pY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *World2Image )( 
            IImage * This,
            /* [in] */ DOUBLE X,
            /* [in] */ DOUBLE Y,
            /* [out] */ FLOAT *px,
            /* [out] */ FLOAT *py);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDefaultBand )( 
            IImage * This,
            /* [out] */ int *nBandIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCamera )( 
            IImage * This,
            /* [out] */ BSTR *bstrCamera);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCamera )( 
            IImage * This,
            /* [in] */ BSTR bstrCamera);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSensorType )( 
            IImage * This,
            /* [out] */ int *pSensorType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSensorType )( 
            IImage * This,
            /* [in] */ int nSensorType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDPI )( 
            IImage * This,
            /* [out] */ FLOAT *pxDPI,
            /* [out] */ FLOAT *pyDPI);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDPI )( 
            IImage * This,
            /* [in] */ FLOAT xDPI,
            /* [in] */ FLOAT yDPI);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Tiff2JPG )( 
            IImage * This,
            /* [in] */ BSTR bstrTiffPath,
            /* [in] */ BSTR bstrJPGPath);
        
        END_INTERFACE
    } IImageVtbl;

    interface IImage
    {
        CONST_VTBL struct IImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IImage_Open(This,bstrPathName,uMode)	\
    ( (This)->lpVtbl -> Open(This,bstrPathName,uMode) ) 

#define IImage_CreateImg(This,bstrFilePath,uMode,Cols,Rows,DataType,nBandNum,BandType,xStart,yStart,cellSize)	\
    ( (This)->lpVtbl -> CreateImg(This,bstrFilePath,uMode,Cols,Rows,DataType,nBandNum,BandType,xStart,yStart,cellSize) ) 

#define IImage_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IImage_IsGeoCoded(This)	\
    ( (This)->lpVtbl -> IsGeoCoded(This) ) 

#define IImage_GetBandFormat(This,pBandFormat)	\
    ( (This)->lpVtbl -> GetBandFormat(This,pBandFormat) ) 

#define IImage_GetBandNum(This,pBandNum)	\
    ( (This)->lpVtbl -> GetBandNum(This,pBandNum) ) 

#define IImage_GetRows(This,pRows)	\
    ( (This)->lpVtbl -> GetRows(This,pRows) ) 

#define IImage_GetCols(This,pCols)	\
    ( (This)->lpVtbl -> GetCols(This,pCols) ) 

#define IImage_GetDataType(This,pDataType)	\
    ( (This)->lpVtbl -> GetDataType(This,pDataType) ) 

#define IImage_GetByteOrder(This,pByteOrder)	\
    ( (This)->lpVtbl -> GetByteOrder(This,pByteOrder) ) 

#define IImage_GetScale(This,pScale)	\
    ( (This)->lpVtbl -> GetScale(This,pScale) ) 

#define IImage_SetScale(This,Scale)	\
    ( (This)->lpVtbl -> SetScale(This,Scale) ) 

#define IImage_GetGrdInfo(This,xStart,yStart,cellSize)	\
    ( (This)->lpVtbl -> GetGrdInfo(This,xStart,yStart,cellSize) ) 

#define IImage_SetGrdInfo(This,xStart,yStart,cellSize)	\
    ( (This)->lpVtbl -> SetGrdInfo(This,xStart,yStart,cellSize) ) 

#define IImage_HaveColorTable(This)	\
    ( (This)->lpVtbl -> HaveColorTable(This) ) 

#define IImage_GetEntryNum(This,pEntryNum)	\
    ( (This)->lpVtbl -> GetEntryNum(This,pEntryNum) ) 

#define IImage_GetColorTable(This,pColorTable)	\
    ( (This)->lpVtbl -> GetColorTable(This,pColorTable) ) 

#define IImage_SetColorTable(This,pColorTable,nEntryNum)	\
    ( (This)->lpVtbl -> SetColorTable(This,pColorTable,nEntryNum) ) 

#define IImage_GetResampleMethod(This,pResampleMethod)	\
    ( (This)->lpVtbl -> GetResampleMethod(This,pResampleMethod) ) 

#define IImage_SetResampleMethod(This,nResampleMethod)	\
    ( (This)->lpVtbl -> SetResampleMethod(This,nResampleMethod) ) 

#define IImage_GetScanSize(This,pScanSize)	\
    ( (This)->lpVtbl -> GetScanSize(This,pScanSize) ) 

#define IImage_SetScanSize(This,ScanSize)	\
    ( (This)->lpVtbl -> SetScanSize(This,ScanSize) ) 

#define IImage_GetBPB(This,pBPB)	\
    ( (This)->lpVtbl -> GetBPB(This,pBPB) ) 

#define IImage_GetBPP(This,pBPP)	\
    ( (This)->lpVtbl -> GetBPP(This,pBPP) ) 

#define IImage_GetPathName(This,bstrPathName)	\
    ( (This)->lpVtbl -> GetPathName(This,bstrPathName) ) 

#define IImage_GetPixel(This,nRows,nCols,pPixel)	\
    ( (This)->lpVtbl -> GetPixel(This,nRows,nCols,pPixel) ) 

#define IImage_SetPixel(This,nRows,nCols,pPixel)	\
    ( (This)->lpVtbl -> SetPixel(This,nRows,nCols,pPixel) ) 

#define IImage_GetGray(This,nRows,nCols,nBand,gray)	\
    ( (This)->lpVtbl -> GetGray(This,nRows,nCols,nBand,gray) ) 

#define IImage_SetGray(This,nRows,nCols,nBand,gray)	\
    ( (This)->lpVtbl -> SetGray(This,nRows,nCols,nBand,gray) ) 

#define IImage_GetPixelF(This,x,y,pPixel,nResampleMethod)	\
    ( (This)->lpVtbl -> GetPixelF(This,x,y,pPixel,nResampleMethod) ) 

#define IImage_GetGrayF(This,x,y,nBand,pGray,nResampleMethod)	\
    ( (This)->lpVtbl -> GetGrayF(This,x,y,nBand,pGray,nResampleMethod) ) 

#define IImage_ReadImg(This,nSrcLeft,nSrcTop,nSrcRight,nSrcBottom,pBuf,nBufWid,nBufHeight,nBandNum,nDestLeft,nDestTop,nDestRight,nDestBottom,nSrcSkip,nDestSkip)	\
    ( (This)->lpVtbl -> ReadImg(This,nSrcLeft,nSrcTop,nSrcRight,nSrcBottom,pBuf,nBufWid,nBufHeight,nBandNum,nDestLeft,nDestTop,nDestRight,nDestBottom,nSrcSkip,nDestSkip) ) 

#define IImage_WriteImg(This,nSrcLeft,nSrcTop,nSrcRight,nSrcBottom,pBuf,nBufWid,nBufHeight,nBandNum,nDestLeft,nDestTop,nDestRight,nDestBottom,nSrcSkip,nDestSkip)	\
    ( (This)->lpVtbl -> WriteImg(This,nSrcLeft,nSrcTop,nSrcRight,nSrcBottom,pBuf,nBufWid,nBufHeight,nBandNum,nDestLeft,nDestTop,nDestRight,nDestBottom,nSrcSkip,nDestSkip) ) 

#define IImage_SetProgressInterface(This,pIUnknown)	\
    ( (This)->lpVtbl -> SetProgressInterface(This,pIUnknown) ) 

#define IImage_GetSupExts(This,lpszExts,flags)	\
    ( (This)->lpVtbl -> GetSupExts(This,lpszExts,flags) ) 

#define IImage_Image2World(This,x,y,pX,pY)	\
    ( (This)->lpVtbl -> Image2World(This,x,y,pX,pY) ) 

#define IImage_World2Image(This,X,Y,px,py)	\
    ( (This)->lpVtbl -> World2Image(This,X,Y,px,py) ) 

#define IImage_GetDefaultBand(This,nBandIndex)	\
    ( (This)->lpVtbl -> GetDefaultBand(This,nBandIndex) ) 

#define IImage_GetCamera(This,bstrCamera)	\
    ( (This)->lpVtbl -> GetCamera(This,bstrCamera) ) 

#define IImage_SetCamera(This,bstrCamera)	\
    ( (This)->lpVtbl -> SetCamera(This,bstrCamera) ) 

#define IImage_GetSensorType(This,pSensorType)	\
    ( (This)->lpVtbl -> GetSensorType(This,pSensorType) ) 

#define IImage_SetSensorType(This,nSensorType)	\
    ( (This)->lpVtbl -> SetSensorType(This,nSensorType) ) 

#define IImage_GetDPI(This,pxDPI,pyDPI)	\
    ( (This)->lpVtbl -> GetDPI(This,pxDPI,pyDPI) ) 

#define IImage_SetDPI(This,xDPI,yDPI)	\
    ( (This)->lpVtbl -> SetDPI(This,xDPI,yDPI) ) 

#define IImage_Tiff2JPG(This,bstrTiffPath,bstrJPGPath)	\
    ( (This)->lpVtbl -> Tiff2JPG(This,bstrTiffPath,bstrJPGPath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImage_INTERFACE_DEFINED__ */


#ifndef __IDEM_INTERFACE_DEFINED__
#define __IDEM_INTERFACE_DEFINED__

/* interface IDEM */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDEM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5155FDA0-6464-45EE-9E72-059955D98712")
    IDEM : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCellSize( 
            /* [out] */ DOUBLE *pXCellSize,
            /* [out] */ DOUBLE *pYCellSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRange( 
            /* [out] */ DOUBLE *pLBX,
            /* [out] */ DOUBLE *pLBY,
            /* [out] */ DOUBLE *pRTX,
            /* [out] */ DOUBLE *pRTY) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTIN( 
            /* [in] */ DWORD ppTriangulateio) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSupExts( 
            /* [out] */ BYTE *lpszExts,
            /* [in] */ UINT accMode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSupFormats( 
            /* [out] */ BYTE *lpszFormats,
            /* [in] */ UINT accMode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetIImage( 
            /* [out] */ IImage **ppIImage) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetVertex( 
            /* [out] */ DOUBLE *pX,
            /* [out] */ DOUBLE *pY,
            /* [out] */ DOUBLE *pZ,
            /* [out] */ int *pVertexNum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTriangle( 
            int nTriIndex,
            DOUBLE *pX,
            DOUBLE *pY,
            DOUBLE *pZ) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTriangleNum( 
            /* [out] */ int *pTriangleNum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ConstrustTIN( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAverageAltitude( 
            /* [out] */ DOUBLE *pZ) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAltitude( 
            /* [in] */ DOUBLE X,
            /* [in] */ DOUBLE Y,
            /* [out] */ DOUBLE *pZ,
            /* [in] */ UINT uResampleMethod) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ BSTR bstrPathName,
            /* [in] */ BSTR bstrFormat,
            /* [in] */ UINT accMode,
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [in] */ DOUBLE LBX,
            /* [in] */ DOUBLE LBY,
            /* [in] */ DOUBLE XCellSize,
            /* [in] */ DOUBLE YCellSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR bstrPathName,
            /* [in] */ DOUBLE lfAltitudeOffset,
            /* [in] */ UINT accMode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetMaxAltitude( 
            /* [out] */ DOUBLE *pZ) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetMinAltitude( 
            /* [out] */ DOUBLE *pZ) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetType( 
            /* [out] */ UINT *pType) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRows( 
            /* [out] */ int *pRows) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCols( 
            /* [out] */ int *pCols) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetStartPos( 
            /* [out] */ DOUBLE *pX0,
            /* [out] */ DOUBLE *pY0) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAltitudeValues( 
            /* [out] */ DOUBLE *pZ) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsSupported( 
            /* [in] */ BSTR bstrPathName,
            /* [in] */ UINT accMode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExportTin( 
            /* [in] */ BSTR bstrTinFile) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TIN2DEM( 
            /* [in] */ BSTR bstrDEMFile,
            /* [in] */ DOUBLE LBX,
            /* [in] */ DOUBLE LBY,
            /* [in] */ DOUBLE RTX,
            /* [in] */ DOUBLE RTY,
            /* [in] */ DOUBLE lfCellSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateFeatureDEM( 
            /* [in] */ BSTR bstrRasterDEMFile,
            /* [in] */ BSTR bstrFeatureFile,
            /* [in] */ DOUBLE lfBufferSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetRange( 
            /* [in] */ DOUBLE LBX,
            /* [in] */ DOUBLE LBY,
            /* [in] */ DOUBLE RTX,
            /* [in] */ DOUBLE RTY,
            /* [in] */ DOUBLE CellSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCellSize( 
            /* [in] */ DOUBLE CellSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFlatAltitude( 
            /* [in] */ DOUBLE Z) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateFlatDEM( 
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [in] */ DOUBLE LBX,
            /* [in] */ DOUBLE LBY,
            /* [in] */ DOUBLE Altitude,
            /* [in] */ DOUBLE CellSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateGCPDEM( 
            /* [in] */ BSTR bstrGcpFile) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetBufferSize( 
            /* [in] */ DOUBLE lfBufferSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetBufferSize( 
            /* [out] */ DOUBLE *pBufferSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateVectorDEM( 
            /* [in] */ BSTR bstrVectorFile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDEMVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDEM * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDEM * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDEM * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDEM * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDEM * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDEM * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDEM * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCellSize )( 
            IDEM * This,
            /* [out] */ DOUBLE *pXCellSize,
            /* [out] */ DOUBLE *pYCellSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetRange )( 
            IDEM * This,
            /* [out] */ DOUBLE *pLBX,
            /* [out] */ DOUBLE *pLBY,
            /* [out] */ DOUBLE *pRTX,
            /* [out] */ DOUBLE *pRTY);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTIN )( 
            IDEM * This,
            /* [in] */ DWORD ppTriangulateio);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IDEM * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSupExts )( 
            IDEM * This,
            /* [out] */ BYTE *lpszExts,
            /* [in] */ UINT accMode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSupFormats )( 
            IDEM * This,
            /* [out] */ BYTE *lpszFormats,
            /* [in] */ UINT accMode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetIImage )( 
            IDEM * This,
            /* [out] */ IImage **ppIImage);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetVertex )( 
            IDEM * This,
            /* [out] */ DOUBLE *pX,
            /* [out] */ DOUBLE *pY,
            /* [out] */ DOUBLE *pZ,
            /* [out] */ int *pVertexNum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTriangle )( 
            IDEM * This,
            int nTriIndex,
            DOUBLE *pX,
            DOUBLE *pY,
            DOUBLE *pZ);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTriangleNum )( 
            IDEM * This,
            /* [out] */ int *pTriangleNum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ConstrustTIN )( 
            IDEM * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAverageAltitude )( 
            IDEM * This,
            /* [out] */ DOUBLE *pZ);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAltitude )( 
            IDEM * This,
            /* [in] */ DOUBLE X,
            /* [in] */ DOUBLE Y,
            /* [out] */ DOUBLE *pZ,
            /* [in] */ UINT uResampleMethod);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            IDEM * This,
            /* [in] */ BSTR bstrPathName,
            /* [in] */ BSTR bstrFormat,
            /* [in] */ UINT accMode,
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [in] */ DOUBLE LBX,
            /* [in] */ DOUBLE LBY,
            /* [in] */ DOUBLE XCellSize,
            /* [in] */ DOUBLE YCellSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IDEM * This,
            /* [in] */ BSTR bstrPathName,
            /* [in] */ DOUBLE lfAltitudeOffset,
            /* [in] */ UINT accMode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetMaxAltitude )( 
            IDEM * This,
            /* [out] */ DOUBLE *pZ);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetMinAltitude )( 
            IDEM * This,
            /* [out] */ DOUBLE *pZ);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IDEM * This,
            /* [out] */ UINT *pType);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetRows )( 
            IDEM * This,
            /* [out] */ int *pRows);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCols )( 
            IDEM * This,
            /* [out] */ int *pCols);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetStartPos )( 
            IDEM * This,
            /* [out] */ DOUBLE *pX0,
            /* [out] */ DOUBLE *pY0);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAltitudeValues )( 
            IDEM * This,
            /* [out] */ DOUBLE *pZ);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsSupported )( 
            IDEM * This,
            /* [in] */ BSTR bstrPathName,
            /* [in] */ UINT accMode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExportTin )( 
            IDEM * This,
            /* [in] */ BSTR bstrTinFile);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TIN2DEM )( 
            IDEM * This,
            /* [in] */ BSTR bstrDEMFile,
            /* [in] */ DOUBLE LBX,
            /* [in] */ DOUBLE LBY,
            /* [in] */ DOUBLE RTX,
            /* [in] */ DOUBLE RTY,
            /* [in] */ DOUBLE lfCellSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateFeatureDEM )( 
            IDEM * This,
            /* [in] */ BSTR bstrRasterDEMFile,
            /* [in] */ BSTR bstrFeatureFile,
            /* [in] */ DOUBLE lfBufferSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetRange )( 
            IDEM * This,
            /* [in] */ DOUBLE LBX,
            /* [in] */ DOUBLE LBY,
            /* [in] */ DOUBLE RTX,
            /* [in] */ DOUBLE RTY,
            /* [in] */ DOUBLE CellSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCellSize )( 
            IDEM * This,
            /* [in] */ DOUBLE CellSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFlatAltitude )( 
            IDEM * This,
            /* [in] */ DOUBLE Z);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateFlatDEM )( 
            IDEM * This,
            /* [in] */ int nRows,
            /* [in] */ int nCols,
            /* [in] */ DOUBLE LBX,
            /* [in] */ DOUBLE LBY,
            /* [in] */ DOUBLE Altitude,
            /* [in] */ DOUBLE CellSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateGCPDEM )( 
            IDEM * This,
            /* [in] */ BSTR bstrGcpFile);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetBufferSize )( 
            IDEM * This,
            /* [in] */ DOUBLE lfBufferSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetBufferSize )( 
            IDEM * This,
            /* [out] */ DOUBLE *pBufferSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateVectorDEM )( 
            IDEM * This,
            /* [in] */ BSTR bstrVectorFile);
        
        END_INTERFACE
    } IDEMVtbl;

    interface IDEM
    {
        CONST_VTBL struct IDEMVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDEM_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDEM_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDEM_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDEM_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDEM_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDEM_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDEM_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDEM_GetCellSize(This,pXCellSize,pYCellSize)	\
    ( (This)->lpVtbl -> GetCellSize(This,pXCellSize,pYCellSize) ) 

#define IDEM_GetRange(This,pLBX,pLBY,pRTX,pRTY)	\
    ( (This)->lpVtbl -> GetRange(This,pLBX,pLBY,pRTX,pRTY) ) 

#define IDEM_GetTIN(This,ppTriangulateio)	\
    ( (This)->lpVtbl -> GetTIN(This,ppTriangulateio) ) 

#define IDEM_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IDEM_GetSupExts(This,lpszExts,accMode)	\
    ( (This)->lpVtbl -> GetSupExts(This,lpszExts,accMode) ) 

#define IDEM_GetSupFormats(This,lpszFormats,accMode)	\
    ( (This)->lpVtbl -> GetSupFormats(This,lpszFormats,accMode) ) 

#define IDEM_GetIImage(This,ppIImage)	\
    ( (This)->lpVtbl -> GetIImage(This,ppIImage) ) 

#define IDEM_GetVertex(This,pX,pY,pZ,pVertexNum)	\
    ( (This)->lpVtbl -> GetVertex(This,pX,pY,pZ,pVertexNum) ) 

#define IDEM_GetTriangle(This,nTriIndex,pX,pY,pZ)	\
    ( (This)->lpVtbl -> GetTriangle(This,nTriIndex,pX,pY,pZ) ) 

#define IDEM_GetTriangleNum(This,pTriangleNum)	\
    ( (This)->lpVtbl -> GetTriangleNum(This,pTriangleNum) ) 

#define IDEM_ConstrustTIN(This)	\
    ( (This)->lpVtbl -> ConstrustTIN(This) ) 

#define IDEM_GetAverageAltitude(This,pZ)	\
    ( (This)->lpVtbl -> GetAverageAltitude(This,pZ) ) 

#define IDEM_GetAltitude(This,X,Y,pZ,uResampleMethod)	\
    ( (This)->lpVtbl -> GetAltitude(This,X,Y,pZ,uResampleMethod) ) 

#define IDEM_Create(This,bstrPathName,bstrFormat,accMode,nRows,nCols,LBX,LBY,XCellSize,YCellSize)	\
    ( (This)->lpVtbl -> Create(This,bstrPathName,bstrFormat,accMode,nRows,nCols,LBX,LBY,XCellSize,YCellSize) ) 

#define IDEM_Open(This,bstrPathName,lfAltitudeOffset,accMode)	\
    ( (This)->lpVtbl -> Open(This,bstrPathName,lfAltitudeOffset,accMode) ) 

#define IDEM_GetMaxAltitude(This,pZ)	\
    ( (This)->lpVtbl -> GetMaxAltitude(This,pZ) ) 

#define IDEM_GetMinAltitude(This,pZ)	\
    ( (This)->lpVtbl -> GetMinAltitude(This,pZ) ) 

#define IDEM_GetType(This,pType)	\
    ( (This)->lpVtbl -> GetType(This,pType) ) 

#define IDEM_GetRows(This,pRows)	\
    ( (This)->lpVtbl -> GetRows(This,pRows) ) 

#define IDEM_GetCols(This,pCols)	\
    ( (This)->lpVtbl -> GetCols(This,pCols) ) 

#define IDEM_GetStartPos(This,pX0,pY0)	\
    ( (This)->lpVtbl -> GetStartPos(This,pX0,pY0) ) 

#define IDEM_GetAltitudeValues(This,pZ)	\
    ( (This)->lpVtbl -> GetAltitudeValues(This,pZ) ) 

#define IDEM_IsSupported(This,bstrPathName,accMode)	\
    ( (This)->lpVtbl -> IsSupported(This,bstrPathName,accMode) ) 

#define IDEM_ExportTin(This,bstrTinFile)	\
    ( (This)->lpVtbl -> ExportTin(This,bstrTinFile) ) 

#define IDEM_TIN2DEM(This,bstrDEMFile,LBX,LBY,RTX,RTY,lfCellSize)	\
    ( (This)->lpVtbl -> TIN2DEM(This,bstrDEMFile,LBX,LBY,RTX,RTY,lfCellSize) ) 

#define IDEM_CreateFeatureDEM(This,bstrRasterDEMFile,bstrFeatureFile,lfBufferSize)	\
    ( (This)->lpVtbl -> CreateFeatureDEM(This,bstrRasterDEMFile,bstrFeatureFile,lfBufferSize) ) 

#define IDEM_SetRange(This,LBX,LBY,RTX,RTY,CellSize)	\
    ( (This)->lpVtbl -> SetRange(This,LBX,LBY,RTX,RTY,CellSize) ) 

#define IDEM_SetCellSize(This,CellSize)	\
    ( (This)->lpVtbl -> SetCellSize(This,CellSize) ) 

#define IDEM_SetFlatAltitude(This,Z)	\
    ( (This)->lpVtbl -> SetFlatAltitude(This,Z) ) 

#define IDEM_CreateFlatDEM(This,nRows,nCols,LBX,LBY,Altitude,CellSize)	\
    ( (This)->lpVtbl -> CreateFlatDEM(This,nRows,nCols,LBX,LBY,Altitude,CellSize) ) 

#define IDEM_CreateGCPDEM(This,bstrGcpFile)	\
    ( (This)->lpVtbl -> CreateGCPDEM(This,bstrGcpFile) ) 

#define IDEM_SetBufferSize(This,lfBufferSize)	\
    ( (This)->lpVtbl -> SetBufferSize(This,lfBufferSize) ) 

#define IDEM_GetBufferSize(This,pBufferSize)	\
    ( (This)->lpVtbl -> GetBufferSize(This,pBufferSize) ) 

#define IDEM_CreateVectorDEM(This,bstrVectorFile)	\
    ( (This)->lpVtbl -> CreateVectorDEM(This,bstrVectorFile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDEM_INTERFACE_DEFINED__ */



#ifndef __ImageXLib_LIBRARY_DEFINED__
#define __ImageXLib_LIBRARY_DEFINED__

/* library ImageXLib */
/* [version][uuid] */ 


enum OpenFlags
    {	modeRead	= 0,
	modeWrite	= 0x1,
	modeReadWrite	= 0x2,
	modeJpegCompress	= 0x4,
	modePyramidCreate	= 0x100,
	modePyramidClean	= 0x200,
	modeAqlut	= 0x400,
	modeEnhance	= 0xc,
	modePyramidRead	= 0x800,
	shareCompat	= 0,
	shareExclusive	= 0x10,
	shareDenyWrite	= 0x20,
	shareDenyRead	= 0x30,
	shareDenyNone	= 0x40,
	modeNoInherit	= 0x80,
	modeCreate	= 0x1000,
	modeNoTruncate	= 0x2000,
	modePropertyOnly	= 0x4000,
	modeDemHeaderOnly	= 0x8000
    } ;

enum Altitude
    {	INVALID_ALTITUDE	= -99999
    } ;

enum DEMType
    {	DT_GRID	= 0,
	DT_TIN	= 1
    } ;
typedef /* [public] */ 
enum __MIDL___MIDL_itf_ImageX_0000_0002_0001
    {	BIP	= 0,
	BIL	= ( BIP + 1 ) ,
	BSQ	= ( BIL + 1 ) 
    } 	BandFormat;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_ImageX_0000_0002_0002
    {	Intel	= 0,
	IEEE	= ( Intel + 1 ) 
    } 	ByteOrder;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_ImageX_0000_0002_0003
    {	Pixel_Byte	= 0,
	Pixel_Int16	= ( Pixel_Byte + 1 ) ,
	Pixel_SInt16	= ( Pixel_Int16 + 1 ) ,
	Pixel_Int32	= ( Pixel_SInt16 + 1 ) ,
	Pixel_SInt32	= ( Pixel_Int32 + 1 ) ,
	Pixel_Float	= ( Pixel_SInt32 + 1 ) ,
	Pixel_Double	= ( Pixel_Float + 1 ) ,
	Pixel_Int64	= ( Pixel_Double + 1 ) ,
	Pixel_SInt64	= ( Pixel_Int64 + 1 ) 
    } 	DataType;


EXTERN_C const IID LIBID_ImageXLib;

EXTERN_C const CLSID CLSID_ImageDriver;

#ifdef __cplusplus

class DECLSPEC_UUID("80F68129-5A4C-48EF-9949-61466CC456B2")
ImageDriver;
#endif

EXTERN_C const CLSID CLSID_DEMDriver;

#ifdef __cplusplus

class DECLSPEC_UUID("B2789850-0375-44A1-920E-C1919F0C1A42")
DEMDriver;
#endif
#endif /* __ImageXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


