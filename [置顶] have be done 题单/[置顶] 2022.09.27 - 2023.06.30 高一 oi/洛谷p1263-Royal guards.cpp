#include <iostream>
#include <cstring>
#include <algorithm>

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

template <typename T> inline void output(T x, char ed = ' '){
	if (x < 0) putchar('-'), x = -x;
	static short st[64], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 200 + 10;

int m, n;
int graph[N][N];
int idl[N][N], idr[N][N];
int n1, n2;
// basic thingss
int head[N * N], idx;
struct node{
	int nxt, to;
}edge[N * N];
// graph
int cnt;
bool st[N * N];
int match[N * N];

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

void init(){
	for (int j = 0; j <= m + 1; j ++)
		graph[0][j] = 2;
	for (int i = 0; i <= n + 1; i ++)
		graph[i][0] = 2;
	
	for (int i = 1; i <= n; i ++){ // x 
		for (int j = 1; j <= m; j ++){
			if (graph[i][j] != 2){
				if (graph[i][j - 1] == 2) idl[i][j] = ++ n1;
				else idl[i][j] = idl[i][j - 1];
			}
		}
	}
	
	for (int j = 1; j <= m; j ++){ // y 
		for (int i = 1; i <= n; i ++){
			if (graph[i][j] != 2){
				if (graph[i - 1][j] == 2) idr[i][j] = ++ n2;
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
	memset(head, -1, sizeof head);
	
	input(n), input(m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			input(graph[i][j]);
	// input
	
	init();
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (!graph[i][j]) add(idl[i][j], idr[i][j]);
	
	for (int i = 1; i <= n1; i ++){
		memset(st, 0, sizeof st);
		cnt += find(i);
	}
	
	output(cnt, '\n');
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (!graph[i][j] and idl[i][j] == match[idr[i][j]])
				output(i), output(j, '\n');
	
	return 0;
}
