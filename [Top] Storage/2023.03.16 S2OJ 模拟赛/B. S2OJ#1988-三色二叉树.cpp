#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define max(a, b) ((a > b) ? (a) : (b))

using namespace std;

const int N = 5e5 + 100;
string s;
int dots = 1, p = 0; // point to tree and string
// init strings
int head[N], idx;
struct node{
	int nxt, to;
}edge[N << 1];
// graph
int outdg[N];
int f[N][2], g[N][2]; // min and max, green or not
// max situation is successful !
// but how to get minium dots (?). i can't do that /kel

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

inline void init(int a, int b){
	if (s[b] == '0') return;
	if (s[b] == '1'){
		outdg[a] = 1;
		add(a, a + 1);
		init(a + 1, b + 1);
	}
	if (s[b] == '2'){
		outdg[a] = 2;
		add(a, a + 1);
		init(a + 1, b + 1);
		add(a, a + 2);
		init(a + 2, b + 1);
	}
}

inline void dp(int u){
	if (!outdg[u]){
		g[u][1] = 1;
		g[u][0] = 0;
		return;
	}
	if (outdg[u] == 1){
		int a = edge[head[u]].to;
		dp(a);
		g[u][1] = max(g[a][0] + 1, g[u][1]);
		g[u][0] = max(max(g[a][0], g[a][1]), g[u][0]);
		return;
	}
	else{
		int a[2] = {0, 0};
		for (int i = head[u]; ~i; i = edge[i].nxt)
			a[(a[0] ? 1 : 0)] = edge[i].to;
//		cerr << a[0] << " " << a[1] << endl;
		// get son
		dp(a[0]), dp(a[1]);
		
		g[u][0] = max(max(g[u][0], g[a[0]][1] + g[a[1]][0]), g[a[0]][0] + g[a[1]][1]);
		g[u][1] = max(g[u][1], g[a[0]][0] + g[a[1]][0] + 1);
		return;
	}
	
}

inline int dfs(){
	int temp = 0;
	queue<int> q; q.push(1);
	
	while (q.size()){
		auto t = q.front(); q.pop();
		
		for (int i = head[t]; ~i; i = edge[i].nxt){
			int j = edge[i].to;
			if (outdg[t] == outdg[j] and outdg[t] == 2) temp ++;
		}
	}
	return temp;
}

inline int minium(){
	int cnt = 0;
	for (int i = 0; i < s.size(); i ++){
		if (s[i] == '2') cnt ++;
	}
	return cnt - dfs();
}

int main(){
	memset(head, -1, sizeof head);
	memset(f, 0x3f, sizeof f);
	// init graph
	cin >> s;
	init(dots, p);
	dp(1);
	
	cout << max(g[1][0], g[1][1]) << " " << minium() << endl;
	// just guess that minium situation qwq
	
	return 0;
}
