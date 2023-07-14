#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define fi first
#define se second
#define max(a, b) ((a > b) ? (a) : (b))

using namespace std;
using LL = long long;
using PII = pair<int, int>;

template<typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 2e4 + 100;
int n;
int gap, cnt, maxn = -1;
int dist[N], p[N];
vector<PII> g[N]; // dots and w 

void dfs(int u, int father){
	for (auto t : g[u]){
		if (t.fi == father) continue;
		p[t.fi] = t.se;
		dfs(t.fi, u);
		dist[u] = max(dist[u], dist[t.fi] + t.se);
	}
	if (dist[u] + p[u] >= gap){
		cnt ++;
		dist[u] = 0;
	}
}

int main(){
	input(n);
	int tmp;
	for (int i = 1; i <= n; i ++){
		input(tmp);
		for (int j = 1; j <= tmp; j ++){
			int to, w; input(to), input(w);
			g[i].push_back({to, w});
			maxn = max(maxn, w);
		}
	}
	input(gap);
	// input
	if (maxn >= gap) return puts("No solution."), 0;
	// special judgement
	dfs(1, 0);
	cout << cnt << endl;
	return 0;
}
