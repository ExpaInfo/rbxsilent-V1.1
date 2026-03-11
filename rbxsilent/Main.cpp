/*
----------------------------------------------
rbxsilent
Created July 2021
Updated 11 March 2026
Author tostring#1337 and Expainfo
----------------------------------------------
*/

#include <Windows.h>
#include <cstring>

static BOOL CALLBACK WindowEnumProc(HWND hWnd, LPARAM) {
    if (!IsWindowVisible(hWnd)) return TRUE;

    char title[256] = {};
    int len = GetWindowTextA(hWnd, title, sizeof(title));
    if (len <= 0) return TRUE;

    if (strcmp(title, "SomeWindowTitle") == 0) {
        // Do one lightweight action here
    }

    return TRUE;
}

int main() {
    while (true) {
        EnumWindows(WindowEnumProc, 0);
        Sleep(1000);
    }
}
