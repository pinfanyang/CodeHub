#include "reg52.h"

//脚标
sbit HC138_A = P2^5;
sbit HC138_B = P2^6;
sbit HC138_C = P2^7;


void Delay(unsigned int t)
{
	while(t--);
	while(t--);
}

void InitHC138(unsigned char n)	//用函数控制选择138输出那一位
{
 	switch(n)
	{
		case 4:
			HC138_C = 1;
			HC138_B = 0;
			HC138_A = 0;		//Y4输出低电平
		//简洁写法
		// P2 = (P2 & 0x1f) | 0x80;
		break;
		case 5:
			HC138_C = 1;
			HC138_B = 0;
			HC138_A = 1;		//Y5输出低电平
		// P2 = (P2 & 0x1f) | 0xa0;
		break;
		case 6:
			HC138_C = 1;
			HC138_B = 1;
			HC138_A = 0;		//Y6输出低电平
		// P2 = (P2 & 0x1f) | 0xc0;
		break;
		case 7:
			HC138_C = 1;
			HC138_B = 1;
			HC138_A = 1;		//Y7输出低电平
		// P2 = (P2 & 0x1f) | 0xe0;
		break;
	}
}

void OutPutP0(unsigned char channel,unsigned char dat)		//通过函数来实现对P0的控制
{
	InitHC138(channel);
	P0 = dat;
}


void LEDRunning()
{
	unsigned char i;
	InitHC138(4);		//Y4输出低电平

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
//	InitHC138(5);		//Y5输出低电平
//	P0 = 0x10;			//让继电器吸合
	OutPutP0(5,0x10);
	Delay(40000);
	Delay(50000);					
//   	P0 = 0x00;			//让继电器吸合
	OutPutP0(5,0x00);

	InitHC138(4);		//Y4输出低电平
	for(i = 1; i <= 8; i++)
	{
		OutPutP0(4,~(0xff << i));
		Delay(60000);
	}

//	InitHC138(5);		//Y5输出低电平
//	P0 = 0x40;			//让蜂鸣器报警
	OutPutP0(5,0x40);
	Delay(40000);
	Delay(50000);					
//   	P0 = 0x00;			//关闭蜂鸣器
	OutPutP0(5,0x00);

}



void InitSystem()	//初始化系统，关掉无关设备（蜂鸣器、继电器这些）
{
	//	InitHC138(5);		//Y5输出低电平
	//P0 = 0x00;			
	OutPutP0(5,0x00);



}


void main()
{
	InitSystem();  //初始化设备
	while(1)
	{
		LEDRunning();


	}

}


