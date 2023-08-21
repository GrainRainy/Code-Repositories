#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 10;
const int M = 3e5 + 10;
int n, tr[M][26], top, cnt;
string a[N];
bool ans[N], ed[M];
bool eg[30][30];
int dg[N];

void insert(string a) {
	int p = 0;
	for (auto c : a) {
		if (!tr[p][c - 'a']) tr[p][c - 'a'] = ++ top;
		p = tr[p][c - 'a'];
	}
	ed[p] = true;
}

void topsort() {
	queue<int> q;
	for (int i = 0; i < 26; ++ i) if (!dg[i]) q.push(i);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++ i) {
			if (!eg[u][i]) continue;
			dg[i] --;
			if (!dg[i]) q.push(i);
		}
	} 
}

bool judge(int i) {
	int p = 0;
	memset(eg, 0, sizeof eg);
	memset(dg, 0, sizeof dg);
	for (auto c : a[i]) {
		if (ed[p]) return false;
		for (int i = 0; i < 26; ++ i)
			if (c - 'a' != i and tr[p][i] and !eg[c - 'a'][i])
				eg[c - 'a'][i] = true, dg[i] ++;
		p = tr[p][c - 'a'];
	}
	topsort();
	for (int i = 0; i < 26; ++ i)
		if (dg[i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i], insert(a[i]);
	for (int i = 1; i <= n; ++ i) 
		if (judge(i)) ans[i] = true, cnt ++;
	cout << cnt << endl;
	for (int i = 1; i <= n; ++ i) 
		if (ans[i]) cout << a[i] << '\n';
	return 0;
}
