#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 5e4 + 100;
const int M = 1e5 + 100;
const int K = 10 + 2 + 5;
const int S = (1 << K);
const LL INF = 1e10;
int n, m, k, s, t;
// basic things
int head[N], idx;
struct node{
	int nxt, to, w;
}edge[M];
// graph
bool st[N];
LL dist[N];
// shortest path
int dots[K];
LL save[K][K];
int ans = 0x3f3f3f3f;
LL f[K + 10][S + 10];

inline void add(int a, int b, int w){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	edge[idx].w = w;
	head[a] = idx;
}

void djikstra(int root){
	memset(st, 0, sizeof st);
	memset(dist, 0x3f3f3f3f, sizeof dist);
	// array init
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	dist[root] = 0;
	heap.push({0, root});
	while (heap.size()){
		int distance = heap.top().first;
		int ver = heap.top().second;
		heap.pop();
		
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = head[ver]; ~i; i = edge[i].nxt){
			int j = edge[i].to;
			if (dist[j] > dist[ver] + edge[i].w){
				dist[j] = dist[ver] + edge[i].w;
				heap.push({dist[j], j});
			}
		}
	}
}

int main(){
	memset(head, -1, sizeof head);
	
	input(n), input(m), input(k), input(s), input(t);
	for (int i = 1; i <= m; i ++){
		int a, b, c; input(a), input(b), input(c);
		add(a, b, c);
	}
	
	for (int i = 1; i <= k; i ++){
		input(dots[i]);
	}
	// input
	dots[0] = s, dots[k + 1] = t;
	for (int i = 0; i <= k + 1; i ++){
		djikstra(dots[i]);
		for (int j = 0; j <= k + 1; j ++){
				save[i][j] = dist[dots[j]];
		}
	}
	if (k == 0){
		cout << (save[0][k + 1] >= INF ? -1 : save[0][k + 1]) << endl;
		return 0;
	}
	djikstra(s);
	for (int i = 0; i <= K; i ++)
		for (int j = 0; j < (1 << K); j ++)
			f[i][j] = INF;
	for (int i = 1; i <= k; i ++)
		f[i][1 << (i - 1)] = dist[dots[i]];
	// init
	for (int j = 1; j < (1 << k); j ++)
		for (int i = 1; i <= k; i ++)
			if ((j >> (i - 1)) & 1)
				for (int u = 1; u <= k; u ++) {
					if (((j >> (u - 1)) & 1) && u != i)
						f[i][j] = min(f[i][j], f[u][j - (1 << (i - 1))] + save[u][i]);
				}
	
	LL ans = INF;
	for (int i = 1; i <= k; i ++){
			ans = min(ans, (LL)f[i][(1 << k) - 1] + save[i][k + 1]);
	}
	
	if (ans >= INF) return puts("-1"), 0;
	cout << ans << endl;
	return 0;
}
