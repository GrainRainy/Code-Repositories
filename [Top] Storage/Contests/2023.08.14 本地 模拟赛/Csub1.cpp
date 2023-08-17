#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 100 + 10;
int n, p[N];
int dg[N];
bool f;

int count(LL x) {
	int cnt = 0;
	while (x) cnt += x & 1, x >>= 1;
	return cnt;
}

int main() {
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> p[i];
	for (LL s = 1; s < (1 << n) - 1; ++ s) { // ( 
		if (count(s) != n >> 1) continue;
		f = true;
		for (int i = 1, pre = 0; i <= n; ++ i) {
			if ((s >> i - 1) & 1) pre ++;
			else pre --;
			if (pre < 0) { f = false; break; }
		}
		if (!f) continue;
		memset(dg, 0, sizeof(int) * (n + 10));
		for (int i = 1; i <= n; ++ i) {
			if ((s >> i - 1) & 1) dg[i] ++, dg[p[i]] ++;
			if (dg[i] > 1 or dg[p[i]] > 1) f = false;
		}
		if (!f) continue;
		for (int i = 1; i <= n; ++ i) {
			if ((s >> i - 1) & 1) cout << '(';
			else cout << ')';
		}
		cout << endl;
		return 0;
	}
	return 0;
}
