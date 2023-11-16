#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0;
	while (++ cnt) {
		system("data.exe > b.in");
		double st = clock();
		system("magic.exe < b.in > b.out");
		double ed = clock();
		system("bf.exe < b.in > bbf.out");
		if (system("fc b.out bbf.out")) return 0;
		printf("AC ON #%d with time %.2lfs\n", cnt, (ed - st) / CLOCKS_PER_SEC);
	}
}
