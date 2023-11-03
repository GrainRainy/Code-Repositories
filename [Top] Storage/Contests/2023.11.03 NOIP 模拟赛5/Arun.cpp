#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0;
	while (++ cnt) {
		system("Adata.exe > a.in");
		system("A.exe < a.in > a.out");
		system("Abf.exe < a.in > abf.out");
		if (system("fc a.out abf.out")) return 0;
		printf("AC ON #%d\n", cnt);
	}
}
