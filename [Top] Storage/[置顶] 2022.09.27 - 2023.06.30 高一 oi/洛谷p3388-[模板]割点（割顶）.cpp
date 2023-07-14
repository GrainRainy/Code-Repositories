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
template <typename T, typename... Args>
void input(T &x, Args&... args){
	input(x), input(args...);
}

template <typename T> inline void output(T x, char ed = '\n'){
	if (x < 0) putchar('-'), x = -x;
	static short st[64], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 2e4 + 100;
const int M = 1e5 + 100;
int n, m;
// basis
int head[N], idx;
struct node{
	int to, nxt;
}edge[M << 1];
// graph
int timestamp, root, ans;
int stk[N], top;
int dfn[N], low[N];
bool cut[N];

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

inline void tarjan(int u){
	dfn[u] = low[u] = ++ timestamp;
	stk[++ top] = u;
	
	int cnt = 0;
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		if (!dfn[j]){
			tarjan(j);
			low[u] = min(low[u], low[j]);
			if (low[j] >= dfn[u]){
				++ cnt;
				if (u != root or cnt > 1) cut[u] = true;
			}
		}
		else low[u] = min(low[u], dfn[j]);
	}
}

int main(){
	memset(head, -1, sizeof head);
	// init
	
	input(n), input(m);
	for (int i = 1; i <= m; i ++){
		int a, b; input(a), input(b);
		add(a, b), add(b, a);
	}
	// input and add
	for (int i = 1; i <= n; i ++)
		if (!dfn[i]) root = i, tarjan(i);
	// tarjan
	
	for (int i = 1; i <= n; i ++)
		if (cut[i]) ans ++;
	output(ans);
	for (int i = 1; i <= n; i ++)
		if (cut[i]) output(i, ' ');
	return 0;
}
