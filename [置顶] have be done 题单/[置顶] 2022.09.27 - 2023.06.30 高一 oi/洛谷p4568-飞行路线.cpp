#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define min(a, b) ((a > b) ? (b) : (a))

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

const int N = 1e4 + 100;
const int M = 5e4 + 100;
const int K = 10 + 5;

int n, m, k;
int s, t;
// basis
int head[N * K << 1], idx;
struct node{
	int nxt, to, w;
}edge[M * K * 4];
// graph
int dist[N * K];
bool st[N * K];
priority_queue<PII, vector<PII>, greater<PII>> heap;
// distance and index
// shortest path

inline void add(int a, int b, int c){
	edge[++ idx].to = b;
	edge[idx].nxt = head[a];
	edge[idx].w = c;
	head[a] = idx;
}

inline void djikstra(int root){
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
			if (dist[j] > distance + edge[i].w){
				dist[j] = distance + edge[i].w;
				heap.push({dist[j], j});
			}
		}
	}
}

signed main(){
	memset(dist, 0x3f, sizeof dist);
	memset(head, -1, sizeof head);
	// init
	
	input(n), input(m), input(k);
	input(s), input(t);
	for (int i = 1; i <= m; i ++){
		int a, b, c; input(a), input(b), input(c);
		add(a, b, c), add(b, a, c);
		for (int j = 1; j <= k; j ++){
			add(a + j * n, b + j * n, c);
			add(b + j * n, a + j * n, c);
			add(a + (j - 1) * n, b + j * n, 0);
			add(b + (j - 1) * n, a + j * n, 0);
		}
	}
	// input and add
	djikstra(s);
	
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= k; ++ i)
		ans = min(dist[t + i * n], ans);
	
	cout << ans << endl;
}
