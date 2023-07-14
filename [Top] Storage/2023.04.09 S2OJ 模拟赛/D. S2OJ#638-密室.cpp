#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
using PII = pair<int, int>;
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

const int N = 1e3 + 10;
const int M = 5e3 + 10;
const int K = 5;

int n, m, k;

int tmpa, tmpb;
int head[N], idx;
struct Node{
	int nxt, to;
}edge[M << 1];
// graph for subtask k == 0
int dist[N];
bool st[N];
queue<PII> q;

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

void topsort(){
	memset(st, 0, sizeof st);
	memset(dist, 0x3f, sizeof dist);
	// array init
	dist[1] = 0;
	q.push({0, 1});
	while (q.size()){
		int distance = q.front().first;
		int ver = q.front().second;
		q.pop();
		
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = head[ver]; ~i; i = edge[i].nxt){
			int j = edge[i].to;
			if (dist[j] > dist[ver] + 1){
				dist[j] = dist[ver] + 1;
				q.push({dist[j], j});
			}
		}
	}
}

int main(){
	memset(head, -1, sizeof head);
	// init 
	input(n), input(m), input(k);	
	if (!k){
		for (int i = 1; i <= m; i ++){
			input(tmpa), input(tmpb);
			add(tmpa, tmpb);
		}
		topsort();
		if (dist[n] == 0x3f3f3f3f) puts("No Solution");
		else cout << dist[n] << '\n';
	}
	else puts("No Solution");
	return 0;
}
