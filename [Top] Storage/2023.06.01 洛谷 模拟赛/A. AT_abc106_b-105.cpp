#include <bits/stdc++.h>
using namespace std;
int n, cnt;

int calc(int n) {
	int res = 0;
	for (int i = 1; i <= n; ++ i)
		if (n % i == 0) res ++;
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 3; i <= n; ++ i) 
		if (i & 1 and calc(i) == 8) cnt ++;
	cout << cnt << endl;
	return 0;
}
