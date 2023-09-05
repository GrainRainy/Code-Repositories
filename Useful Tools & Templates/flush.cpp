#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
char s[10];

void full_screen() {
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);
    int cy = GetSystemMetrics(SM_CYSCREEN);
    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}

int main() {
	srand(time(0));
	s[0] = 'c', s[1] = 'o', s[2] = 'l', s[3] = 'o', s[4] = 'r', s[5] = ' ';
	full_screen();
    while (true) {
    	s[6] = (char)('A' + rand() % 6), s[7] = (char)('0' + rand() % 10);
    	system(s);
    	Sleep(5);
	}
}


