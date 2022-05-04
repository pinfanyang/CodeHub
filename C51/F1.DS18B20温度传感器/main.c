#include "reg52.h"
#include "absacc.h"
#include "onewire.h"

unsigned char SMGNoDot_CA[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,
																 0x82,0xf8,0x80,0x90};//0-9������
unsigned char SMGDot_CA[10] = {0x40,0x79,0x24,0x30,0x19,
															 0x12,0x02,0x78,0x00,0x10};//0-9����
unsigned int temp = 0;
															 
void DelaySMG(unsigned int t)
{
	while(t--);
}

void DisplaySMG_Bit(unsigned char pos,unsigned char dat)
{
	XBYTE[0xE000] = 0xff;	//ȫѡ��Ӱ
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
	DisplaySMG_Bit(7,SMGNoDot_CA[temp % 10]);		//��λ
	DelaySMG(100);
	DisplaySMG_Bit(6,SMGDot_CA[(temp % 100) / 10]); //ʮλ
	DelaySMG(100);
	DisplaySMG_Bit(5,SMGNoDot_CA[temp / 100]);		//��λ
	DelaySMG(100);
	
	
	DisplaySMG_Bit(4,0xff);	//����ʾ�����ǻ���Ҫд����ֹ��������
	DelaySMG(100);
	DisplaySMG_Bit(3,0xff);
	DelaySMG(100);
	DisplaySMG_Bit(2,0xff);
	DelaySMG(100);
	DisplaySMG_Bit(1,0xff);
	DelaySMG(100);
	DisplaySMG_Bit(0,0xff);
	DelaySMG(100);
	
	DisPlay_All(0xff);		//�ص����������
	
}

void Delay(unsigned int t)
{
	while(t--)	//ע�⣺����ܲ���ֱ����ô����ʱ�����������ʱ��ʱ��ҲҪ���ֶ�̬ɨ��
	{
		DisPlaySMG_Temp();
	}
}

void Read_DS18B20_temp()
{
	unsigned char LSB,HSB;	//�洢�¶ȵĸߵ�λ
	
	init_ds18b20();		//DS18B20�豸��ʼ��
	Write_DS18B20(0xcc);	//����ROMָ��
	Write_DS18B20(0x44);	//�¶�ת��
	
	Delay(1000);	//����ʱ������ת��ʱ��
	
	init_ds18b20();		//DS18B20�豸��ʼ��
	Write_DS18B20(0xcc);	//����ROMָ��
	Write_DS18B20(0xbe);	//�����¶�ת������
	
	LSB = Read_DS18B20();	//���Ͱ�λ
	HSB = Read_DS18B20();	//���߰�λ
	
	temp = HSB;
	temp = (temp << 8) | LSB;		//���¶����������������Ϊ����Ľ��
	
	
	//�����ⲿ���ǿ�����С�����������Ҫ����������ôֱ������������
	//��һ�� temp >>= 4;���ɣ�Ҳ����ֱ��ȥ��С�����ּ���
	if((temp & 0xf800) == 0x0000)	//������λ�ǲ���0����0�¶Ⱦ�Ϊ��
	{
		temp >>= 4;	//������λ��ȥ��С��������ӻ���
		temp = temp * 10;	//�������ַŵ�10��
		temp = temp + (LSB & 0x0f) *0.625;	//����С��������Ҳ������10��
	}
	
}


void main()
{
	XBYTE[8000] = 0x00;	//�ر�����LED�� 
	while(1)
	{
		Read_DS18B20_temp();
		DisPlaySMG_Temp();
	}
	
}