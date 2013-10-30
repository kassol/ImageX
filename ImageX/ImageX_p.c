

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "ImageX_i.h"

#define TYPE_FORMAT_STRING_SIZE   121                               
#define PROC_FORMAT_STRING_SIZE   3379                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _ImageX_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } ImageX_MIDL_TYPE_FORMAT_STRING;

typedef struct _ImageX_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } ImageX_MIDL_PROC_FORMAT_STRING;

typedef struct _ImageX_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } ImageX_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const ImageX_MIDL_TYPE_FORMAT_STRING ImageX__MIDL_TypeFormatString;
extern const ImageX_MIDL_PROC_FORMAT_STRING ImageX__MIDL_ProcFormatString;
extern const ImageX_MIDL_EXPR_FORMAT_STRING ImageX__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IImage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IImage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDEM_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDEM_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const ImageX_MIDL_PROC_FORMAT_STRING ImageX__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Open */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x1 ),	/* 1 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrPathName */

/* 24 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter uMode */

/* 30 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateImg */

/* 42 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 44 */	NdrFcLong( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 52 */	NdrFcShort( 0x60 ),	/* 96 */
/* 54 */	NdrFcShort( 0x8 ),	/* 8 */
/* 56 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 58 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x1 ),	/* 1 */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrFilePath */

/* 66 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 68 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 70 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter uMode */

/* 72 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 74 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 76 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Cols */

/* 78 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 80 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Rows */

/* 84 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 86 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 88 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter DataType */

/* 90 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 92 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 94 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBandNum */

/* 96 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 98 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter BandType */

/* 102 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 104 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter xStart */

/* 108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 110 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 112 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yStart */

/* 114 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 116 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 118 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cellSize */

/* 120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 122 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 124 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 128 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */

/* 132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x9 ),	/* 9 */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 146 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 148 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */


	/* Procedure IsGeoCoded */

/* 162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0xa ),	/* 10 */
/* 170 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 176 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 178 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBandFormat */

/* 192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0xb ),	/* 11 */
/* 200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x24 ),	/* 36 */
/* 206 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 208 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBandFormat */

/* 216 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBandNum */

/* 228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0xc ),	/* 12 */
/* 236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x24 ),	/* 36 */
/* 242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 244 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBandNum */

/* 252 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRows */

/* 264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0xd ),	/* 13 */
/* 272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x24 ),	/* 36 */
/* 278 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 280 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRows */

/* 288 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCols */

/* 300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0xe ),	/* 14 */
/* 308 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x24 ),	/* 36 */
/* 314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 316 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCols */

/* 324 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDataType */

/* 336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0xf ),	/* 15 */
/* 344 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x24 ),	/* 36 */
/* 350 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 352 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataType */

/* 360 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTriangleNum */


	/* Procedure GetByteOrder */

/* 372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x10 ),	/* 16 */
/* 380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x24 ),	/* 36 */
/* 386 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 388 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTriangleNum */


	/* Parameter pByteOrder */

/* 396 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 398 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 404 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetScale */

/* 408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x11 ),	/* 17 */
/* 416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x24 ),	/* 36 */
/* 422 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 424 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScale */

/* 432 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 434 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 436 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetScale */

/* 444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x12 ),	/* 18 */
/* 452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 458 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Scale */

/* 468 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 472 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGrdInfo */

/* 480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x13 ),	/* 19 */
/* 488 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x74 ),	/* 116 */
/* 494 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter xStart */

/* 504 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 508 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yStart */

/* 510 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 514 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cellSize */

/* 516 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 518 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 520 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 524 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetGrdInfo */

/* 528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0x14 ),	/* 20 */
/* 536 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 538 */	NdrFcShort( 0x30 ),	/* 48 */
/* 540 */	NdrFcShort( 0x8 ),	/* 8 */
/* 542 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 544 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter xStart */

/* 552 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 554 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 556 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yStart */

/* 558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 560 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 562 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cellSize */

/* 564 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 566 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 568 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 572 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HaveColorTable */

/* 576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x15 ),	/* 21 */
/* 584 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 590 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 592 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 602 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEntryNum */

/* 606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 612 */	NdrFcShort( 0x16 ),	/* 22 */
/* 614 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0x24 ),	/* 36 */
/* 620 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 622 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEntryNum */

/* 630 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 632 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 638 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetColorTable */

/* 642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x17 ),	/* 23 */
/* 650 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x21 ),	/* 33 */
/* 656 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 658 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pColorTable */

/* 666 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 670 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 674 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetColorTable */

/* 678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x18 ),	/* 24 */
/* 686 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 688 */	NdrFcShort( 0x21 ),	/* 33 */
/* 690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 692 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 694 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pColorTable */

/* 702 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 704 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 706 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nEntryNum */

/* 708 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 710 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 716 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRows */


	/* Procedure GetResampleMethod */

/* 720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x19 ),	/* 25 */
/* 728 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x24 ),	/* 36 */
/* 734 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 736 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRows */


	/* Parameter pResampleMethod */

/* 744 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 746 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 752 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResampleMethod */

/* 756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x1a ),	/* 26 */
/* 764 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 772 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nResampleMethod */

/* 780 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetScanSize */

/* 792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x1b ),	/* 27 */
/* 800 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x24 ),	/* 36 */
/* 806 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 808 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanSize */

/* 816 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 820 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 824 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetScanSize */

/* 828 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0x1c ),	/* 28 */
/* 836 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 842 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 844 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ScanSize */

/* 852 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 854 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 856 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBPB */

/* 864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x1d ),	/* 29 */
/* 872 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x24 ),	/* 36 */
/* 878 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 880 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBPB */

/* 888 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 890 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 896 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBPP */

/* 900 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x1e ),	/* 30 */
/* 908 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x24 ),	/* 36 */
/* 914 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 916 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBPP */

/* 924 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 926 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 930 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 932 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPathName */

/* 936 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 938 */	NdrFcLong( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x1f ),	/* 31 */
/* 944 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 948 */	NdrFcShort( 0x8 ),	/* 8 */
/* 950 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 952 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 954 */	NdrFcShort( 0x1 ),	/* 1 */
/* 956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrPathName */

/* 960 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 962 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 964 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 966 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 968 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPixel */

/* 972 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 974 */	NdrFcLong( 0x0 ),	/* 0 */
/* 978 */	NdrFcShort( 0x20 ),	/* 32 */
/* 980 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 982 */	NdrFcShort( 0x10 ),	/* 16 */
/* 984 */	NdrFcShort( 0x21 ),	/* 33 */
/* 986 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 988 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nRows */

/* 996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 998 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nCols */

/* 1002 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1004 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPixel */

/* 1008 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1010 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1012 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 1014 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1016 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPixel */

/* 1020 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1026 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1028 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1030 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1032 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1034 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1036 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nRows */

/* 1044 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1046 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nCols */

/* 1050 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1052 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPixel */

/* 1056 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1058 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1060 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 1062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1064 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGray */

/* 1068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1076 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1078 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1080 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1082 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 1084 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nRows */

/* 1092 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1094 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nCols */

/* 1098 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1100 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBand */

/* 1104 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1106 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter gray */

/* 1110 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1112 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1114 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 1116 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1118 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetGray */

/* 1122 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1130 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1132 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1134 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1136 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 1138 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nRows */

/* 1146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1148 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nCols */

/* 1152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1154 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBand */

/* 1158 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1160 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter gray */

/* 1164 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1166 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1168 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 1170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1172 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPixelF */

/* 1176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1184 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1186 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1188 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1190 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 1192 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 1200 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1202 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1204 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter y */

/* 1206 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1208 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1210 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter pPixel */

/* 1212 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1214 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1216 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nResampleMethod */

/* 1218 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1220 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1226 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGrayF */

/* 1230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1238 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1240 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1242 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1244 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 1246 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 1254 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1256 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1258 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter y */

/* 1260 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1262 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1264 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter nBand */

/* 1266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1268 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pGray */

/* 1272 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1274 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1276 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nResampleMethod */

/* 1278 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1280 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1286 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadImg */

/* 1290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1298 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 1300 */	NdrFcShort( 0x68 ),	/* 104 */
/* 1302 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1304 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0xf,		/* 15 */
/* 1306 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nSrcLeft */

/* 1314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1316 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSrcTop */

/* 1320 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1322 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSrcRight */

/* 1326 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1328 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSrcBottom */

/* 1332 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1334 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBuf */

/* 1338 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1340 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1342 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nBufWid */

/* 1344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1346 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBufHeight */

/* 1350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1352 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBandNum */

/* 1356 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1358 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nDestLeft */

/* 1362 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1364 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nDestTop */

/* 1368 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1370 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nDestRight */

/* 1374 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1376 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nDestBottom */

/* 1380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1382 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSrcSkip */

/* 1386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1388 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nDestSkip */

/* 1392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1394 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1398 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1400 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 1402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteImg */

/* 1404 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1410 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1412 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 1414 */	NdrFcShort( 0x68 ),	/* 104 */
/* 1416 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1418 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0xf,		/* 15 */
/* 1420 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nSrcLeft */

/* 1428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1430 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSrcTop */

/* 1434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1436 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSrcRight */

/* 1440 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1442 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSrcBottom */

/* 1446 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1448 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBuf */

/* 1452 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1454 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1456 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nBufWid */

/* 1458 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1460 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBufHeight */

/* 1464 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1466 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBandNum */

/* 1470 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1472 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nDestLeft */

/* 1476 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1478 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nDestTop */

/* 1482 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1484 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nDestRight */

/* 1488 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1490 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nDestBottom */

/* 1494 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1496 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSrcSkip */

/* 1500 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1502 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 1504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nDestSkip */

/* 1506 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1508 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 1510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1512 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1514 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 1516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetProgressInterface */

/* 1518 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1526 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1532 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1534 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIUnknown */

/* 1542 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1544 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1546 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */

	/* Return value */

/* 1548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1550 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSupExts */

/* 1554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1562 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1566 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1568 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1570 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lpszExts */

/* 1578 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1580 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1582 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter flags */

/* 1584 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1586 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1592 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Image2World */

/* 1596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1604 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1606 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1608 */	NdrFcShort( 0x50 ),	/* 80 */
/* 1610 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 1612 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 1620 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1622 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1624 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter y */

/* 1626 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1628 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1630 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter pX */

/* 1632 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1634 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1636 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pY */

/* 1638 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1640 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1642 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 1644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1646 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure World2Image */

/* 1650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1656 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1658 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1660 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1662 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1664 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 1666 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter X */

/* 1674 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1676 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1678 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter Y */

/* 1680 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1682 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1684 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter px */

/* 1686 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1688 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1690 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter py */

/* 1692 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1694 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1696 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 1698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1700 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDefaultBand */

/* 1704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1712 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1716 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1718 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1720 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nBandIndex */

/* 1728 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1730 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCamera */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1748 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1754 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1756 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1758 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrCamera */

/* 1764 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1766 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1768 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1772 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCamera */

/* 1776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1784 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1790 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1792 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrCamera */

/* 1800 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1802 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1804 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 1806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1808 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSensorType */

/* 1812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1820 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1826 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1828 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSensorType */

/* 1836 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1838 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1844 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSensorType */

/* 1848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1856 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1862 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1864 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nSensorType */

/* 1872 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1874 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1880 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDPI */

/* 1884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1892 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1898 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1900 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1906 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pxDPI */

/* 1908 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1910 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1912 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter pyDPI */

/* 1914 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1918 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 1920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1922 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDPI */

/* 1926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1934 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1936 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1940 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1942 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter xDPI */

/* 1950 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1952 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1954 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Parameter yDPI */

/* 1956 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1958 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1960 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 1962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1964 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Tiff2JPG */

/* 1968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1974 */	NdrFcShort( 0x33 ),	/* 51 */
/* 1976 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1982 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1984 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1988 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1990 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrTiffPath */

/* 1992 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1994 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1996 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter bstrJPGPath */

/* 1998 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2000 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2002 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 2004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2006 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCellSize */

/* 2010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2018 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2022 */	NdrFcShort( 0x50 ),	/* 80 */
/* 2024 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2026 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2032 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pXCellSize */

/* 2034 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2036 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2038 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pYCellSize */

/* 2040 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2042 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2044 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2046 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2048 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRange */

/* 2052 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2054 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2058 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2060 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2064 */	NdrFcShort( 0x98 ),	/* 152 */
/* 2066 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2068 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2074 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLBX */

/* 2076 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2078 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2080 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pLBY */

/* 2082 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2084 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2086 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pRTX */

/* 2088 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2090 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2092 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pRTY */

/* 2094 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2096 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2098 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2102 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTIN */

/* 2106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2112 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2120 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2122 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppTriangulateio */

/* 2130 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2132 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2136 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2138 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSupExts */

/* 2142 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0xb ),	/* 11 */
/* 2150 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2154 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2156 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2158 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2164 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lpszExts */

/* 2166 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2168 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2170 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter accMode */

/* 2172 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2174 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2178 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2180 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSupFormats */

/* 2184 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2186 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2190 */	NdrFcShort( 0xc ),	/* 12 */
/* 2192 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2196 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2198 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2200 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lpszFormats */

/* 2208 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2210 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2212 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter accMode */

/* 2214 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2216 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2222 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIImage */

/* 2226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0xd ),	/* 13 */
/* 2234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2240 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2242 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIImage */

/* 2250 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2252 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2254 */	NdrFcShort( 0x5e ),	/* Type Offset=94 */

	/* Return value */

/* 2256 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2258 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVertex */

/* 2262 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2264 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2268 */	NdrFcShort( 0xe ),	/* 14 */
/* 2270 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2274 */	NdrFcShort( 0x90 ),	/* 144 */
/* 2276 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2278 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2284 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pX */

/* 2286 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2288 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2290 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pY */

/* 2292 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2294 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2296 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pZ */

/* 2298 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2300 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2302 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pVertexNum */

/* 2304 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2306 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2312 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTriangle */

/* 2316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2322 */	NdrFcShort( 0xf ),	/* 15 */
/* 2324 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2326 */	NdrFcShort( 0x74 ),	/* 116 */
/* 2328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2330 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2332 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2338 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nTriIndex */

/* 2340 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2342 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pX */

/* 2346 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2348 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2350 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pY */

/* 2352 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2354 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2356 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pZ */

/* 2358 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2360 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2362 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2364 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2366 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConstrustTIN */

/* 2370 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2376 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2378 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2384 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2386 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2392 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2396 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAverageAltitude */

/* 2400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2406 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2408 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2412 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2414 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2416 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pZ */

/* 2424 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2426 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2428 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2432 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAltitude */

/* 2436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2442 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2444 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2446 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2448 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2450 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2452 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter X */

/* 2460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2462 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2464 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter Y */

/* 2466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2468 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2470 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pZ */

/* 2472 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2474 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2476 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter uResampleMethod */

/* 2478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2480 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2486 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create */

/* 2490 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2498 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 2500 */	NdrFcShort( 0x58 ),	/* 88 */
/* 2502 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2504 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xa,		/* 10 */
/* 2506 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2510 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2512 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrPathName */

/* 2514 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2518 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter bstrFormat */

/* 2520 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2524 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter accMode */

/* 2526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2528 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nRows */

/* 2532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2534 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nCols */

/* 2538 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2540 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter LBX */

/* 2544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2546 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2548 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter LBY */

/* 2550 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2552 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2554 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter XCellSize */

/* 2556 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2558 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2560 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter YCellSize */

/* 2562 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2564 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2566 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2568 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2570 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 2572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Open */

/* 2574 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2576 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2580 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2582 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2584 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2588 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2590 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2594 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2596 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrPathName */

/* 2598 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2600 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2602 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter lfAltitudeOffset */

/* 2604 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2606 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2608 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter accMode */

/* 2610 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2612 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2616 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2618 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxAltitude */

/* 2622 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2628 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2630 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2634 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2636 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2638 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2644 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pZ */

/* 2646 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2648 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2650 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2652 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2654 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMinAltitude */

/* 2658 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2660 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2664 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2666 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2670 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2672 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2674 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2680 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pZ */

/* 2682 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2684 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2686 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2688 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2690 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetType */

/* 2694 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2700 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2702 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2706 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2708 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2710 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2716 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 2718 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2720 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2726 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCols */

/* 2730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2736 */	NdrFcShort( 0x1a ),	/* 26 */
/* 2738 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2742 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2744 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2746 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2752 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCols */

/* 2754 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2756 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2760 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2762 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2764 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStartPos */

/* 2766 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2768 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2772 */	NdrFcShort( 0x1b ),	/* 27 */
/* 2774 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2778 */	NdrFcShort( 0x50 ),	/* 80 */
/* 2780 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2782 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2788 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pX0 */

/* 2790 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2792 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2794 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pY0 */

/* 2796 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2798 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2800 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2802 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2804 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAltitudeValues */

/* 2808 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2810 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2814 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2816 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2820 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2822 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2824 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pZ */

/* 2832 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2834 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2836 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2838 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2840 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2842 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsSupported */

/* 2844 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2846 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2850 */	NdrFcShort( 0x1d ),	/* 29 */
/* 2852 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2858 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2860 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2864 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2866 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrPathName */

/* 2868 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2870 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2872 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter accMode */

/* 2874 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2876 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2882 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportTin */

/* 2886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2892 */	NdrFcShort( 0x1e ),	/* 30 */
/* 2894 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2900 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2902 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2906 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2908 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrTinFile */

/* 2910 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2912 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2914 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 2916 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2918 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TIN2DEM */

/* 2922 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2928 */	NdrFcShort( 0x1f ),	/* 31 */
/* 2930 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 2932 */	NdrFcShort( 0x50 ),	/* 80 */
/* 2934 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2936 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2938 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2942 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2944 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrDEMFile */

/* 2946 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2948 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2950 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter LBX */

/* 2952 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2954 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2956 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter LBY */

/* 2958 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2960 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2962 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter RTX */

/* 2964 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2966 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2968 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter RTY */

/* 2970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2972 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2974 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter lfCellSize */

/* 2976 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2978 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2980 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2984 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateFeatureDEM */

/* 2988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2994 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2996 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2998 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3002 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3004 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3008 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3010 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrRasterDEMFile */

/* 3012 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3014 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3016 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter bstrFeatureFile */

/* 3018 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3020 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3022 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter lfBufferSize */

/* 3024 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3026 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3028 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3030 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3032 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRange */

/* 3036 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3038 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x21 ),	/* 33 */
/* 3044 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 3046 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3050 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 3052 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter LBX */

/* 3060 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3062 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3064 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter LBY */

/* 3066 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3068 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3070 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter RTX */

/* 3072 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3074 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3076 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter RTY */

/* 3078 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3080 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3082 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter CellSize */

/* 3084 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3086 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3088 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3090 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3092 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3094 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCellSize */

/* 3096 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3098 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3102 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3104 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3106 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3108 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3110 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3112 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter CellSize */

/* 3120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3122 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3124 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3128 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFlatAltitude */

/* 3132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3138 */	NdrFcShort( 0x23 ),	/* 35 */
/* 3140 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3142 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3146 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3148 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Z */

/* 3156 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3160 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3164 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateFlatDEM */

/* 3168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3174 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3176 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 3178 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3182 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 3184 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3190 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nRows */

/* 3192 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3194 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nCols */

/* 3198 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter LBX */

/* 3204 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3206 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3208 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter LBY */

/* 3210 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3212 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3214 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter Altitude */

/* 3216 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3218 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3220 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter CellSize */

/* 3222 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3224 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3226 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3230 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateGCPDEM */

/* 3234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3240 */	NdrFcShort( 0x25 ),	/* 37 */
/* 3242 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3248 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3250 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3254 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrGcpFile */

/* 3258 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3260 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3262 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 3264 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3266 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBufferSize */

/* 3270 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3272 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3276 */	NdrFcShort( 0x26 ),	/* 38 */
/* 3278 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3280 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3284 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3286 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3292 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lfBufferSize */

/* 3294 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3296 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3298 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3302 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBufferSize */

/* 3306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x27 ),	/* 39 */
/* 3314 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3318 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3320 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3322 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBufferSize */

/* 3330 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3334 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateVectorDEM */

/* 3342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3348 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3350 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3356 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3358 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3362 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrVectorFile */

/* 3366 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3368 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3370 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 3372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3374 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const ImageX_MIDL_TYPE_FORMAT_STRING ImageX__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x0,	/* FC_UP */
/*  4 */	NdrFcShort( 0xe ),	/* Offset= 14 (18) */
/*  6 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  8 */	NdrFcShort( 0x2 ),	/* 2 */
/* 10 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 12 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 14 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 16 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 18 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 20 */	NdrFcShort( 0x8 ),	/* 8 */
/* 22 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (6) */
/* 24 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 26 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 28 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0x4 ),	/* 4 */
/* 34 */	NdrFcShort( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0xffde ),	/* Offset= -34 (2) */
/* 38 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 40 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 42 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 44 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 46 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 48 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 50 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 52 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 54 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 56 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 58 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 60 */	NdrFcShort( 0x6 ),	/* Offset= 6 (66) */
/* 62 */	
			0x13, 0x0,	/* FC_OP */
/* 64 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (18) */
/* 66 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x4 ),	/* 4 */
/* 72 */	NdrFcShort( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (62) */
/* 76 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 78 */	NdrFcLong( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 88 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 90 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 92 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 94 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 96 */	NdrFcShort( 0x2 ),	/* Offset= 2 (98) */
/* 98 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 100 */	NdrFcLong( 0x889c2904 ),	/* -2003031804 */
/* 104 */	NdrFcShort( 0x3afe ),	/* 15102 */
/* 106 */	NdrFcShort( 0x4920 ),	/* 18720 */
/* 108 */	0xa6,		/* 166 */
			0x59,		/* 89 */
/* 110 */	0xe7,		/* 231 */
			0xdc,		/* 220 */
/* 112 */	0x85,		/* 133 */
			0x75,		/* 117 */
/* 114 */	0x3e,		/* 62 */
			0xa,		/* 10 */
/* 116 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 118 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IImage, ver. 0.0,
   GUID={0x889C2904,0x3AFE,0x4920,{0xA6,0x59,0xE7,0xDC,0x85,0x75,0x3E,0x0A}} */

#pragma code_seg(".orpc")
static const unsigned short IImage_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    42,
    132,
    162,
    192,
    228,
    264,
    300,
    336,
    372,
    408,
    444,
    480,
    528,
    576,
    606,
    642,
    678,
    720,
    756,
    792,
    828,
    864,
    900,
    936,
    972,
    1020,
    1068,
    1122,
    1176,
    1230,
    1290,
    1404,
    1518,
    1554,
    1596,
    1650,
    1704,
    1740,
    1776,
    1812,
    1848,
    1884,
    1926,
    1968
    };

static const MIDL_STUBLESS_PROXY_INFO IImage_ProxyInfo =
    {
    &Object_StubDesc,
    ImageX__MIDL_ProcFormatString.Format,
    &IImage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IImage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    ImageX__MIDL_ProcFormatString.Format,
    &IImage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(52) _IImageProxyVtbl = 
{
    &IImage_ProxyInfo,
    &IID_IImage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IImage::Open */ ,
    (void *) (INT_PTR) -1 /* IImage::CreateImg */ ,
    (void *) (INT_PTR) -1 /* IImage::Close */ ,
    (void *) (INT_PTR) -1 /* IImage::IsGeoCoded */ ,
    (void *) (INT_PTR) -1 /* IImage::GetBandFormat */ ,
    (void *) (INT_PTR) -1 /* IImage::GetBandNum */ ,
    (void *) (INT_PTR) -1 /* IImage::GetRows */ ,
    (void *) (INT_PTR) -1 /* IImage::GetCols */ ,
    (void *) (INT_PTR) -1 /* IImage::GetDataType */ ,
    (void *) (INT_PTR) -1 /* IImage::GetByteOrder */ ,
    (void *) (INT_PTR) -1 /* IImage::GetScale */ ,
    (void *) (INT_PTR) -1 /* IImage::SetScale */ ,
    (void *) (INT_PTR) -1 /* IImage::GetGrdInfo */ ,
    (void *) (INT_PTR) -1 /* IImage::SetGrdInfo */ ,
    (void *) (INT_PTR) -1 /* IImage::HaveColorTable */ ,
    (void *) (INT_PTR) -1 /* IImage::GetEntryNum */ ,
    (void *) (INT_PTR) -1 /* IImage::GetColorTable */ ,
    (void *) (INT_PTR) -1 /* IImage::SetColorTable */ ,
    (void *) (INT_PTR) -1 /* IImage::GetResampleMethod */ ,
    (void *) (INT_PTR) -1 /* IImage::SetResampleMethod */ ,
    (void *) (INT_PTR) -1 /* IImage::GetScanSize */ ,
    (void *) (INT_PTR) -1 /* IImage::SetScanSize */ ,
    (void *) (INT_PTR) -1 /* IImage::GetBPB */ ,
    (void *) (INT_PTR) -1 /* IImage::GetBPP */ ,
    (void *) (INT_PTR) -1 /* IImage::GetPathName */ ,
    (void *) (INT_PTR) -1 /* IImage::GetPixel */ ,
    (void *) (INT_PTR) -1 /* IImage::SetPixel */ ,
    (void *) (INT_PTR) -1 /* IImage::GetGray */ ,
    (void *) (INT_PTR) -1 /* IImage::SetGray */ ,
    (void *) (INT_PTR) -1 /* IImage::GetPixelF */ ,
    (void *) (INT_PTR) -1 /* IImage::GetGrayF */ ,
    (void *) (INT_PTR) -1 /* IImage::ReadImg */ ,
    (void *) (INT_PTR) -1 /* IImage::WriteImg */ ,
    (void *) (INT_PTR) -1 /* IImage::SetProgressInterface */ ,
    (void *) (INT_PTR) -1 /* IImage::GetSupExts */ ,
    (void *) (INT_PTR) -1 /* IImage::Image2World */ ,
    (void *) (INT_PTR) -1 /* IImage::World2Image */ ,
    (void *) (INT_PTR) -1 /* IImage::GetDefaultBand */ ,
    (void *) (INT_PTR) -1 /* IImage::GetCamera */ ,
    (void *) (INT_PTR) -1 /* IImage::SetCamera */ ,
    (void *) (INT_PTR) -1 /* IImage::GetSensorType */ ,
    (void *) (INT_PTR) -1 /* IImage::SetSensorType */ ,
    (void *) (INT_PTR) -1 /* IImage::GetDPI */ ,
    (void *) (INT_PTR) -1 /* IImage::SetDPI */ ,
    (void *) (INT_PTR) -1 /* IImage::Tiff2JPG */
};


static const PRPC_STUB_FUNCTION IImage_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IImageStubVtbl =
{
    &IID_IImage,
    &IImage_ServerInfo,
    52,
    &IImage_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDEM, ver. 0.0,
   GUID={0x5155FDA0,0x6464,0x45EE,{0x9E,0x72,0x05,0x99,0x55,0xD9,0x87,0x12}} */

#pragma code_seg(".orpc")
static const unsigned short IDEM_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    2010,
    2052,
    2106,
    162,
    2142,
    2184,
    2226,
    2262,
    2316,
    372,
    2370,
    2400,
    2436,
    2490,
    2574,
    2622,
    2658,
    2694,
    720,
    2730,
    2766,
    2808,
    2844,
    2886,
    2922,
    2988,
    3036,
    3096,
    3132,
    3168,
    3234,
    3270,
    3306,
    3342
    };

static const MIDL_STUBLESS_PROXY_INFO IDEM_ProxyInfo =
    {
    &Object_StubDesc,
    ImageX__MIDL_ProcFormatString.Format,
    &IDEM_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDEM_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    ImageX__MIDL_ProcFormatString.Format,
    &IDEM_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(41) _IDEMProxyVtbl = 
{
    &IDEM_ProxyInfo,
    &IID_IDEM,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetCellSize */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetRange */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetTIN */ ,
    (void *) (INT_PTR) -1 /* IDEM::Close */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetSupExts */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetSupFormats */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetIImage */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetVertex */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetTriangle */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetTriangleNum */ ,
    (void *) (INT_PTR) -1 /* IDEM::ConstrustTIN */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetAverageAltitude */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetAltitude */ ,
    (void *) (INT_PTR) -1 /* IDEM::Create */ ,
    (void *) (INT_PTR) -1 /* IDEM::Open */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetMaxAltitude */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetMinAltitude */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetType */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetRows */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetCols */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetStartPos */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetAltitudeValues */ ,
    (void *) (INT_PTR) -1 /* IDEM::IsSupported */ ,
    (void *) (INT_PTR) -1 /* IDEM::ExportTin */ ,
    (void *) (INT_PTR) -1 /* IDEM::TIN2DEM */ ,
    (void *) (INT_PTR) -1 /* IDEM::CreateFeatureDEM */ ,
    (void *) (INT_PTR) -1 /* IDEM::SetRange */ ,
    (void *) (INT_PTR) -1 /* IDEM::SetCellSize */ ,
    (void *) (INT_PTR) -1 /* IDEM::SetFlatAltitude */ ,
    (void *) (INT_PTR) -1 /* IDEM::CreateFlatDEM */ ,
    (void *) (INT_PTR) -1 /* IDEM::CreateGCPDEM */ ,
    (void *) (INT_PTR) -1 /* IDEM::SetBufferSize */ ,
    (void *) (INT_PTR) -1 /* IDEM::GetBufferSize */ ,
    (void *) (INT_PTR) -1 /* IDEM::CreateVectorDEM */
};


static const PRPC_STUB_FUNCTION IDEM_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDEMStubVtbl =
{
    &IID_IDEM,
    &IDEM_ServerInfo,
    41,
    &IDEM_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    ImageX__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x700022b, /* MIDL Version 7.0.555 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _ImageX_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IImageProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDEMProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _ImageX_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IImageStubVtbl,
    ( CInterfaceStubVtbl *) &_IDEMStubVtbl,
    0
};

PCInterfaceName const _ImageX_InterfaceNamesList[] = 
{
    "IImage",
    "IDEM",
    0
};

const IID *  const _ImageX_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _ImageX_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _ImageX, pIID, n)

int __stdcall _ImageX_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _ImageX, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _ImageX, 2, *pIndex )
    
}

const ExtendedProxyFileInfo ImageX_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _ImageX_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _ImageX_StubVtblList,
    (const PCInterfaceName * ) & _ImageX_InterfaceNamesList,
    (const IID ** ) & _ImageX_BaseIIDList,
    & _ImageX_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

