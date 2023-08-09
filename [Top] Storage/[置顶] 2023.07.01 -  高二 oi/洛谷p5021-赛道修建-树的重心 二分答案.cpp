#include <bits/stdc++.h>
#define DEBUG puts("--DEBUG--");
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std;
const int N = 5e4 + 10;
int n, m;
int head[N], idx;
struct Node { int nxt, to, w; }edge[N << 1];
int l, r, mid, mxd[N];
int res[N], cnt;

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

void dfs(int u, int fa) {
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		dfs(j, u);
		r = max(r, mxd[u] + edge[i].w + mxd[j]);
		mxd[u] = max(mxd[u], mxd[j] + edge[i].w);
	}
}

void calc(int u, int fa) {
	multiset<int> st;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		calc(j, u);
		st.insert(res[j] + edge[i].w);
	}
	if (cnt >= m) return;
	if (st.size()) {
		auto sl = st.lower_bound(mid);
		while (sl != st.end()) {
			st.erase(sl);
			cnt ++;
			sl = st.lower_bound(mid);
		}
	}
	while (st.size()) {
		auto sl = st.begin();
		int tmp = *sl;
		st.erase(sl);
		auto sr = st.lower_bound(mid - tmp);
		if (sr == st.end()) res[u] = max(res[u], tmp);
		else cnt ++, st.erase(sr);
	}
}

bool check() {
	cnt = 0;
	memset(res, 0, sizeof(int) * (n + 10));
	calc(1, 0);
	return cnt >= m;
}

int main() {
//	#ifdef ONLINE_JUDGE
//		freopen("track.in", "r", stdin);
//		freopen("track.out", "w", stdout);
//	#endif
	
	input(n), input(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b, l; i < n; ++ i) {
		input(a), input(b), input(l);
		add(a, b, l), add(b, a, l);
	} 
	dfs(1, 0);
	while (l < r) {
		mid = l + r + 1 >> 1;
		if (check()) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}
