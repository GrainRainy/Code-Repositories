#include <bits/stdc++.h>
using namespace std;
const int N = 60 + 10;
const int M = 1e2 + 10;
const int MOD = 1e4 + 7;
int n, m, tr[N * M][26], fail[N * M], ttp;
int dp[M][N * M], ans;
bool ed[N * M];
string s;

void insert(string &s) {
	int p = 0;
	for (auto t : s) {
		if (!tr[p][t - 'A']) tr[p][t - 'A'] = ++ ttp;
		p = tr[p][t - 'A'];
	}
	ed[p] = true;
}

void build() {
	queue<int> q;
	for (int i = 0; i < 26; ++ i) if (tr[0][i]) q.push(tr[0][i]);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++ i) {
			if (tr[u][i]) {
				fail[tr[u][i]] = tr[fail[u]][i];
				ed[tr[u][i]] |= ed[tr[fail[u]][i]];
				q.push(tr[u][i]);
			} else tr[u][i] = tr[fail[u]][i];
		}
	}
} 

inline int qpow(int a, int b) {
	int res = 1;
	for (; b; a = a * a % MOD, b >>= 1) if (b & 1) res = res * a % MOD;
	return res;
}

inline void upd(int &x, const int &y) { x += y; if (x >= MOD) x -= MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> s, insert(s);
	build(), dp[0][0] = 1;
	for (int i = 1; i <= m; ++ i)
		for (int j = 0; j <= ttp; ++ j)
			for (int k = 0; k < 26; ++ k) 
				if (!ed[tr[j][k]]) upd(dp[i][tr[j][k]], dp[i - 1][j]);
	for (int i = 0; i <= ttp; ++ i) upd(ans, MOD - dp[m][i]);
	upd(ans, qpow(26, m));
	return cout << ans << '\n', 0;
}
