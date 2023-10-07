#include <bits/stdc++.h>
#define DEBUG cerr << "-- DBBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 5e2 + 10;
int n, k;
char s[N], nw[N], c[10] = {'(', '*', ')'};
int pos[N], res;

void dfs(int p) {
	if (p == n + 1) {
		int v = 0, lc = 0;
		for (int i = 1; i <= n; ++ i) {
			if (nw[i] == '*') lc ++;
			else {
				lc = 0;
				if (nw[i] == '(') {
					v ++, pos[v] = i;
				} else if (nw[i] == ')') {
					if (nw[pos[v] - 1] == '*' and nw[i + 1] == '*')
						return;
					pos[v] = 0, v --;
				}
			}
			if (lc > k or v < 0) return;
		}
		if (lc or v) return;
		return res ++, void();
	}
	if (s[p] != '?') return dfs(p + 1);
	for (int i = 0; i < 3; ++ i) 
		nw[p] = c[i], dfs(p + 1);
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k >> s + 1;
	memcpy(nw, s, sizeof s);
	dfs(1);
	cout << res << '\n';
	return 0;
}
