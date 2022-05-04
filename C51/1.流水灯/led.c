#include "reg52.h"

//声明变量
sbit HC138_A = P2^5;
sbit HC138_B = P2^6;
sbit HC138_C = P2^7;

//手动延时函数实现
void Delay(unsigned int t)
{
	while(t--);
	while(t--);
}

void LEDRunning()
{
	unsigned char i;
	//选通锁存器																										   
	HC138_A = 1;
	HC138_B = 0;
	HC138_C = 0;

	//8个灯全亮，然后全灭，执行三次
	for(i = 0; i < 3; i++)
	{
		P0 = 0x00;	 //全亮
		Delay(40000);
		Delay(50000);
		P0 = 0xff;	//全灭
	}

	//流水灯实现，L1到L8依次点亮
	for(i = 1; i <= 8; i++)
	{
		P0 = 0xff << i;	//依次左移置0
	}
	for(i = 1; i <= 8; i++)
	{
		P0 = ~(0xff << i);	//依次熄灭 	  
	}

}

void  main()
{
	while(1)
	{
		LEDRunning();
	}


}