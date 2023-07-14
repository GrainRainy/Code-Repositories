#include <bits/stdc++.h>

#define enter putchar('\n')
#define FI first
#define SE second

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar(); bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T, typename... Args> 
	void input(T &x, Args&... args) {
		input(x), input(args...);
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

const int N = 2e3 + 10;
int n;
int px[N], py[N];
double d, dist[N][N];
bool st[N], bt[N];

double get(int i, int j) {
	double tmpd = (double)(px[i] - px[j]) * (px[i] - px[j]) + (double)(py[i] - py[j]) * (py[i] - py[j]);
	return sqrt(tmpd);
}

void dfs(int u) {
	for (int i = 1; i <= n; ++ i) {
		if (i == u) continue;
		if (st[i]) continue;
		if (dist[u][i] <= d) st[i] = true, dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) cin >> px[i] >> py[i];
	
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j) 
			dist[i][j] = get(i, j);
		
	dfs(1);
	st[1] = true;
	
	for (int i = 1; i <= n; ++ i)
		if (st[i]) puts("Yes");
		else puts("No");
	return 0;
}
