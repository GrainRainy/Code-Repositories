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
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n'){
	if (x < 0) putchar('-'), x = -x;
	static short st[64], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 100;

LL h, x, y, z;

int head[N], idx;
struct node{
	int nxt, to, w;
}edge[N << 1];
// graph
LL dist[N];
bool st[N];
LL ans;

inline void add(int a, int b, int c){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	edge[idx].w = c;
	head[a] = idx;
}

inline void dijkstra(int root){
	queue<int> q;
	dist[root] = 1, st[root] = true; q.push(root);
	
	while (q.size()){
		auto t = q.front(); q.pop();
		st[t] = false;
		for (int i = head[t]; ~i; i = edge[i].nxt){
			int j = edge[i].to;
			if (dist[j] > dist[t] + edge[i].w){
				dist[j] = dist[t] + edge[i].w;
				if (!st[j]) q.push(j), st[j] = true;
			}
		}
	}
}
// i found it seems not to be dijkstra when i just finished it
// but i forget how to write dijkstra /kk 

int main(){
	memset(head, -1, sizeof head);
	input(h), input(x), input(y), input(z);
	// input and init head
	if (x == 1 or y == 1 or z == 1) return output(h), 0;
	// special judgements
	
	for (int i = 0; i < x; i ++){
		add(i, (i + y) % x, y);
		add(i, (i + z) % x, z);
	}
	
	memset(dist, 0x3f3f3f3f, sizeof dist);
	dijkstra(1);
	
	for (int i = 0; i < x; i ++)
		if (dist[i] <= h) ans += (h - dist[i]) / x + 1;
	
	output(ans);
	return 0;
}
