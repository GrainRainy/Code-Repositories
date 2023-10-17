#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int L = 50;
int n, m, tr[N * L][26], st[N * L], ttp;
string s;

void insert(string s) {
	int p = 0;
	for (auto t : s) {
		if (!tr[p][t - 'a']) tr[p][t - 'a'] = ++ ttp;
		p = tr[p][t - 'a'];
	}
	st[p] = 1;
}

void query(string s) {
	int p = 0;
	for (auto t : s) {
		if (!tr[p][t - 'a']) return cout << "WRONG\n", void();
		p = tr[p][t - 'a'];
	}
	if (st[p] == 2) cout << "REPEAT\n";
	else if (!st[p]) cout << "WRONG\n";
	else cout << "OK\n", st[p] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> s, insert(s);
	cin >> m;
	for (int i = 1; i <= m; ++ i) cin >> s, query(s);
	return 0;
}
