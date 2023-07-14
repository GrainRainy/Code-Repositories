#include <iostream>
#include <cstring>
#include <algorithm>

#define min(a, b) ((a) < (b) ? (a) : (b))

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
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 2e5 + 10;
int n;
int head[N], idx;
struct Node{
	int nxt, to, w;
}edge[N << 1];
// graph
bool st[N];
int indg[N];
int cson[N], croot[N];
// calculate son discharge 
// calculate discharge when become root 

inline void add(int a, int b, int c){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	edge[idx].w = c;
	head[a] = idx;
}

void dp(int u){
	st[u] = true; cson[u] = 0;
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int to = edge[i].to, w = edge[i].w;
		if (st[to]) continue;
		dp(to);
		if (indg[to] != 1) cson[u] += min(cson[to], w);
		else cson[u] += w;
	}
}

void dfs(int u){
	st[u] = true;
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int to = edge[i].to, w = edge[i].w;
		if (st[to]) continue;
		if (indg[u] == 1) croot[to] = cson[to] + w;
		else if (indg[to] == 1) croot[to] = cson[to] + min(croot[u] - w, w);
		else croot[to] = cson[to] + min(croot[u] - min(cson[to], w), w);
		dfs(to);
	}
}

inline void solve(){
	idx = 0;
	memset(head, -1, sizeof head);
	memset(st, 0, sizeof st);
	memset(indg, 0, sizeof indg);
	// init 
	
	input(n);
	int a, b, c;
	for (int i = 1; i <= n - 1; i ++){
		input(a), input(b), input(c);
		add(a, b, c), add(b, a, c);
		indg[a] ++, indg[b] ++;
	}
	// input 
	dp(1);
	memset(st, 0, sizeof st);
	croot[1] = cson[1];
	dfs(1);
	// dp and change root 
	
	int ans = 0;
	for (int i = 1; i <= n; i ++)
		ans = max(ans, croot[i]);
	
//	for (int i = 1; i <= n; i ++)
//		cerr << cson[i] << " ";
//	cerr << endl;
	
	return output(ans), void();
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
