#include <iostream>
#include <Windows.h>
#include "FT4232H_DRIVER/ftd2xx.h"
#include <bitset>
using namespace std;
FT_HANDLE ftHandle;
FT_STATUS ftStatus;
FT_HANDLE ftHandle1;
FT_STATUS open();
FT_STATUS close();
FT_STATUS OPENIC();
uint16_t kaiji = 0;
uint16_t guanji = 0;

int main()
{
	while (1) 
	{
		cout << "开机操作: " << ++kaiji << endl;
		while (open() != FT_OK);
		Sleep(100);
		while (close() != FT_OK);
		Sleep(20000);
		cout << "关机操作: " << ++guanji << endl;
		while (open() != FT_OK);
		Sleep(2500);
		while (close() != FT_OK);
		cout << "等待关机45秒开始" << endl;
		Sleep(45000);
		cout << "等待关机45秒结束" << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}


FT_STATUS open()
{
	while (OPENIC() != FT_OK);
	ftStatus = FT_Open(1, &ftHandle1);
	if (ftStatus != FT_OK) {
		cout << "FT_Open1 failed" << endl;
	}
	FT_STATUS ftStatus;
	UCHAR Mask1 = 0x00; //	bit set '0' used for input, set '1' used for output	0x01 mean bit0 turn 1 ，but the output is low
	UCHAR Mode1 = 1; // set Asynchronous Bit Bang mode	//this mode can be used for GPIO
	ftStatus = FT_SetBitMode(ftHandle1, Mask1, Mode1);
	if (ftStatus == FT_OK) {
		cout << "开机按下" << endl;
	}
	else {
		cout << "按下 FAILED!" << endl;
	}
	FT_Close(ftHandle1);
	return ftStatus;
}

FT_STATUS close()
{
	while (OPENIC() != FT_OK);
	ftStatus = FT_Open(1, &ftHandle1);
	if (ftStatus != FT_OK) {
		cout << "FT_Open1 failed" << endl;
	}
	FT_STATUS ftStatus;
	UCHAR Mask1 = 0xff; //	bit set '0' used for input, set '1' used for output	0x01 mean bit0 turn 1 ，but the output is low
	UCHAR Mode1 = 1; // set Asynchronous Bit Bang mode	//this mode can be used for GPIO
	ftStatus = FT_SetBitMode(ftHandle1, Mask1, Mode1);
	if (ftStatus == FT_OK) {
		cout << "开机松开" << endl;
	}
	else {
		cout << "松开 FAILED!" << endl;
	}
	FT_Close(ftHandle1);
	return ftStatus;
}

FT_STATUS OPENIC() 
{
	ftStatus = FT_Open(0, &ftHandle);
	if (ftStatus != FT_OK) {
		//cout << "FT_Open failed" << endl;
	}
	UCHAR Mask = 0xFF; //	bit set '0' used for input, set '1' used for output	0x01 mean bit0 turn 1 ，but the output is low
	UCHAR Mode = 1; // set Asynchronous Bit Bang mode	//this mode can be used for GPIO
	ftStatus = FT_SetBitMode(ftHandle, Mask, Mode);
	if (ftStatus == FT_OK) {
		//cout << "初始化 成功" << endl;
	}
	else {
		//cout << "初始化 FAILED!" << endl;
	}
	FT_Close(ftHandle);
	return ftStatus;
}

void get()
{
	//UCHAR BitMode;
	//ftStatus = FT_GetBitMode(ftHandle, &BitMode);			//ground triggle
	//if (ftStatus == FT_OK) {
	//	cout << "BitMode contains current value" << endl;
	//}
	//else {
	//	cout << "FT_GetBitMode FAILED!" << endl;
	//}
	//printf("bit mode is 0x%02x\r\n", BitMode);
	//cout << "bit bin is " << bitset<sizeof(UCHAR) * 8>(BitMode) << endl;
}