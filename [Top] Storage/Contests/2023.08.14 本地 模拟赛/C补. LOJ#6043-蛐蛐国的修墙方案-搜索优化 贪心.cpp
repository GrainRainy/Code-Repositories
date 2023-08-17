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
const int N = 1e2 + 10;
int n, tot, p[N]; char s[N];
vector<int> g[N]; bool st[N];

void check() {
	for (int i = 1, t = 0; i <= n; ++ i)
		if ((t += s[i] == '(' ? 1 : -1) < 0) return;
	puts(s + 1); exit(0);
}

void dfs(int pos) {
	if (pos > tot) return check();
	if (g[pos].size() == 2) return s[g[pos][0]] = '(', s[g[pos][1]] = ')', dfs(pos + 1);
	for (int i = 0; i < g[pos].size(); ++ i) s[g[pos][i]] = i & 1 ? '(' : ')'; dfs(pos + 1);
	for (int i = 0; i < g[pos].size(); ++ i) s[g[pos][i]] = i & 1 ? ')' : '('; dfs(pos + 1);
}

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) rd(p[i]);
	for (int i = 1, t; i <= n; ++ i)
		if (!st[t = i]) {
			++ tot;
			while (!st[t]) st[t] = true, g[tot].push_back(t), t = p[t];
		}
	return dfs(1), 0;
}
