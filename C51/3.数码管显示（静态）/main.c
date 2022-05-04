#include "reg52.h"

unsigned char code SMG_duanma[18]=
	{0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,
	 0x88,0x80,0xc6,0xc0,0x86,0x8e,
	 0xbf,0x7f};		//0-9,A-F,-和.
	
void Delay(unsigned int t)		//不能用char
{
	while(t--);
	while(t--);
	while(t--);
}

void InitHC138(unsigned char n)
{
		switch(n)
		{
			case 4:
				P2 = (P2 & 0x1f) | 0x80;
			break;
			case 5:
				P2 = (P2 & 0x1f) | 0xa0;
			break;
			case 6:
				P2 = (P2 & 0x1f) | 0xc0;
			break;
			case 7:
				P2 = (P2 & 0x1f) | 0xe0;
			break;
		}
}

void ShowSMG()
{
	InitHC138(6);
	P0 = 0x01;	//位选，第一个
	InitHC138(7);
	P0 = 0x82;  //段选6

}
void ShowSMG_Bit(unsigned char dat, unsigned pos)
{


	InitHC138(6);	//数码管的位置
	P0 = 0x01 << pos;
	InitHC138(7); //数码管的内容
	P0 = dat;
}

void SMG_Static()
{
	unsigned char i,j;
	for(i = 0; i < 8; i++)		//逐个显示0-9
	{
		for(j = 0;j < 10; j++)
		{
			ShowSMG_Bit(SMG_duanma[j],i);
			Delay(60000);
			Delay(40000);
		}
	}
	
	for(j = 0; j < 16 ; j++) //集体显示0-F
	{
		InitHC138(6);
		P0 = 0xff;
		InitHC138(7);
		P0 = SMG_duanma[j];
		Delay(40000);
		Delay(60000);
	}

}
	
	
void InitSystem()	//初始化系统，关掉无关设备（蜂鸣器、继电器这些）
{
	InitHC138(4);		//Y5输出低电平
	P0 = 0xff;			
	InitHC138(5);		//Y5输出低电平
	P0 = 0x00;			
	//OutPutP0(5,0x00);
}
	
void main()
{

	InitSystem();
	while(1)
	{

		SMG_Static();
	}
}
