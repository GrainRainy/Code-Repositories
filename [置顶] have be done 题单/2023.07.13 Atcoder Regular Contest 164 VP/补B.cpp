#include <bits/stdc++.h>
#define fi first
#define se second
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar(); 
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
	template <typename T, typename... Args> 
	void input(T &x, Args&... args) { input(x), input(args...); }
}

using namespace IO;
using namespace std;
using PII = pair<int, int>;
const int N = 2e5 + 10;
int n, m, col[N], fa[N];
vector<PII> edge;

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
	input(n, m);
	for (int i = 0, a, b; i < m; ++ i) input(a, b), edge.push_back({a, b});
	for (int i = 1; i <= n; ++ i) input(col[i]), fa[i] = i;
	for (auto t : edge) if (col[t.fi] != col[t.se]) fa[find(t.fi)] = find(t.se);
	for (auto t : edge) if (col[t.fi] == col[t.se] and find(t.fi) == find(t.se)) return puts("Yes"), 0;
	return puts("No"), 0;
}
