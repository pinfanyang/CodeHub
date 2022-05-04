#include "reg52.h"

unsigned char code SMG_duanma[18]=
	{0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,
	 0x88,0x80,0xc6,0xc0,0x86,0x8e,
	 0xbf,0x7f};		//0-9,A-F,-和.
unsigned int year = 1234;
unsigned int month = 1;

void SelectHC573(unsigned char channel)
{
	switch(channel)
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

void DisplaySMG_Bit(unsigned char value, unsigned char pos)
{
	SelectHC573(6);
	P0 = 0x01 << pos;
	SelectHC573(7);
	P0 = value ;
}

void DelaySMG(unsigned int t)
{
	while(t--);
}

void Display_Dynamic()
{
	DisplaySMG_Bit(SMG_duanma[year/1000],0);
	DelaySMG(600);
	DisplaySMG_Bit(SMG_duanma[year%1000/100],1);
	DelaySMG(600);
	DisplaySMG_Bit(SMG_duanma[year%100/10],2);
	DelaySMG(600);
	DisplaySMG_Bit(SMG_duanma[year%10],3);
	DelaySMG(600);
	
	DisplaySMG_Bit(SMG_duanma[16],4);
	DelaySMG(600);
	DisplaySMG_Bit(SMG_duanma[16],5);
	DelaySMG(600);
	
	DisplaySMG_Bit(SMG_duanma[month/10],6);
	DelaySMG(600);
	DisplaySMG_Bit(SMG_duanma[month%10],7);
	DelaySMG(600);
}

void Delay(unsigned int t)		//不能用char
{
	while(t--)
	{
		Display_Dynamic();
	}
}

	 

void InitSystem()	//初始化系统，关掉无关设备（蜂鸣器、继电器这些）
{
	SelectHC573(4);		//Y4输出低电平,关灯
	P0 = 0xff;			
	SelectHC573(5);		//Y5输出低电平
	P0 = 0x00;			
}
	
void main()
{
	InitSystem();
	Display_Dynamic();
	while(1)
	{
		month++;
		if(month > 12)
		{
			month = 1;
			year++;
		}
		Delay(100);
	}
}

		
		