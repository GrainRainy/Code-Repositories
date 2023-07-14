#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^'0');
	if (f) x = -x;
}

const int K = 55;
const int M = 1e3 + 10;

int n, m, k;
int head[K * K], idx;
struct node{
	int nxt, to, w;
}edge[K * M << 2];
// graph
int dist[K * K], st[K * K];
// spfa

inline void add(int a, int b, int c){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	edge[idx].w = c;
	head[a] = idx;
}

inline void spfa(int root){
	queue<int> q;
	dist[root] = 0, st[root] = true, q.push(root);
	
	while (q.size()){
		auto t = q.front(); q.pop(), st[t] = false;
		for (int i = head[t]; ~i; i = edge[i].nxt){
			int j = edge[i].to;
			if (dist[j] > dist[t] + edge[i].w){
				dist[j] = dist[t] + edge[i].w;
				if (!st[j]) q.push(j), st[j] = true;
			}
		}
	}
}

int main(){
	memset(dist, 0x3f, sizeof dist);
	memset(head, -1, sizeof head);
	
	input(n), input(m), input(k);
	for (int i = 0; i < m ; i ++){
		int a, b, c;
		input(a), input(b), input(c);
		for (int j = 0; j <= k; j ++){
			add(a + j * n, b + j * n, c);
			add(b + j * n, a + j * n, c);
			
		}
		for (int j = 0; j < k; j ++){
			add(a + j * n, b + (j + 1) * n, c / 2);
			add(b + j * n, a + (j + 1) * n, c / 2);
		}
	}
	// input
	
	spfa(1);
	
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= k; i ++)
		ans = min(ans, dist[n + i * n]);
	cout << ans << endl;
	return 0;
}
