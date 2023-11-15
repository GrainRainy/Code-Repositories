#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0;
	while (++ cnt) {
		system("Bdata.exe > b.in");
		system("B.exe < b.in > b.out");
		system("Bbf.exe < b.in > bbf.out");
		if (system("fc b.out bbf.out")) return 0;
		printf("AC ON #%d\n", cnt);
	}
}
