#include <bits/stdc++.h>
using namespace std;
using UL = unsigned long long;
const int N = 1e3 + 10;
const int P = 13331;
const int Q = 131;
int n, m, a, b, cnt;
char s[N];
UL p[N], q[N], pf[N][N], tmp[N], qa, pb;
unordered_map<UL, bool> mp;

UL hsh(int i, int j) {
	return pf[i][j] - pf[i - a][j] * qa - pf[i][j - b] * pb + pf[i - a][j - b] * qa * pb;
}

UL qpow(UL a, int b) {
	UL res = 1;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> a >> b;
	qa = qpow(Q, a), pb = qpow(P, b);
	for (int i = 1; i <= n; ++ i) {
		cin >> s + 1;
		for (int j = 1; j <= m; ++ j) 
			pf[i][j] = pf[i][j - 1] * P + (s[j] - '0' + 1);
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			pf[i][j] += pf[i - 1][j] * Q;
	for (int i = a; i <= n; ++ i)
		for (int j = b; j <= m; ++ j)
			mp[hsh(i, j)] = true;
	cin >> cnt;
	while (cnt --) {
		memset(tmp, 0, sizeof(int) * (n + 10));
		for (int i = 1; i <= a; ++ i) {
			cin >> s + 1;
			for (int j = 1; j <= b; ++ j)
				tmp[i] = tmp[i] * P + (s[j] - '0' + 1);
		}
		for (int i = 1; i <= a; ++ i) tmp[i] += tmp[i - 1] * Q;
		cout << (mp.find(tmp[a]) == mp.end() ? '0' : '1') << '\n';
	}
	return 0;
}
