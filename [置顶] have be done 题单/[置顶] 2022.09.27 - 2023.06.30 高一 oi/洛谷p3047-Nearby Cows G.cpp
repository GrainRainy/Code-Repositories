#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template <typename T> inline void input (T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n'){
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
const int K = 25;
int n, k, ans;
int w[N];
int head[N], idx;
struct Node{
	int nxt, to;
}edge[N << 1];
// graph
bool st[N];
int son[N][K], sum[N][K];
// dp 

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

void init(int u, int father){
	for (int i = 0; i <= k; ++ i) son[u][i] = w[u];
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		if (j == father) continue;
		init(j, u);
		for (int m = 1; m <= k; ++ m){
			son[u][m] += son[j][m - 1];
		}
	}
}

void dfs(int u, int father){
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		if (j == father) continue;
		sum[j][1] += son[u][0];
		for (int m = 2; m <= k; ++ m){
			sum[j][m] += sum[u][m - 1] - son[j][m - 2];
		}
		
		dfs(j, u);
	}
}

int main(){
	memset(head, -1, sizeof head);
	// init graph 
	input(n); input(k);
	int tmpa, tmpb;
	for (int i = 1; i <= n - 1; ++ i){
		input(tmpa), input(tmpb);
		add(tmpa, tmpb), add(tmpb, tmpa);
	}
	for (int i = 1; i <= n; i ++) input(w[i]);
	// input
	
	init(1, 0);
	for (int i = 1; i <= n; ++ i)
		for (int j = 0; j <= k; ++ j)
			sum[i][j] = son[i][j];
	dfs(1, 0);
	
	for (int i = 1; i <= n; i ++){
		output(sum[i][k]);
	}
	return 0;
} 
