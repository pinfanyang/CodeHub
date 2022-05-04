#include "reg52.h"

//��������
sbit HC138_A = P2^5;
sbit HC138_B = P2^6;
sbit HC138_C = P2^7;

//�ֶ���ʱ����ʵ��
void Delay(unsigned int t)
{
	while(t--);
	while(t--);
}

void LEDRunning()
{
	unsigned char i;
	//ѡͨ������																										   
	HC138_A = 1;
	HC138_B = 0;
	HC138_C = 0;

	//8����ȫ����Ȼ��ȫ��ִ������
	for(i = 0; i < 3; i++)
	{
		P0 = 0x00;	 //ȫ��
		Delay(40000);
		Delay(50000);
		P0 = 0xff;	//ȫ��
	}

	//��ˮ��ʵ�֣�L1��L8���ε���
	for(i = 1; i <= 8; i++)
	{
		P0 = 0xff << i;	//����������0
	}
	for(i = 1; i <= 8; i++)
	{
		P0 = ~(0xff << i);	//����Ϩ�� 	  
	}

}

void  main()
{
	while(1)
	{
		LEDRunning();
	}


}