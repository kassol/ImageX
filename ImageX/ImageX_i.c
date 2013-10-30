

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IImage,0x889C2904,0x3AFE,0x4920,0xA6,0x59,0xE7,0xDC,0x85,0x75,0x3E,0x0A);


MIDL_DEFINE_GUID(IID, IID_IDEM,0x5155FDA0,0x6464,0x45EE,0x9E,0x72,0x05,0x99,0x55,0xD9,0x87,0x12);


MIDL_DEFINE_GUID(IID, LIBID_ImageXLib,0x64801B79,0x246C,0x45C6,0xBB,0xF7,0x5B,0x7A,0x9F,0xCE,0xA6,0x30);


MIDL_DEFINE_GUID(CLSID, CLSID_ImageDriver,0x80F68129,0x5A4C,0x48EF,0x99,0x49,0x61,0x46,0x6C,0xC4,0x56,0xB2);


MIDL_DEFINE_GUID(CLSID, CLSID_DEMDriver,0xB2789850,0x0375,0x44A1,0x92,0x0E,0xC1,0x91,0x9F,0x0C,0x1A,0x42);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



