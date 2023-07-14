#include <bits/stdc++.h>
#define DEBUG puts("__DEBUG__");
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
const int N = 1e5 + 10;
int n, res[N];
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
bool judge;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int fa, int l) {
	multiset<int> st;
	if (!judge) return;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		dfs(j, u, l);
		st.insert(res[j] + 1);
	}
	res[u] = 0;
	if ((u == 1 and st.size() & 1) or u != 1 and !(st.size() & 1)) st.insert(0);
	while (st.size()) {
		auto sl = st.begin();
//		int tmp = *sl;
		st.erase(sl);
		auto sr = st.lower_bound(l - *sl);
		if (sr == st.end()) {
			if (u == 1) return judge = false, void();
			else if (res[u]) return judge = false, void();
			else res[u] = *sl;
		} else st.erase(sr);
	}
}

inline bool check(int mid) {
	judge = true;
	dfs(1, 0, mid);
	return judge;
}

int main() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 5));
	for (int i = 1, u, v; i < n; ++ i) {
		input(u), input(v);
		add(u, v), add(v, u);
	}
	int l = 0, r = n;
	while (l < r) {
		int mid = l + r + 1>> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
}
