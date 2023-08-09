#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;
const int N = 1e4 + 10;
const int M = 1e2 + 10;
const int DIS = 1e8 + 10;
int n, m, u, v, w, k;
int root, sum, siz[N], mx[N], dis[N];
int head[N], idx;
struct Node { int nxt, to, w; }edge[N << 1];
bool del[N], save[DIS];
int query[M], rem[DIS];
bool test[M];
int q[N], top; // ´ýÇå¿Õ¶ÓÁÐ  

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void getRt(int u, int fa) {
	siz[u] = 1, mx[u] = 0;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa or del[j]) continue;
		getRt(j, u);
		siz[u] += siz[j];
		mx[u] = max(mx[u], siz[j]);
	}
	mx[u] = max(mx[u], sum - siz[u]);
	if (mx[u] < mx[root]) root = u;
}

void getDis(int u, int fa) {
	rem[++ rem[0]] = dis[u];
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa or del[j]) continue;
		dis[j] = dis[u] + edge[i].w;
		getDis(j, u);
	}
}

void calc(int u) {
	top = 0;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (del[j]) continue;
		dis[j] = edge[i].w;
		getDis(j, u);
		
		for (int j = rem[0]; j; -- j)
			for (int k = 1; k <= m; ++ k)
				if (query[k] >= rem[j]) 
					test[k] |= save[query[k] - rem[j]];
		
		for (int &j = rem[0]; j; -- j)
			q[++ top] = rem[j], save[rem[j]] = 1;
	}
	for (int i = 1; i <= top; ++ i)
		save[q[i]] = 0;
}

void solve(int u) {
	del[u] = save[0] = true;
	calc(u);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (del[j]) continue;
		sum = siz[j];
		mx[root = 0] = DIS;
		getRt(j, 0);
		solve(root);
	}
}

int main() {
	input(n), input(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i < n; ++ i) {
		input(u), input(v), input(w);
		add(u, v, w), add(v, u, w);
	}
	for (int i = 1; i <= m; ++ i) input(query[i]);
	
	mx[root] = sum = n;
	getRt(1, 0);
	solve(root);
	
	for (int i = 1; i <= m; ++ i)
		puts(test[i] ? "AYE" : "NAY");
	return 0;
}
