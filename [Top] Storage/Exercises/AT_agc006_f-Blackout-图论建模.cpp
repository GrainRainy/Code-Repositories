#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << u << '\n';
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
const int N = 1e5 + 10;
int n, m;
int col[N], head[N], idx;
struct Node { int nxt, to, w; }edge[N << 1];
LL ans, cnt[6]; // true/false, cnt1, cnt2, cnt3, cntN, cntE 

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

inline int tar(int u) {
	return !u ? 3 : u == 4 ? 1 : u;
}

void dfs(int u, int color) {
	col[u] = color, cnt[col[u]] ++, cnt[4] ++;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		cnt[5] ++;
		if (!col[j]) dfs(j, tar(col[u] + edge[i].w));
		else if (col[j] != tar(col[u] + edge[i].w)) cnt[0] = 1;
	}
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i <= m; ++ i) 
		rd(a), rd(b), add(a, b ,1), add(b, a, -1);
	for (int i = 1; i <= n; ++ i) {
		if (col[i]) continue;
		memset(cnt, 0, sizeof cnt);
		dfs(i, 1);
		if (cnt[0]) { ans += cnt[4] * cnt[4]; continue; }
		cnt[5] >>= 1;
		if (!cnt[1] or !cnt[2] or !cnt[3]) ans += cnt[5];
		else ans += cnt[1] * cnt[2] + cnt[2] * cnt[3] + cnt[3] * cnt[1];
	}
	return cout << ans << '\n', 0;
}
