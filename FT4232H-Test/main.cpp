#include <iostream>
#include <Windows.h>
#include "FT4232H_DRIVER/ftd2xx.h"

using namespace std;

int main()
{
	FT_HANDLE ftHandle;
	FT_STATUS ftStatus;

	ftStatus = FT_Open(0, &ftHandle);
	if (ftStatus != FT_OK) {
		// FT_Open failed
		//return ;
	}
	UCHAR Mask = 1; //	bit set '0' used for input, set '1' used for output
	UCHAR Mode = 1; // set Asynchronous Bit Bang mode	//this mode can be used for GPIO
	ftStatus = FT_SetBitMode(ftHandle, Mask, Mode);
	if (ftStatus == FT_OK) {
		// Asynchronous Bit bang Mode enabled
	}
	else {
		// FT_SetBitMode FAILED!
	}
	UCHAR BitMode;
	ftStatus = FT_GetBitMode(ftHandle, &BitMode);
	if (ftStatus == FT_OK) {
		// BitMode contains current value
	}
	else {
		// FT_GetBitMode FAILED!
	}
	printf("bit mode is 0x%02x\r\n", BitMode);
	FT_Close(ftHandle);

	system("pause");
	return 0;
}

