#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, tr[N][26], fail[N], ed[N], ttp;
string s, t;
int stk[N], sv[N], top;

void insert(string s) {
	int p = 0;
	for (auto t : s) {
		if (!tr[p][t - 'a']) tr[p][t - 'a'] = ++ ttp;
		p = tr[p][t - 'a'];
	}
	ed[p] = s.size();
}

void build() {
	queue<int> q;
	for (int i = 0; i < 26; ++ i) if (tr[0][i]) q.push(tr[0][i]);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++ i) {
			if (!tr[u][i]) tr[u][i] = tr[fail[u]][i];
			else fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
		}
	}
}

void match() {
	int p = 0;
	for (int i = 0; i < s.size(); ++ i) {
		p = tr[p][s[i] - 'a'];
		stk[++ top] = i, sv[i] = p;
		if (ed[p]) top -= ed[p], p = sv[stk[top]];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s >> n;
	for (int i = 1; i <= n; ++ i) cin >> t, insert(t);
	build(), match();
	for (int i = 1; i <= top; ++ i) cout << s[stk[i]];
	return cout << '\n', 0;
}
