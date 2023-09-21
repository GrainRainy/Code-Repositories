#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string a, b;
int nxt[N], sv[N], stk[N], top;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> a >> b, a = " " + a, b = " " + b;
	for (int i = 2, j = 0; i < b.size(); ++ i) {
		while (j and b[i] != b[j + 1]) j = nxt[j];
		if (b[i] == b[j + 1]) j ++;
		nxt[i] = j;
	}
	for (int i = 1, j = 0; i < a.size(); ++ i) {
		while (j and a[i] != b[j + 1]) j = nxt[j];
		if (a[i] == b[j + 1]) j ++;
		stk[++ top] = i, sv[i] = j;
		if (j == b.size() - 1) top -= b.size() - 1, j = sv[stk[top]];
	}
	for (int i = 1; i <= top; ++ i) cout << a[stk[i]];
	return cout << '\n', 0;
}
