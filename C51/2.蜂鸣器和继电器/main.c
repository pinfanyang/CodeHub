#include "reg52.h"

//�ű�
sbit HC138_A = P2^5;
sbit HC138_B = P2^6;
sbit HC138_C = P2^7;


void Delay(unsigned int t)
{
	while(t--);
	while(t--);
}

void InitHC138(unsigned char n)	//�ú�������ѡ��138�����һλ
{
 	switch(n)
	{
		case 4:
			HC138_C = 1;
			HC138_B = 0;
			HC138_A = 0;		//Y4����͵�ƽ
		//���д��
		// P2 = (P2 & 0x1f) | 0x80;
		break;
		case 5:
			HC138_C = 1;
			HC138_B = 0;
			HC138_A = 1;		//Y5����͵�ƽ
		// P2 = (P2 & 0x1f) | 0xa0;
		break;
		case 6:
			HC138_C = 1;
			HC138_B = 1;
			HC138_A = 0;		//Y6����͵�ƽ
		// P2 = (P2 & 0x1f) | 0xc0;
		break;
		case 7:
			HC138_C = 1;
			HC138_B = 1;
			HC138_A = 1;		//Y7����͵�ƽ
		// P2 = (P2 & 0x1f) | 0xe0;
		break;
	}
}

void OutPutP0(unsigned char channel,unsigned char dat)		//ͨ��������ʵ�ֶ�P0�Ŀ���
{
	InitHC138(channel);
	P0 = dat;
}


void LEDRunning()
{
	unsigned char i;
	InitHC138(4);		//Y4����͵�ƽ

	for(i = 0; i < 3; i++)
	{
		OutPutP0(4,0x00);
		Delay(40000);
		Delay(50000);
		OutPutP0(4,0xff);
		Delay(40000);
		Delay(50000);
	}

	for(i = 1; i <= 8; i++)
	{
		OutPutP0(4,(0xff << i));
		Delay(60000);
	}

	/////////////////////////////////
//	InitHC138(5);		//Y5����͵�ƽ
//	P0 = 0x10;			//�ü̵�������
	OutPutP0(5,0x10);
	Delay(40000);
	Delay(50000);					
//   	P0 = 0x00;			//�ü̵�������
	OutPutP0(5,0x00);

	InitHC138(4);		//Y4����͵�ƽ
	for(i = 1; i <= 8; i++)
	{
		OutPutP0(4,~(0xff << i));
		Delay(60000);
	}

//	InitHC138(5);		//Y5����͵�ƽ
//	P0 = 0x40;			//�÷���������
	OutPutP0(5,0x40);
	Delay(40000);
	Delay(50000);					
//   	P0 = 0x00;			//�رշ�����
	OutPutP0(5,0x00);

}



void InitSystem()	//��ʼ��ϵͳ���ص��޹��豸�����������̵�����Щ��
{
	//	InitHC138(5);		//Y5����͵�ƽ
	//P0 = 0x00;			
	OutPutP0(5,0x00);



}


void main()
{
	InitSystem();  //��ʼ���豸
	while(1)
	{
		LEDRunning();


	}

}


