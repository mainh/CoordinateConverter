/*
 * libCoordinateConverter.h
 *
 * Main
 * 2018-08-14
 *
 * ����ת�����ӿ�����
 */

#ifndef __LIB_COORDINATE_CONVERTER__
#define __LIB_COORDINATE_CONVERTER__

// ����ϵ���Ͷ���
typedef enum
{
	// WGS-84ԭʼ����ϵ�����Ƕ�λģ�飨GPS�����������
	COORDINATE_SYSTEM_WGS84 = 0,
	// �����-02���׼����ϵ(��������ϵ)����άͼ�£��ߵ£�GOOGLE��ͼ��ʹ�ô�����ϵ
	COORDINATE_SYSTEM_GCJ02 = 1,
	// �ٶȵ�ͼ����ϵ
	COORDINATE_SYSTEM_BD09 = 2,
}CoordinateSystemType;

// ��γ������ṹ����
typedef struct
{
	// ����
	double X;
	// γ��
	double Y;
}MainCoordinate;

#ifdef __cplusplus
extern "C"
{
#endif

	/*
	* Comments: ��ע��, ��ע���޷�����ʹ��
	* Param :
	* @Return void
	*/
	int Main_RegisterDll(const char *aKey);

	/*
	* Comments: ����ǰ����ת��Ϊ�����02ϵ����(��������)
	* Param aX: ��ת���ľ���
	* Param aY: ��ת����γ��
	* Param aType: ��ת���ľ�γ����������ϵ
	* Param aCoordinate: [���] ת�����GCJ02ϵ����
	* @Return void
	*/
	void Main_ConvertGCJ02(double aX, double aY, CoordinateSystemType aType, MainCoordinate *aCoordinate);

	/*
	* Comments: ����ǰ����ת��Ϊ�ٶ�ϵ����
	* Param aX: ��ת���ľ���
	* Param aY: ��ת����γ��
	* Param aType: ��ת���ľ�γ����������ϵ
	* Param aCoordinate: [���] ת����İٶ�ϵ����
	* @Return void
	*/
	void Main_ConvertBD09(double aX, double aY, CoordinateSystemType aType, MainCoordinate *aCoordinate);

	/*
	* Comments: ����ǰ����ת��ΪWGS84����ͨ������
	* Param aX: ��ת���ľ���
	* Param aY: ��ת����γ��
	* Param aType: ��ת���ľ�γ����������ϵ
	* Param aCoordinate: [���] ת�����WGS84ϵ����
	* @Return void
	*/
	void Main_ConvertWGS84(double aX, double aY, CoordinateSystemType aType, MainCoordinate *aCoordinate);

	/*
	* Comments: ��ȡ������γ��֮��ľ���(m)
	* Param :
	* @Return void
	*/
	double Main_GetDistance(double aX1, double aY1, double aX2, double aY2);

#ifdef __cplusplus
}
#endif


#endif // !__LIB_COORDINATE_CONVERTER__
