#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N = 510;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int n, m;
char gph[N][N];
int head[N * N * 4], idx;
struct Node { int nxt, to, w; }edge[N * N * 12];
int dist[N * N * 4];
bool st[N * N * 4];
// graph

inline bool check(int a, int b) {
	return a >= 0 and a < n and b >= 0 and b < m;
}

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

inline int get(int a, int b, int type) {
	return a * n + b + 1 + type * n * n;
}

void dijkstra(int u) {
	memset(st, 0, sizeof st);
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII>, greater<PII>> q;
	
	dist[u] = 0; q.push({0, u});
	while (q.size()) {
		int ver = q.top().second; q.pop();
		for (int i = head[ver], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (st[j]) continue;
			st[j] = true;
			if (dist[j] > dist[ver] + edge[i].w) {
				dist[j] = dist[ver] + edge[i].w;
				q.push({dist[j], j});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	memset(head, -1, sizeof head);
	cin >> n >> m;
	for (int i = 0; i < n; ++ i) cin >> gph[i];
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j) {
			if (gph[i][j] == 'S') continue;
			if (check(i - 1, j) and gph[i][j] != 'U' and gph[i - 1][j] != 'S') {
				add(get(i, j, 0), get(i - 1, j, 0), 0); 
				add(get(i, j, 1), get(i - 1, j, 0), 1);
				add(get(i, j, 2), get(i - 1, j, 0), 1);
				add(get(i, j, 3), get(i - 1, j, 0), 1);
			}
			if (check(i + 1, j) and gph[i][j] != 'D' and (gph[i + 1][j] != 'S' or i + 1 == n - 1 and j == m - 1)) {
				add(get(i, j, 1), get(i + 1, j, 1), 0); 
				add(get(i, j, 0), get(i + 1, j, 1), 1);
				add(get(i, j, 2), get(i + 1, j, 1), 1);
				add(get(i, j, 3), get(i + 1, j, 1), 1);
			}
			if (check(i, j - 1) and gph[i][j] != 'L' and gph[i][j - 1] != 'S') {
				add(get(i, j, 2), get(i, j - 1, 2), 0); 
				add(get(i, j, 1), get(i, j - 1, 2), 1);
				add(get(i, j, 0), get(i, j - 1, 2), 1);
				add(get(i, j, 3), get(i, j - 1, 2), 1);
			}
			if (check(i, j + 1) and gph[i][j] != 'R' and (gph[i][j + 1] != 'S' or i == n - 1 and j + 1 == m - 1)) {
				add(get(i, j, 3), get(i, j + 1, 3), 0); 
				add(get(i, j, 1), get(i, j + 1, 3), 1);
				add(get(i, j, 2), get(i, j + 1, 3), 1);
				add(get(i, j, 0), get(i, j + 1, 3), 1);
			}	
		}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < 4; ++ i) {
		dijkstra(1 + n * n * i);
		for (int j = 0; j < 4; ++ j)
			ans = min(ans, dist[n * n * (j + 1)]);
	}
	if (ans == 0x3f3f3f3f) puts("No Solution");
	else cout << ans << endl;
	return 0;
}
