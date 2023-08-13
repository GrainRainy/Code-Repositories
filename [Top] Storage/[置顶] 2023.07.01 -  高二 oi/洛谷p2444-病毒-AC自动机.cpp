#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 10;
int n; string s;
int tr[N][2], idx, fail[N];
bool ed[N], np[N], pp[N];

void insert(string s) {
	int p = 0;
	for (auto c : s) {
		if (!tr[p][c - '0']) tr[p][c - '0'] = ++ idx;
		p = tr[p][c - '0'];
	}
	ed[p] = true;
}

void build() {
	queue<int> q;
	if (tr[0][0]) q.push(tr[0][0]);
	if (tr[0][1]) q.push(tr[0][1]);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 2; ++ i) {
			if (!tr[u][i]) tr[u][i] = tr[fail[u]][i];
			else {
				int fl = fail[u];
				while (fl and !tr[fl][i]) fl = fail[fl];
				fail[tr[u][i]] = tr[fl][i];
				if (tr[fl][i] and ed[tr[fl][i]]) ed[tr[u][i]] = true;
				q.push(tr[u][i]);
			}
		}
	}
}

void dfs(int u) {
	np[u] = true;
	for (int i = 0; i < 2; ++ i) {
		if (np[tr[u][i]]) { cout << "TAK\n"; exit(0); }
		else if (!ed[tr[u][i]] and !pp[tr[u][i]]) {
			pp[tr[u][i]] = true; dfs(tr[u][i]);	
		}
	}
	np[u] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> s, insert(s);
	build();
	dfs(0);
	cout << "NIE\n";
	return 0;
}
