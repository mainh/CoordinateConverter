/*
* Comments: 坐标转换器演示程序
* Param : 
* @Return void
*/

#include <stdio.h>
#include "../Debug/libCoordinateConverter.h"

const char *Key = "p0CQ<Q9Q0Qz6_6_Q_n^6_6W{v6_6woW6.6zrXs_Szs_s_sXsXs0svsxsWs9sXsWsWs0sXs^s0sxsvsWsvQv{Z{ZRW{x{0{z{9Rx{^Qv{Z{zRX{^RWRx{^RWSz{^Ry{^3E";

int main()
{
	MainCoordinate tmp_pnt = { 120.39548, 36.10626 };
	MainCoordinate new_pnt;
	double tmp_dis;
	int result;

	result = Main_RegisterDll(Key);
	if (result)
	{
		printf("Register fail: %d.\r\n", result);
		getchar();
		return -1;
	}

	for (int i = 0; i < 50; i++)
	{
		printf("原始坐标：%lf, %lf\r\n", tmp_pnt.X, tmp_pnt.Y);
		// 百度坐标加偏
		Main_ConvertBD09(tmp_pnt.X, tmp_pnt.Y, COORDINATE_SYSTEM_WGS84, &new_pnt);
		printf("百度加偏：%lf, %lf\r\n", new_pnt.X, new_pnt.Y);

		// 反向还原成原始的GPS坐标
		Main_ConvertWGS84(new_pnt.X, new_pnt.Y, COORDINATE_SYSTEM_BD09, &new_pnt);
		printf("百度还原：%lf, %lf\r\n", new_pnt.X, new_pnt.Y);

		// 获得两点之间的误差距离,单位米
		tmp_dis = Main_GetDistance(tmp_pnt.X, tmp_pnt.Y, new_pnt.X, new_pnt.Y);
		printf("百度坐标还原后，两点之间的误差精度: %lf米\r\n", tmp_dis);

		// 火星坐标系(如谷歌，高德)坐标加偏
		Main_ConvertGCJ02(tmp_pnt.X, tmp_pnt.Y, COORDINATE_SYSTEM_WGS84, &new_pnt);
		printf("火星加偏：%lf, %lf\r\n", new_pnt.X, new_pnt.Y);
		// 反向还原成原始的GPS坐标
		Main_ConvertWGS84(new_pnt.X, new_pnt.Y, COORDINATE_SYSTEM_GCJ02, &new_pnt);
		printf("火星还原：%lf, %lf\r\n", new_pnt.X, new_pnt.Y);

		// 获得两点之间的误差距离,单位米
		tmp_dis = Main_GetDistance(tmp_pnt.X, tmp_pnt.Y, new_pnt.X, new_pnt.Y);
		printf("火星坐标还原后，两点之间的误差精度: %lf米\r\n", tmp_dis);

		tmp_pnt.X += 0.01;
		tmp_pnt.Y += 0.01;
	}

	getchar();

    return 0;
}

