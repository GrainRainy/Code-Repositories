#include <iostream>
#include <cstring>
#include <algorithm>

#define __DEBUG__ puts("__DEBUG__");

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int NP = 5e3 + 10;
const int NC = 5e4 + 10;
const int M = 1e5 + 10;
int np, nc, m, tmp, tc, st, ed;
struct Node {
	int u, v, w;
	bool operator < (const Node &t) const { return w < t.w; }
}edge[M];
int fa[NC], siz[NC];
// dsu 
int id[NC], pro[NC], cost[NP];
int ansl, ansr, nw;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	if (x == y) return;
	if (siz[x] > siz[y]) fa[y] = x, siz[x] += siz[y];
	else fa[x] = y, siz[y] += siz[x];
}

void DsuClear() {
	for (int i = 1; i <= nc; i ++) fa[i] = i, siz[i] = 1;
	return;
}

int main() {
	input(np), input(m);
	for (int i = 1; i <= m; ++ i) 
		input(edge[i].u), input(edge[i].v), input(edge[i].w);
	for (int i = 1; i <= np; ++ i) {
        input(tmp), nc += tmp;
        while (tmp --) input(tc), pro[tc] = i;
    }
    for (int i = 1; i <= np; ++ i) input(cost[i]);
    input(st), input(ed);

    for (int i = 1; i <= m; ++ i) 
        edge[i].w *= cost[pro[edge[i].u]] + cost[pro[edge[i].v]];
    sort(edge + 1, edge + 1 + m);
    DsuClear();
    for (ansl = edge[m].w / 200, nw = m; find(st) != find(ed); ansl --)
        while (nw and edge[nw].w >= ansl * 200) merge(find(edge[nw].u), find(edge[nw].v)), -- nw;
	DsuClear();
    for (ansr = ++ ansl; find(st) != find(ed); ansr ++)
        while (nw < m and edge[nw + 1].w <= ansr * 200) ++ nw, merge(find(edge[nw].u), find(edge[nw].v));
    printf("%d %d\n", ansl, ansr - 1);
    return 0;
}

