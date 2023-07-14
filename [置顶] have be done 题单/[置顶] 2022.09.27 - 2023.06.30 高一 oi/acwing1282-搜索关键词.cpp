#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e4 + 10;
const int L = 50 + 10;
const int M = 1e6 + 10;

int t, n;
// bases 
int tr[N * L][26], cnt[N * L], nxt[N * L], tTol;
char s[M];
int res;

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
		while (p) {
			res += cnt[p];
			cnt[p] = 0;
			p = nxt[p];
		}
	}
	return res;
}

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		memset(tr, 0, sizeof(int) * (n * L + 10));
		memset(cnt, 0, sizeof(int) * (n * L + 10));
		memset(nxt, 0, sizeof(int) * (n * L + 10));
		res = 0;
		for (int i = 1; i <= n; ++ i) cin >> s, insert(s);
		build();
		cin >> s;
		printf("%d\n", query(s));
	}
	return 0;
}
