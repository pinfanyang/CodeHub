#include "reg52.h"
#include "absacc.h"
#include "onewire.h"

unsigned char SMGNoDot_CA[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,
																 0x82,0xf8,0x80,0x90};//0-9不带点
unsigned char SMGDot_CA[10] = {0x40,0x79,0x24,0x30,0x19,
															 0x12,0x02,0x78,0x00,0x10};//0-9带点
unsigned int temp = 0;
															 
void DelaySMG(unsigned int t)
{
	while(t--);
}

void DisplaySMG_Bit(unsigned char pos,unsigned char dat)
{
	XBYTE[0xE000] = 0xff;	//全选消影
	XBYTE[0xC000] = 0x01 << pos;
	XBYTE[0xE000] = dat;
}

void DisPlay_All(unsigned char dat)
{
		XBYTE[0xC000] = 0xff;
		XBYTE[0xE000] = dat;
}



void DisPlaySMG_Temp()
{
	DisplaySMG_Bit(7,SMGNoDot_CA[temp % 10]);		//个位
	DelaySMG(100);
	DisplaySMG_Bit(6,SMGDot_CA[(temp % 100) / 10]); //十位
	DelaySMG(100);
	DisplaySMG_Bit(5,SMGNoDot_CA[temp / 100]);		//百位
	DelaySMG(100);
	
	
	DisplaySMG_Bit(4,0xff);	//不显示，但是还是要写，防止电流抖动
	DelaySMG(100);
	DisplaySMG_Bit(3,0xff);
	DelaySMG(100);
	DisplaySMG_Bit(2,0xff);
	DelaySMG(100);
	DisplaySMG_Bit(1,0xff);
	DelaySMG(100);
	DisplaySMG_Bit(0,0xff);
	DelaySMG(100);
	
	DisPlay_All(0xff);		//关掉所有数码管
	
}

void Delay(unsigned int t)
{
	while(t--)	//注意：数码管不能直接这么用延时，数码管在延时的时候也要保持动态扫描
	{
		DisPlaySMG_Temp();
	}
}

void Read_DS18B20_temp()
{
	unsigned char LSB,HSB;	//存储温度的高低位
	
	init_ds18b20();		//DS18B20设备初始化
	Write_DS18B20(0xcc);	//跳过ROM指令
	Write_DS18B20(0x44);	//温度转换
	
	Delay(1000);	//给延时，数据转换时间
	
	init_ds18b20();		//DS18B20设备初始化
	Write_DS18B20(0xcc);	//跳过ROM指令
	Write_DS18B20(0xbe);	//接收温度转换数据
	
	LSB = Read_DS18B20();	//读低八位
	HSB = Read_DS18B20();	//读高八位
	
	temp = HSB;
	temp = (temp << 8) | LSB;		//将温度数据组合起来，成为输出的结果
	
	
	//下面这部分是考虑了小数，如果比赛要求整数，那么直接在上面的语句
	//接一句 temp >>= 4;即可，也就是直接去除小数部分即可
	if((temp & 0xf800) == 0x0000)	//看高五位是不是0，是0温度就为正
	{
		temp >>= 4;	//右移四位，去除小数，后面加回来
		temp = temp * 10;	//整数部分放到10倍
		temp = temp + (LSB & 0x0f) *0.625;	//加上小数，精度也扩大了10倍
	}
	
}


void main()
{
	XBYTE[8000] = 0x00;	//关闭所有LED灯 
	while(1)
	{
		Read_DS18B20_temp();
		DisPlaySMG_Temp();
	}
	
}