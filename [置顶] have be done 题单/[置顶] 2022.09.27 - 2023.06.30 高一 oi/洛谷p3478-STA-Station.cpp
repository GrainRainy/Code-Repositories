#include <iostream>
#include <cstring>
#include <algorithm>

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

const int N = 1e6 + 10;
int n;
int head[N], idx;
struct Node{
	int nxt, to;
}edge[N << 1];
// graph
LL indg[N], siz[N], sum[N], dist[N];
bool st[N];

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

void init(int u){
	st[u] = true, siz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		if (st[j]) continue;
		dist[j] = dist[u] + 1;
		init(j);
		siz[u] += siz[j];
	}
	return;
}

void dfs(int u){
	st[u] = true;
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		if (st[j]) continue;
		sum[j] = sum[u] - siz[j] + n - siz[j];
		dfs(j);
	}
}

int main(){
	memset(head, -1, sizeof head);
	
	input(n);
	int tmpa, tmpb;
	for (int i = 1; i <= n - 1; ++ i){
		input(tmpa), input(tmpb);
		add(tmpa, tmpb), add(tmpb, tmpa);
		indg[tmpb] ++, indg[tmpa] ++;
	}
	// input and init 
	init(1);
	
	for (int i = 1; i <= n; i ++)
		sum[1] += dist[i];
	memset(st, 0, sizeof st);
	
	dfs(1);
	
	LL ans = -1, ansIdx = 0;
	for (int i = 1; i <= n; ++ i){
		if (ans < sum[i]){
			ans = sum[i];
			ansIdx = i;
		}
	}
	cout << ansIdx << endl;
	return 0;
}
