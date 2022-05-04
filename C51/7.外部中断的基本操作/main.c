#include "reg52.h"

sbit L1 = P0^0;
sbit L8 = P0^7;

void Delay(unsigned int t)
{
	while(t--);
}

void SelectHC573(unsigned char channel)
{
	switch(channel)
	{
		case 4:
			P2 = (P2 & 0x01f) | 0x80;
		break;
		case 5:
			P2 = (P2 & 0x01f) | 0xa0;
		break;
		case 6:
			P2 = (P2 & 0x01f) | 0xc0;
		break;
		case 7:
			P2 = (P2 & 0x01f) | 0xe0;
		break;
	}
}

void Working()
{
	SelectHC573(4);
	L1 = 0;
	Delay(60000);
	L1 = 1;
	Delay(40000);
}



void Init_INI0()	//�жϳ�ʼ������
{
		IT0 = 1;	//�жϴ�����ʽ���½��ش���
		EX0 = 1;	//�ⲿ�ж�ʹ��
		EA = 1;		//���жϴ�
}

void ServiceINT0() interrupt 0	//�жϷ�����
{
	L8 = 0;
	Delay(60000);
	Delay(60000);
	Delay(60000);
	Delay(60000);
	Delay(60000);
	Delay(60000);
	Delay(60000);
	Delay(60000);
	Delay(60000);
	Delay(60000);
	Delay(60000);
	Delay(60000);
	L8 = 1;
}



void InitSystem()	//��ʼ��ϵͳ���ص��޹��豸�����������̵�����Щ��
{
	SelectHC573(4);		//Y4����͵�ƽ,�ص�
	P0 = 0xff;			
	SelectHC573(5);		//Y5����͵�ƽ
	P0 = 0x00;			
}

void main()
{
	//InitSystem();
	Init_INI0();
	while(1)
	{
		Working();
		
	}
	
}








////////////////////////////////////////////////////////
////���ǵڶ���д������ʱ����õ� (����ѯ���жϣ�
////�����ܱ�֤���жϲ���ʱ����Ӱ��ǰ��L1�ƣ���Ϊÿ�ζ��ǵ�L1����֮����ȥ��ѯ�ж�״̬
//unsigned char stat_int = 0;
//void Init_INI0()	//�жϳ�ʼ������
//{
//		IT0 = 1;	//�жϴ�����ʽ���½��ش���
//		EX0 = 1;	//�ⲿ�ж�ʹ��
//		EA = 1;		//���жϴ�
//}

//unsigned cahr stat_int = 0;
//void ServiceINT0() interrupt 0	//�жϷ�����
//{
//	stat_int = 0;
//}
//	
//void LEDINT()
//{
//	if(stat_int == 1)
//	{
//		L8 = 0;
//		Delay(60000);
//		Delay(60000);
//		Delay(60000);
//		Delay(60000);
//		Delay(60000);
//		Delay(60000);
//		Delay(60000);
//		Delay(60000);
//		Delay(60000);
//		Delay(60000);
//		Delay(60000);
//		Delay(60000);
//		L8 = 1;
//	}
//	stat_int =0;
//}

//void main()
//{
//	Init_INI0();
//	while(1)
//	{
//		Working();
//		LEDINT();
//	}
//	
//}


/////////////////////////////////////////////////////
