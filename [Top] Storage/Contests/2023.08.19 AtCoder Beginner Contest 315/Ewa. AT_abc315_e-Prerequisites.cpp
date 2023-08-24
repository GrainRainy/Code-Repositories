#include <bits/stdc++.h>
#define fi first
#define se second
#define DEBUG cerr << "-- DEBUG --\n";

namespace IO {
	#ifdef __LINUX__
	#define getchar() getchar_unlocked()
	#define putchar(a) putchar_unlocked(a)
	#endif
	
	#ifdef __WINDOWS__
	#define getchar() _getchar_nolock()
	#define putchar(a) _putchar_nolock()
	#endif
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar(); bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T, typename... Args> 
	void rd(T &x, Args&... args) { rd(x), rd(args...); }
	template <typename T> inline void ot(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
	template <typename T, typename ...Args>
	void output(T x, char ch = ' ', Args... args) {
		ot(x, ch); ot(args...);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

template<typename Typ1> void debug(Typ1 a) { cerr << a << '\n'; }
template<typename Typ1, typename ...Typ2> void debug(Typ1 a, Typ2 ...arg) {
	cerr << a << " ", debug(arg...);
}

const int N = 2e5 + 10;
int n;
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int dg[N];
bool st[N];
vector<int> v;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int father) {
	st[u] = true;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!st[j] and j != father) dfs(j, u);
	}
}

int main() {
	rd(n);
	memset(head, -1, sizeof head);
	for (int i = 1, c, p; i <= n; ++ i) {
		rd(c);
		for (int j = 1; j <= c; ++ j) 
			rd(p), add(i, p), add(p, i), dg[i] ++;
	}
	dfs(1, 0);
	queue<int> q;
	for (int i = 1; i <= n; ++ i) {
		if (!st[i]) continue;
		if (!dg[i]) q.push(i);
	}
	memset(st, 0, sizeof st);
	while (q.size()) {
		int u = q.front(); q.pop();
		ot(u, ' ');
		st[u] = true;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			dg[j] --;
			if (!st[j] and !dg[j]) {
				if (j == 1) return 0;
				q.push(j);
			}
		}
	}
	puts("");
	return 0;
}
