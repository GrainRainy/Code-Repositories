#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 50 + 10;
int n, m;
char graph[N][N];
// basic things
int head[N * N], idx;
struct node{
	int nxt, to;
}edge[N * N];
// graph
int n1, n2;
int idl[N][N], idr[N][N];
bool st[N];
int match[N];

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

inline void init(){
	for (int j = 1; j <= m; j ++)
		graph[0][j] = '#';
	for (int i = 1; i <= n; i ++)
		graph[i][0] = '#';
	// basic init
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= m; j ++){
			if (graph[i][j] != '#'){
				if (graph[i][j - 1] == '#') idl[i][j] = ++ n1;
				else idl[i][j] = idl[i][j - 1];
			}
		}
	}
	for (int j = 1; j <= m; j ++){
		for (int i = 1; i <= n; i ++){
			if (graph[i][j] != '#'){
				if (graph[i - 1][j] == '#') idr[i][j] = ++ n2;
				else idr[i][j] = idr[i - 1][j];
			}
		}
	}
}

bool find(int u){
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		if (st[j]) continue;
		st[j] = true;
		if (!match[j] or find(match[j])){
			match[j] = u;
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			cin >> graph[i][j];
	// input
	init();
	// init graph
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (graph[i][j] != '#' and )
	// build graph
	
	for (int i = 1; i <= n1; i ++){
		if ()
	}
}
