#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}
using IO::rd;
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
int n, head[N], idx, cnt, faw[N];
struct Node { int nxt, to, w; }edge[N << 1];
struct Data {
	LL val; int cnt;
}up[N], dn[N], lf[N], rt[N], ans; 
int stk[N], top;

inline void upd(Data &a, const Data &t) {
	if (t.val > a.val) a = t;
	else if (t.val == a.val) a.cnt += t.cnt;
}
inline void check(const Data &t) { cnt += (t.cnt == ans.cnt and t.val == ans.val); }

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

void init(int u, int fa) {
	dn[u] = {0, 1};
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		init(j, u);
		faw[j] = edge[i].w;
		upd(ans, (Data){dn[u].val + dn[j].val + edge[i].w, dn[u].cnt * dn[j].cnt});
		upd(dn[u], (Data){dn[j].val + edge[i].w, dn[j].cnt});
	}
}

void dp(int u, int fa) {
	if (!fa) up[u] = {0, 1};
	else {
		upd(up[u], (Data){up[fa].val + faw[u], up[fa].cnt});
		upd(up[u], (Data){lf[u].val + faw[u], lf[u].cnt});
		upd(up[u], (Data){rt[u].val + faw[u], rt[u].cnt});
		check((Data){up[u].val + dn[u].val, up[u].cnt * dn[u].cnt});
	}
	Data tmp = {0, 0}; top = 0;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		stk[++ top] = j;
		lf[j] = tmp;
		upd(tmp, (Data){dn[j].val + edge[i].w, dn[j].cnt});
	}
	tmp = {0, 0};
	for (int i = top; i; -- i) {
		rt[stk[i]] = tmp;
		upd(tmp, (Data){dn[stk[i]].val + faw[stk[i]], dn[stk[i]].cnt});
	}
	for (int i = head[u]; ~i; i = edge[i].nxt) 
		if (edge[i].to != fa) dp(edge[i].to, u);
}

int main() {
	rd(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b, c; i < n; ++ i) 
		rd(a), rd(b), rd(c), add(a, b, c), add(b, a, c);
	init(1, 0), dp(1, 0);
	return cout << ans.val << '\n' << cnt << '\n', 0;
}
