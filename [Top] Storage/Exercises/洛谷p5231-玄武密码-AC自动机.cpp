#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int L = 1e2 + 10;
int n, m;
string s, a[N];
int tr[N * L][4], fail[N * L], idx;
bool st[N * L];
unordered_map<char, int> mp;

void insert(string a) {
	int p = 0;
	for (auto c : a) {
		if (!tr[p][mp[c]]) tr[p][mp[c]] = ++ idx;
		p = tr[p][mp[c]];
	}
}

void build() {
	queue<int> q;
	for (int i = 0; i < 4; ++ i)
		if (tr[0][i]) q.push(tr[0][i]);
	while (q.size()) {
		int t = q.front(); q.pop();
		for (int i = 0, p; i < 4; ++ i) {
			p = tr[t][i];
			if (!p) tr[t][i] = tr[fail[t]][i];
			else fail[p] = tr[fail[t]][i], q.push(p);
		}
	}
}

void run() {
	int p = 0;
	for (auto c : s) {
		p = tr[p][mp[c]];
		for (int i = p; i and !st[i]; i = fail[i])
			st[i] = true;
	}
}

int bfs(string a) {
	int p = 0, res = 0;
	for (int i = 0; i < a.size(); ++ i) {
		p = tr[p][mp[a[i]]];
		if (st[p]) res = i + 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	mp['E'] = 0, mp['S'] = 1, mp['W'] = 2, mp['N'] = 3;
	for (int i = 1; i <= m; ++ i) cin >> a[i], insert(a[i]);
	build(), run();
	for (int i = 1; i <= m; ++ i) cout << bfs(a[i]) << '\n';
	return 0;
}
