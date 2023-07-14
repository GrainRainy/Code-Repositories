#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2e5 + 10;
int n;
string tmp; int node[N];
int tr[N][30], fail[N], sum[N], tTol;
// Trie & AC Automaton 
int head[N], idx;
struct Node { int nxt, to; } edge[N];
// graph 

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void insert(string a, int id) {
	int p = 0;
	for (int i = 0, c; i < a.size(); ++ i) {
		c = a[i] - 'a';
		if (!tr[p][c]) tr[p][c] = ++ tTol;
		p = tr[p][c];
	}
	node[id] = p;
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
		sum[p] ++;
	}
}

void dfs(int u) {
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		dfs(j);
		sum[u] += sum[j];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	memset(head, -1, sizeof head);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> tmp, insert(tmp, i);
	build();
	cin >> tmp; query(tmp);
	for (int i = 1; i <= tTol; ++ i) add(fail[i], i);
	dfs(0);
	for (int i = 1; i <= n; ++ i) cout << sum[node[i]] << endl;
	return 0;
}
