#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 110;
bool f;
int n, m;
char gph[N][N];
map<PII, bool> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> gph[i] + 1;
	
	for (int i = 1; i <= n; ++ i) {
		f = false;
		for (int j = 1; j <= m; ++ j) f |= (gph[i][j] == '#');
		if (!f) st[{i, 0}] = true;
	}
	for (int j = 1; j <= m; ++ j) {
		f = false;
		for (int i = 1; i <= n; ++ i) f |= (gph[i][j] == '#');
		if (!f) st[{0, j}] = true;
	}
	
	for (int i = 1; i <= n; ++ i) {
		f = false;
		for (int j = 1; j <= m; ++ j)
			if (!st[{i, 0}] and !st[{0, j}]) 
				cout << gph[i][j], f = true;
		if (f) cout << '\n';
	}
	return 0;
}
