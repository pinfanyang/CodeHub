#include "reg52.h"

//定义按键
sbit S7 = P3^0;
sbit S6 = P3^1;
sbit S5 = P3^2;
sbit S4 = P3^3;
//定义LED灯
sbit L1 = P0^0;
sbit L2 = P0^1;
sbit L3 = P0^2;
sbit L4 = P0^3;
sbit L5 = P0^4;
sbit L6 = P0^5;


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

void DelayK(unsigned char t)
{
	while(t--);
}

unsigned char start_k = 0;	//S7、S6按下标志位
void ScanKeys_Alone()
{
	if(S7 == 0)
	{
		DelayK(100);
		if(S7 == 0)
		{
				if(start_k == 0)
				{
					L1 = 0;
					start_k = 1;
				}
				else if(start_k == 1)
				{
					L1 = 1;
					start_k = 0;
				}
				while(S7 == 0);		//细节处理，按下消除抖动，这样可以保证按下就亮，不然有时候按下不亮 
		}
	}
	if(S6 == 0)
	{
		DelayK(100);
		if(S6 == 0)
		{
				if(start_k == 0)
				{
					L2 = 0;
					start_k = 2;
				}
				else if(start_k == 2) //用不同变量大小起到异或的功能
				{
					L2 = 1;
					start_k = 0;
				}
				while(S6 == 0);		//细节处理，按下消除抖动，这样可以保证按下就亮，不然有时候按下不亮 
		}
	}
	if(S5 == 0)
	{
		DelayK(100);
		if(S5 == 0)
		{
			if(start_k == 1)		//分组功能
			{
				L3 = 0;
				while(S5 == 0);
				L3 = 1;
			}
			else if(start_k == 2)
			{
				L5 = 0;
				while(S5 == 0); 
				L5 = 1;
			}
		}
	}
	if(S4 == 0)
	{
		DelayK(100);
		if(S4 == 0)
		{
			if(start_k == 1)		//分组功能
			{
				L4 = 0;
				while(S4 == 0);
				L4 = 1;
			}
			else if(start_k == 2)
			{
				L6 = 0;
				while(S4 == 0);
				L6 = 1;
			}
		}
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
	//InitSystem();
	SelectHC573(4);
	while(1)
	{
		ScanKeys_Alone();
	}
	
}
	
	
	