#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0;
	while (++ cnt) {
		system("Adata.exe > a.in");
		double st = clock();
		system("Anw.exe < a.in > a.out");
		double ed = clock();
//		system("Abf.exe < a.in > abf.out");
//		if (system("fc a.out abf.out")) return 0;
		printf("AC ON #%d time %.2lf\n", cnt, (ed - st) / CLOCKS_PER_SEC);
	}
}
