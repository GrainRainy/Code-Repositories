#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
using namespace std;
const int N = 20 + 5;
const int S = 15 + 5;
const int K = 1e3 + 10;
int n, k, tr[N * S][3], ed[N * S], fail[N * S], ttp;
int f[K][N * S], ans;
string s;

void insert(const string &s) {
	int p = 0;
	for (auto t : s) {
		if (!tr[p][t - 'A']) tr[p][t - 'A'] = ++ ttp;
		p = tr[p][t - 'A'];
	}
	ed[p] ++;
}

void build() {
	queue<int> q;
	for (int i : {0, 1, 2}) if (tr[0][i]) q.push(tr[0][i]);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i : {0, 1, 2}) {
			if (!tr[u][i]) tr[u][i] = tr[fail[u]][i];
			else fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
		}
		ed[u] += ed[fail[u]];
	}
}

inline void upd(int &x, const int &y) { if (x < y) x = y; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) cin >> s, insert(s);
	build();
	memset(f, 0xaf, sizeof f);
	for (int i = 0; i <= k; ++ i) f[i][0] = 0;
	for (int i = 1; i <= k; ++ i) 
		for (int j = 0; j <= ttp; ++ j) 
			for (int p : {0, 1, 2}) 
				upd(f[i][tr[j][p]], f[i - 1][j] + ed[tr[j][p]]);
	for (int i = 0; i <= ttp; ++ i) upd(ans, f[k][i]);
	return cout << ans << '\n', 0;
}
