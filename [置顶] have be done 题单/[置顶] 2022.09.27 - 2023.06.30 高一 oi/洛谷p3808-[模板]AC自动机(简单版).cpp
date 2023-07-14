#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e6 + 10;
int n;
int tr[N][30], cnt[N], nxt[N], tTol;
char s[N];

void insert(char s[]) {
	int pos = 0;
	for (int i = 0, t; s[i]; ++ i) {
		t = s[i] - 'a';
		if (!tr[pos][t]) tr[pos][t] = ++ tTol;
		pos = tr[pos][t];
	}
	cnt[pos] ++;
	return;
}

void build() {
	queue<int> q;
	for (int i = 0; i < 26; ++ i) 
		if (tr[0][i]) q.push(tr[0][i]);
	while (q.size()) {
		int t = q.front(); q.pop();
		for (int i = 0, pos; i < 26; ++ i) {
			pos = tr[t][i];
			if (!pos) tr[t][i] = tr[nxt[t]][i];
			else nxt[pos] = tr[nxt[t]][i], q.push(pos);
		}
	}
}

int query(char s[]) {
	int res = 0;
	for (int i = 0, j = 0, t; s[i]; ++ i) {
		t = s[i] - 'a';
		j = tr[j][t];
		
		int p = j;
		while (p and cnt[p]) {
			res += cnt[p];
			cnt[p] = 0;
			p = nxt[p];
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> s, insert(s);
	build();
	cin >> s;
	cout << query(s) << endl;
	return 0;
}
