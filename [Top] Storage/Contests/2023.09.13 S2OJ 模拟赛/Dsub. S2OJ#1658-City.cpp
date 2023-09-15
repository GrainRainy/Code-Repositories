#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		while (!isdigit(c)) c = getchar();
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
	template <typename T> inline void ot(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
const int N = 5e5 + 10;
int n, m, x, q;

namespace sub1 {
	void solve() {
		if (m < n) return ot(-1);
		for (int i = 1; i <= n; ++ i)
			ot(i, ' '), ot(i + 1 == n + 1 ? 1 : i + 1);
		m -= n;
		for (int i = 1; i <= n and m; ++ i) {
			for (int j = i + 2, cnt = 1; cnt <= n - 2 and m; ++ j, ++ cnt) {
				if (j == n + 1) j = 1;
				ot(i, ' '), ot(j), m --;
			}
		}
	}
}

namespace sub2 {
	void solve() {
		if (q) return ot(-1);
		if (m > ((long long)n * n - n) >> 1) return ot(-1);
		for (int i = 1; i < n and m; ++ i)
			for (int j = i + 1; j <= n and m; ++ j)
				ot(i, ' '), ot(j), m --;
	}
}

namespace sub3 {
	/* bug maybe */
	int fa[N], idx;
	vector<int> dot[N];
	struct Edge { int a,b; }e[N];
	int stk[N], top;
	int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
	
	void print() {
		for (int i = 1; i <= m; ++ i)
			ot(e[i].a, ' '), ot(e[i].b, '\n');
		return;
	}
	
	void solve() {
		iota(fa + 1, fa + n + 1, 1);
		for (int i = 1, a, b; i <= q; ++ i)
			rd(a), rd(b), fa[find(a)] = b;
		for (int i = 1; i <= n; ++ i) {
			dot[find(i)].push_back(i);
			if (find(i) == i) x --;
		}
		if (x < 0) return ot(-1);
		if (x) for (int i = 2; i <= n and x; ++ i) 
			if (dot[i].size() > 1) {
				for (auto t : dot[i]) dot[1].push_back(t);
				dot[i].clear(), x --;
			}
		for (int i = 1; i <= n; ++ i) if (dot[i].size()) stk[++ top] = i;
		for (int i = 1; i <= top; ++ i) {
			for (int j = 0; j < dot[stk[i]].size() - 1; ++ j)
				e[++ idx] = {dot[stk[i]][j], dot[stk[i]][j + 1]};
			e[++ idx] = {dot[stk[i]][dot[stk[i]].size() - 1], dot[stk[i]][0]};
		}
		if (idx > m) return ot(-1);
		for (int i = 1; i <= top and idx < m; ++ i) {
			for (int j = 0; j < dot[stk[i]].size() and idx < m; ++ j) {
				for (int k = j + 2, cnt = 1; k < dot[stk[i]].size() and idx < m and cnt <= dot[stk[i]].size() - 2; ++ k, cnt ++) {
					if (k == dot[stk[i]].size() + 1) k = 0;
					e[++ idx] = {dot[stk[i]][j], dot[stk[i]][k]};
				}
			}
		}
		for (int i = 1; i < top and idx < m; ++ i)
			for (int j = i + 1; j <= top and idx < m; ++ j) 
				for (auto a : dot[stk[i]])
					for (auto b : dot[stk[j]])
						e[++ idx] = {a, b};
		print();
	}
}

int main() {
	rd(n), rd(m), rd(x), rd(q);
	if (x == 1) return sub1::solve(), 0;
	if (x == n) return sub2::solve(), 0;
	return sub3::solve(), 0;
}
