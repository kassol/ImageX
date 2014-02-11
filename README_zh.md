#ImageX 设计文档#

  GDAL提供了很丰富的影像格式的读取和一系列操作的方法，ImageX是对gdal的一层封装，写成了
一个COM组件，简化了使用方法，并扩充了DEM（数字地面模型）的一系列格式，为3S行业的编程提供了很大的便捷性。


**接口定义**

(1) `HRESULT Open([in] BSTR bstrPathName, [in] UINT uMode);`
> **功能**
> 
> 打开一幅影像
> 
> **参数**
> 
> bstrPathName:		影像路径名
> 
> uMode:			打开方式
> 
> **返回值**
> 
> S_OK:				打开成功
> 
> S_FALSE:			打开失败

(2) `HRESULT CreateImg([in] BSTR bstrFilePath, [in] UINT uMode, [in] int Cols, [in] int Rows, [in] UINT DataType, [in] int nBandNum, [in] UINT BandType, [in] DOUBLE xStart, [in] DOUBLE yStart, [in] DOUBLE cellSize);`
> **功能**
> 
> 创建一幅影像
> 
> **参数**
> 
> bstrFilePath:		影像路径名
> 
> uMode:			创建方式
> 
> Cols:				影像列数
> 
> Rows:				影像行数
> 
> DataType:			影像数据类型
> 
> nBandNum:			影像波段数
> 
> BandType:			波段排列方式
> 
> xStart:			影像起始x坐标
> 
> yStart:			影像起始y坐标
> 
> **返回值**
> 
> S_OK:				创建成功
> 
> S_FALSE:			创建失败

(3) `HRESULT Close(void);`
> **功能**
> 
> 关闭影像
> 
> **返回值**
> 
> S_OK:				关闭成功
> 
> S_FALSE:			关闭失败

(4) `HRESULT IsGeoCoded(void);`
> **功能**
> 
> 影像是否有地理编码
> 
> **返回值**
> 
> S_OK:				有地理编码
> 
> S_FALSE:			无地理编码

(5) `HRESULT GetBandFormat([out] UINT* pBandFormat);`
> **功能**
> 
> 获取波段排列方式
> 
> **参数**
> 
> pBandFormat:		保存影像的波段排列方式
> 
> **返回值**
> 
> S_OK:				获取成功
> 
> S_FALSE:			获取失败

(7) `HRESULT GetBandNum([out] int* pBandNum);`
> **功能**
> 
> 获取影像的波段数
> 
> **参数**
> 
> pBandNum:			影像的波段数
> 
> **返回值**
> 
> S_OK:				获取成功
> 
> S_FALSE:			获取失败

(9) `HRESULT GetRows([out] int* pRows);`
> **功能**
> 
> 获取影像的列数
> 
> **参数**
> 
> pRows:			影像的列数
> 
> **返回值**
> 
> S_OK:				获取成功
> 
> S_FALSE:			获取失败

(11) `HRESULT GetCols([out] int* pCols);`
> **功能**
> 
> 获取影像的行数
> 
> **参数**
> 
> pCols:			影像的行数
> 
> **返回值**
> 
> S_OK:				获取成功
> 
> S_FALSE:			获取失败

(13) `HRESULT GetDataType([out] UINT* pDataType);`
> **功能**
> 
> 获取影像数据类型
> 
> **参数**
> 
> pDataType:		影像数据类型
> 
> **返回值**
> 
> S_OK:				获取成功
> 
> S_FALSE:			获取失败

(15) `HRESULT GetByteOrder([out] UINT* pByteOrder);`
> **功能**
> 
> 获取影像数据字节序
> 
> **参数**
> 
> pByteOrder:		影像数据字节序
> 
> **返回值**
> 
> S_OK:				获取成功
> 
> S_FALSE:			获取失败

(17) `HRESULT GetScale([out] FLOAT* pScale);`