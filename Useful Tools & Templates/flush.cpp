#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
char s[10];

void st(int w, int h) {
    HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT wrt = {0, 0, w - 1, h - 1};
    SetConsoleWindowInfo(hStdOutput, TRUE, &wrt);
    COORD coord = {w, h};
    SetConsoleScreenBufferSize(hStdOutput, coord);
}

int main() {
	srand(time(0));
	s[0] = 'c', s[1] = 'o', s[2] = 'l', s[3] = 'o', s[4] = 'r', s[5] = ' ';
	st(35, 15);
    while (true) {
    	s[6] = (char)('A' + rand() % 6), s[7] = (char)('0' + rand() % 10);
    	system(s);
    	Sleep(5);
	}
}


