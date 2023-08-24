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

const int N = 1000 + 10;
const int M = 1e4 + 100;

int n, p, k;
// basic things
int head[N], idx;
struct node{
	int nxt, to;
	LL w;
}edge[M << 1];
// graph
LL dist[N];
bool st[N];
// shortest path

inline void add(int a, int b, int c){
	edge[++ idx] = {head[a], b, c};
	head[a] = idx;
}

inline LL spfa(int maxn){
	memset(dist, 0x3f, sizeof dist);
	queue<LL> q;
	dist[1] = 0, st[1] =true, q.push(1);
	
	while (q.size()){
		auto t = q.front(); q.pop();
		st[t] = false;
		
		for (int i = head[t]; ~i; i = edge[i].nxt){
			int j = edge[i].to;
			
			int val = edge[i].w > maxn ? 1 : 0;
			if (dist[j] > dist[t] + val){
				dist[j] = dist[t] + val;
				q.push(j);
			}
		}
	}
	return dist[n];
}

int main(){
	memset(head, -1, sizeof head);
	// init
	
	input(n), input(p), input(k);
	for (int i = 0; i < p; i ++){
		int tmpa, tmpb, tmpc;
		input(tmpa), input(tmpb), input(tmpc);
		add(tmpa, tmpb, tmpc), add(tmpb, tmpa, tmpc);
	}
	// input
	LL l = 1, r = 1000000;
	int ans = 0;
	while (l < r){
		LL mid = l + r >> 1;
		if (spfa(mid) <= k) r = mid;
		else l = mid + 1;
	}
//	cout << l << endl;
	cout << ((l != 1 and r != 1000000) ? l : -1) << endl;
}
