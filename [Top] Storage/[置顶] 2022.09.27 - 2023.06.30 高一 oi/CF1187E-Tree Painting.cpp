#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define max(a, b) ((a > b) ? (a) : (b))

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

const int N = 2e5 + 10;
LL n, ans;
vector<int> graph[N];
LL siz[N];
// graph
LL f[N], g[N];
// dp

inline void dfs(int u, int father){
	siz[u] = 1;
	for (int tmp : graph[u]){
		if (tmp == father) continue;
		dfs(tmp, u);
		f[u] += f[tmp];
		siz[u] += siz[tmp];
	}
	f[u] += siz[u];
}

inline void init(int u, int father){
	if (u != 1){
		g[u] = g[father] + n - 2 * siz[u];
		ans = max(ans, g[u]);
	}
	for (int tmp : graph[u]){
		if (tmp == father) continue;
		init(tmp, u);
	}
}

int main(){
	input(n);
	for (int i = 1; i < n; i ++){
		int u, v; input(u), input(v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	// input and add
	dfs(1, 0);
	ans = g[1] = f[1];
	init(1, 0);
	cout << ans << endl;
	
//	cerr << endl;
//	for (int i = 1; i <= n; i ++)
//		cerr << i << " " << f[i] << " " << g[i] << endl;
	return 0;
}
