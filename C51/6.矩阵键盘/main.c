#include "reg52.h"

sfr P4 = 0xC0;		//P4�� ͷ�ļ�����û�ã������������ֲ������У�����ֱ���ֶ��������ĵ�ַ

sbit row1 = P3^0;
sbit row2 = P3^1;
sbit row3 = P3^2;
sbit row4 = P3^3;

sbit column4 = P3^4;
sbit column3 = P3^5;
sbit column2 = P4^2;
sbit column1 = P4^4;

unsigned char code SMG_duanma[18]=
	{0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,
	 0x88,0x80,0xc6,0xc0,0x86,0x8e,
	 0xbf,0x7f};		//0-9,A-F,-��.
	
	 
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

void DisplayKeyNum(unsigned char value)
{
	SelectHC573(6);
	P0 = 0x01;
	SelectHC573(7);
	P0 = value;
}
unsigned char key_num;
void ScanKeyMulti()
{
//--------��һ��
	row1 = 0; row2 = row3 = row4 = 1; //��һ����0
	column1 = column2 = column3 = column4 = 1; //����ȫ��1
	if(column1 == 0)	//[1,1]=0 ����
	{
		while(column1 == 0);
		key_num = 0;
		DisplayKeyNum(SMG_duanma[key_num]);
	}
	else if(column2 == 0)	//[1,2]=1 ����
	{
		while(column2 == 0);
		key_num = 1;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
	else if(column3 == 0)	//[1,3]=2 ����
	{
		while(column3 == 0);
		key_num = 2;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
	else if(column4 == 0)	//[1,4]=3 ����
	{
		while(column4 == 0);
		key_num = 3;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
//--------�ڶ���	
	row2 = 0; row1 = row3 = row4 = 1; //�ڶ�����0
	column1 = column2 = column3 = column4 = 1; //����ȫ��1
	if(column1 == 0)	//[2,1]=4 ����
	{
		while(column1 == 0);
		key_num = 4;
		DisplayKeyNum(SMG_duanma[key_num]);
	}
	else if(column2 == 0)	//[2,2]=5 ����
	{
		while(column2 == 0);
		key_num = 5;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
	else if(column3 == 0)	//[2,3]=6 ����
	{
		while(column3 == 0);
		key_num = 6;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
	else if(column4 == 0)	//[2,4]=7 ����
	{
		while(column4 == 0);
		key_num = 7;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
//--------������	
	row3 = 0; row1 = row2 = row4 = 1; //��������0
	column1 = column2 = column3 = column4 = 1; //����ȫ��1
	if(column1 == 0)	//[3,1]=8 ����
	{
		while(column1 == 0);
		key_num = 8;
		DisplayKeyNum(SMG_duanma[key_num]);
	}
	else if(column2 == 0)	//[3,2]=9 ����
	{
		while(column2 == 0);
		key_num = 9;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
	else if(column3 == 0)	//[3,3]=a ����
	{
		while(column3 == 0);
		key_num = 10;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
	else if(column4 == 0)	//[3,4]=b ����
	{
		while(column4 == 0);
		key_num = 11;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
//--------������	
	row4 = 0; row1 = row2 = row3 = 1; //��������0
	column1 = column2 = column3 = column4 = 1; //����ȫ��1
	if(column1 == 0)	//[4,1]=c ����
	{
		while(column1 == 0);
		key_num = 12;
		DisplayKeyNum(SMG_duanma[key_num]);
	}
	else if(column2 == 0)	//[4,2]=d ����
	{
		while(column2 == 0);
		key_num = 13;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
	else if(column3 == 0)	//[4,3]=e ����
	{
		while(column3 == 0);
		key_num = 14;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
	else if(column4 == 0)	//[4,4]=f ����
	{
		while(column4 == 0);
		key_num = 15;
		DisplayKeyNum(SMG_duanma[key_num]);
	}	
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
	InitSystem();
	while(1)
	{
		ScanKeyMulti();
	}
}
