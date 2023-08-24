#include <iostream>
#include <cstring>
#include <algorithm>

#define min(a, b) ((a > b) ? (b) : (a))

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

const int N = 2e3 + 10;
int n, k;
int tmpa, tmpb, tmpc;
int head[N], idx;
struct Node{
	int nxt, to, w;
}edge[N << 1];
// graph
int siz[N];
LL dp[N][N];

inline void add(int a, int b, int c){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	edge[idx].w = c;
	head[a] = idx;
}

void dfs(int u, int father){
	siz[u] = 1, dp[u][0] = dp[u][1] = 0;
	
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to, w = edge[i].w;
		if (j == father) continue;
		dfs(j, u);
		siz[u] += siz[j]; // update 
		for (int m = min(siz[u], k); m >= 0; -- m){
			for (int v = 0; v <= min(siz[j], m); ++ v){
				if (dp[u][m - v] == -1) continue;
				LL cnt = 1ll * v * (k - v) + (LL)(siz[j] - v) * (LL)(n - siz[j] - k + v);
				dp[u][m] = max(dp[u][m], dp[j][v] + dp[u][m - v] + cnt * w);
			}
		}
	}
}

int main(){
	memset(dp, -1, sizeof dp);
	memset(head, -1, sizeof head);
	
	input(n), input(k);
	for (int i = 1; i <= n - 1; ++ i){
		input(tmpa), input(tmpb), input(tmpc);
		add(tmpa, tmpb, tmpc), add(tmpb, tmpa, tmpc);
	}
	// input 
	dfs(1, 0);
	cout << dp[1][k] << '\n';
	return 0;
}
