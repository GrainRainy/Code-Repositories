#include <bits/stdc++.h>
using namespace std;
const int L = 3e5 + 10;
const int M = 1e6 + 10;
const int MOD = 20071027;
int n, dp[L], cnt;
int tr[M][30], idx;
string s, a;
bool st[M];

void insert(string a) {
	int p = 0;
	for (auto c : a) {
		if (!tr[p][c - 'a']) tr[p][c - 'a'] = ++ idx;
		p = tr[p][c - 'a'];
	}
	st[p] = true;
}

inline void upd(int &x, int y) { x += y; (x >= MOD) and (x -= MOD); }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> s >> n) {
		memset(tr, 0, sizeof tr);
		memset(st, 0, sizeof st);
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; ++ i) cin >> a, insert(a);
		dp[s.size()] = 1;
		for (int i = s.size() - 1; ~i; -- i) {
			int p = 0;
			for (int j = i; j < s.size(); ++ j) {
				if (!tr[p][s[j] - 'a']) break;
				p = tr[p][s[j] - 'a']; 
				if (st[p]) upd(dp[i], dp[j + 1]);
			} 
		}
		cout << "Case " << ++ cnt << ": " << dp[0] << '\n';
	}
}
