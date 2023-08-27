#include <windows.h>
int main() {
	Sleep(2000);
	while (true) {
		keybd_event(VK_F5, 0, 0, 0);
		keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
		Sleep(200);
	}
}
