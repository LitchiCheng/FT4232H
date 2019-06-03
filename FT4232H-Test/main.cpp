#include <iostream>
#include <Windows.h>
#include "FT4232H_DRIVER/ftd2xx.h"
//#pragma comment(lib,"ftd2xx.lib")
using namespace std;

int main()
{
	FT_HANDLE ftHandle;
	FT_STATUS ftStatus;

	ftStatus = FT_Open(0, &ftHandle);
	if (ftStatus != FT_OK) {
		// FT_Open failed
		printf("\r\nFT_OPEN FAILED\r\n");
		//return ;
	}
	UCHAR Mask = 0x02; //	bit set '0' used for input, set '1' used for output
	UCHAR Mode = 1; // set Asynchronous Bit Bang mode	//this mode can be used for GPIO
	ftStatus = FT_SetBitMode(ftHandle, Mask, Mode);
	if (ftStatus == FT_OK) {
		// Asynchronous Bit bang Mode enabled
		printf("bitbang is ok\r\n");
	}
	else {
		// FT_SetBitMode FAILED!
	}
	//while (1) {
	//	UCHAR BitMode;
	//	ftStatus = FT_GetBitMode(ftHandle, &BitMode);
	//	if (ftStatus == FT_OK) {
	//		// BitMode contains current value
	//	}
	//	else {
	//		// FT_GetBitMode FAILED!
	//		printf("FT_GetBitMode is failed\r\n");
	//	}
	//	printf("bit mode is 0x%02x\r\n", BitMode);
	//	Sleep(100);
	//}
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

