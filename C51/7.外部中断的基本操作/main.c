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



void Init_INI0()	//中断初始化函数
{
		IT0 = 1;	//中断触发方式：下降沿触发
		EX0 = 1;	//外部中断使能
		EA = 1;		//总中断打开
}

void ServiceINT0() interrupt 0	//中断服务函数
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
	Init_INI0();
	while(1)
	{
		Working();
		
	}
	
}








////////////////////////////////////////////////////////
////这是第二种写法，有时候会用到 (带查询的中断）
////这种能保证在中断产生时不会影响前面L1灯，因为每次都是等L1亮了之后再去查询中断状态
//unsigned char stat_int = 0;
//void Init_INI0()	//中断初始化函数
//{
//		IT0 = 1;	//中断触发方式：下降沿触发
//		EX0 = 1;	//外部中断使能
//		EA = 1;		//总中断打开
//}

//unsigned cahr stat_int = 0;
//void ServiceINT0() interrupt 0	//中断服务函数
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
