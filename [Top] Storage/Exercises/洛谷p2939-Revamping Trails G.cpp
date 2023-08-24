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

const int N = 1e5 + 10;
const int K = 20 + 10;
const int M = 5e5 + 10;

int n, m, k;
// basic things
int head[N * K], idx;
struct node{
	int nxt, to, w;
}edge[N * K << 2];
// graph
priority_queue<PII, vector<PII>, greater<PII> > heap;
// distance and index
LL dist[N * K];
bool st[N * K];
// shortest path

inline void add(int a, int b, int c){
	edge[++ idx].to = b;
	edge[idx].nxt = head[a];
	edge[idx].w = c;
	head[a] = idx;
}

inline void dijkstra(int root){
	dist[root] = 0;
	heap.push({0, root});
	
	while (heap.size()){
		auto t = heap.top(); heap.pop();
		if (st[t.second]) continue;
		st[t.second] = true;
		
		for (int i = head[t.second]; ~i; i = edge[i].nxt){
			int j = edge[i].to;
			if (dist[j] > t.first + edge[i].w){
				dist[j] = t.first + edge[i].w;
				heap.push({dist[j], j});
			}
		}
	}
}

int main(){
	memset(dist, 0x3f3f3f3f, sizeof dist);
	memset(head, -1, sizeof head);
	// init
	
	input(n), input(m), input(k);
	for (int i = 0; i < m; i ++){
		int a, b, c;
		input(a), input(b), input(c);
		add(a, b, c), add(b, a, c);
		for (int j = 1; j <= k; j ++){
			add(a + j * n, b + j * n, c);
			add(b + j * n, a + j * n, c);
			add(a + (j - 1) * n, b + j * n, 0);
			add(b + (j - 1) * n, a + j * n, 0);
		}
	}
	// input
	dijkstra(1);
	
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 0; i <= k; i ++){
		ans = min(ans, dist[n * i + n]);
	}
	cout << ans << endl;
	
	for (int i = 1; i <= 10; i ++){
		cerr << i << " " << dist[i] << endl;
	}
	
	return 0;
}
