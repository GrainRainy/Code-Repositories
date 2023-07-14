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

template <typename T> inline void output(T x, char ed = '\n') {
    if (x < 0) putchar('-'), x = -x;
    static short st[20], top;
    do st[ ++ top] = x % 10, x /= 10; while (x);
    while (top) putchar(st[top -- ] | '0');
    putchar(ed);
}

const int N = 3e5 + 10;
int n, m, c[N], f[N];
bool a[N];
LL h[N], v[N];
// basis 
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N];
// graph 
int lson[N], rson[N], dep[N], dis[N], tth[N]; // tree to heap 
LL val[N], adt[N], mlt[N]; // add tag, multiplication tag 
// leftist tree
int ansCity[N], ansPer[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

inline void pushAdd(int u, LL x) {
	val[u] += x, adt[u] += x;
}

inline void pushMul(int u, LL x) {
	val[u] *= x, adt[u] *= x, mlt[u] *= x; 
}

void pushDown(int u) {
	pushMul(lson[u], mlt[u]);
	pushMul(rson[u], mlt[u]);
	pushAdd(lson[u], adt[u]);
	pushAdd(rson[u], adt[u]);
	adt[u] = 0, mlt[u] = 1;
}

int merge(int a, int b) {
	if (!b or !a) return a | b;
	if (val[a] > val[b]) swap(a, b);
	pushDown(a);
	rson[a] = merge(rson[a], b);
	if (dis[rson[a]] > dis[lson[a]]) swap(lson[a], rson[a]);
	dis[a] = dis[rson[a]] + 1;
	return a;
}

int pop(int u) { // return new root 
	pushDown(u);
	return merge(lson[u], rson[u]);
}

void dfs(int u) {
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		dep[j] = dep[u] + 1;
		dfs(j);
	}
	
    while (tth[u] and val[tth[u]] < h[u]) {
        ansCity[u] ++;
        ansPer[tth[u]] = dep[c[tth[u]]] - dep[u];
        tth[u] = pop(tth[u]);
    }
    // deal death 
    a[u] ? pushMul(tth[u], v[u]) : pushAdd(tth[u], v[u]);
    if (u > 1) tth[f[u]] = merge(tth[u], tth[f[u]]);
    else while (tth[u]) {
        ansPer[tth[u]] = dep[c[tth[u]]] + 1;
        tth[u] = pop(tth[u]);
    } // all alive 
    return;
}

int main() {
	memset(head, -1, sizeof head);
	dis[0] = -1;
	input(n), input(m);
    for (int i = 1; i <= n; ++ i) input(h[i]), mlt[i] = 1;
    for (int i = 2; i <= n; ++ i) {
        input(f[i]); add(f[i], i);
        input(a[i]), input(v[i]);
    }
    for (int i = 1; i <= m; ++ i) {
        input(val[i]), input(c[i]);
        tth[c[i]] = merge(i, tth[c[i]]);
    }
    
    dfs(1);

    for (int i = 1; i <= n; ++ i) output(ansCity[i]);
    for (int i = 1; i <= m; ++ i) output(ansPer[i]);
    return 0;
}
