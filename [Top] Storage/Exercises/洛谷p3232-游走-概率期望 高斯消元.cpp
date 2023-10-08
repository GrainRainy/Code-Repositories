#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
const int M = 1.25e5;
const double eps = 1e-12;
int n, m, dg[N], head[N], idx, top;
struct Node { int nxt, to; }edge[M << 1];
double co[N][N], stk[M], res;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void Gauss() {
	for (int i = 1; i < n; ++ i) {
		int mp = i;
		for (int j = i + 1; j < n; ++ j)
			if (fabs(co[j][i]) > fabs(co[mp][i])) mp = j;
		swap(co[mp], co[i]);
		for (int j = 1; j < n; ++ j) {
			if (j == i) continue;
			for (int k = i + 1; k <= n; ++ k)
				co[j][k] -= co[i][k] * co[j][i] / co[i][i];
		}
	}
	return;
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i <= m; ++ i) 	
		rd(a), rd(b), add(a, b), add(b, a), dg[a] ++, dg[b] ++;
	for (int u = 1; u < n; ++ u) {
		co[u][u] = -1;
		for (int i = head[u], v; ~i; i = edge[i].nxt)
			if ((v = edge[i].to) != n) co[u][v] = 1.0 / dg[v];
	}
	co[1][n] = -1, Gauss();
	for (int u = 1; u < n; ++ u)
		for (int i = head[u], v; ~i; i = edge[i].nxt)
			if (u < (v = edge[i].to))
				stk[++ top] = co[u][n] / co[u][u] / dg[u] + ((v == n) ? 0 : co[v][n] / co[v][v] / dg[v]);
	sort(stk + 1, stk + top + 1);
	for (int i = 1; i <= top; ++ i) res += stk[i] * (m - i + 1);
	return printf("%.3lf\n", res), 0;
}
