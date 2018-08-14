/*
 * libCoordinateConverter.h
 *
 * Main
 * 2018-08-14
 *
 * 坐标转换器接口声明
 */

#ifndef __LIB_COORDINATE_CONVERTER__
#define __LIB_COORDINATE_CONVERTER__

// 坐标系类型定义
typedef enum
{
	// WGS-84原始坐标系，卫星定位模块（GPS）输出的坐标
	COORDINATE_SYSTEM_WGS84 = 0,
	// 国测局-02年标准坐标系(火星坐标系)，四维图新，高德，GOOGLE地图均使用此坐标系
	COORDINATE_SYSTEM_GCJ02 = 1,
	// 百度地图坐标系
	COORDINATE_SYSTEM_BD09 = 2,
}CoordinateSystemType;

// 经纬度坐标结构定义
typedef struct
{
	// 经度
	double X;
	// 纬度
	double Y;
}MainCoordinate;

#ifdef __cplusplus
extern "C"
{
#endif

	/*
	* Comments: 库注册, 不注册无法正常使用
	* Param :
	* @Return void
	*/
	int Main_RegisterDll(const char *aKey);

	/*
	* Comments: 将当前坐标转换为国测局02系坐标(火星坐标)
	* Param aX: 待转换的经度
	* Param aY: 待转换的纬度
	* Param aType: 待转换的经纬度所属坐标系
	* Param aCoordinate: [输出] 转换后的GCJ02系坐标
	* @Return void
	*/
	void Main_ConvertGCJ02(double aX, double aY, CoordinateSystemType aType, MainCoordinate *aCoordinate);

	/*
	* Comments: 将当前坐标转换为百度系坐标
	* Param aX: 待转换的经度
	* Param aY: 待转换的纬度
	* Param aType: 待转换的经纬度所属坐标系
	* Param aCoordinate: [输出] 转换后的百度系坐标
	* @Return void
	*/
	void Main_ConvertBD09(double aX, double aY, CoordinateSystemType aType, MainCoordinate *aCoordinate);

	/*
	* Comments: 将当前坐标转换为WGS84国际通用坐标
	* Param aX: 待转换的经度
	* Param aY: 待转换的纬度
	* Param aType: 待转换的经纬度所属坐标系
	* Param aCoordinate: [输出] 转换后的WGS84系坐标
	* @Return void
	*/
	void Main_ConvertWGS84(double aX, double aY, CoordinateSystemType aType, MainCoordinate *aCoordinate);

	/*
	* Comments: 获取两个经纬度之间的距离(m)
	* Param :
	* @Return void
	*/
	double Main_GetDistance(double aX1, double aY1, double aX2, double aY2);

#ifdef __cplusplus
}
#endif


#endif // !__LIB_COORDINATE_CONVERTER__
