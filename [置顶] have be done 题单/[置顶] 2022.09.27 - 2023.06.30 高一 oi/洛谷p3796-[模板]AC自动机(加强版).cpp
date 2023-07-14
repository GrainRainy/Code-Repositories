#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 150 + 10;
const int L = 70 + 10;

int n;
string tmp;
int tr[N * L][30], id[N * L], fail[N * L], idx;
struct Query { 
	string a;
	int id, cnt; 
	bool operator < (const Query &t) const {
		return cnt ^ t.cnt ? cnt > t.cnt : id < t.id;
	}
}q[N];

void insert(string a, int tmpId) {
	int p = 0;
	for (int i = 0, c; i < a.size(); ++ i) {
		c = a[i] - 'a';
		if (!tr[p][c]) tr[p][c] = ++ idx;
		p = tr[p][c];
	}
	id[p] = tmpId;
	return;
}

void build() {
	queue<int> q;
	for (int i = 0; i < 26; ++ i)
		if (tr[0][i]) q.push(tr[0][i]);
	
	while (q.size()) {
		int t = q.front(); q.pop();
		for (int i = 0, p = 0; i < 26; ++ i) {
			p = tr[t][i];
			if (!p) tr[t][i] = tr[fail[t]][i];
			else fail[p] = tr[fail[t]][i], q.push(p);
		}
	}
}

void query(string a) {
	for (int i = 0, p = 0; i < a.size(); ++ i) {
		p = tr[p][a[i] - 'a'];
		for (int nxt = p; nxt; nxt = fail[nxt]) 
			q[id[nxt]].cnt ++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	while (cin >> n, n) {
		idx = 0;
		memset(tr, 0, sizeof(int) * (n * L + 5) * 30);
		memset(id, 0, sizeof(int) * (n * L + 5));
		memset(fail, 0, sizeof(int) * (n * L + 5));
		for (int i = 1; i <= n; ++ i) {
			cin >> q[i].a; insert(q[i].a, i);
			q[i].id = i, q[i].cnt = 0;
		}
		build();
		cin >> tmp; query(tmp);
		sort(q + 1, q + n + 1);
		cout << q[1].cnt << endl;
		for (int i = 1; i <= n and q[i].cnt == q[1].cnt; ++ i)
			cout << q[i].a << '\n';
	}
	return 0;
}
