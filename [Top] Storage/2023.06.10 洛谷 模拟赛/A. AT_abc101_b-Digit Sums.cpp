#include <bits/stdc++.h>
using namespace std;
int n;
int s(int x) {
	int res = 0;
	do res += x % 10, x /= 10; while (x);
	return res; 
}

int main() {
	cin >> n;
	if (!(n % s(n))) puts("Yes");
	else puts("No");
	return 0;
}
