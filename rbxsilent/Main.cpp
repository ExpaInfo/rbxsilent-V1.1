/*
----------------------------------------------
rbxsilent
Created July 2021
Updated 11 March 2026
Author tostring#1337 and Expainfo
----------------------------------------------
*/

#include <Windows.h>

// Write a string to the console using only Win32 API (no CRT I/O overhead)
static void ConWrite(const char* msg) {
    DWORD written;
    WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), msg, lstrlenA(msg), &written, NULL);
}

static BOOL CALLBACK windcallback(HWND hWnd, LPARAM lparam) {
    if (!IsWindowVisible(hWnd))
        return TRUE;

    char buffer[16];
    int len = GetWindowTextA(hWnd, buffer, sizeof(buffer));

    // Compare without any CRT - just manual byte check
    if (len == 6 &&
        buffer[0] == 'R' && buffer[1] == 'o' && buffer[2] == 'b' &&
        buffer[3] == 'l' && buffer[4] == 'o' && buffer[5] == 'x') {
        ShowWindow(hWnd, SW_HIDE);
        PostMessage(hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
        ConWrite("Found roblox window\n");
    }

    return TRUE;
}

int main() {
    ConWrite("All roblox clients that are open/opened will now be hidden.\n");

    SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);

    while (true) {
        EnumWindows(windcallback, 0);
        Sleep(2000);
    }
    return 0;
}
