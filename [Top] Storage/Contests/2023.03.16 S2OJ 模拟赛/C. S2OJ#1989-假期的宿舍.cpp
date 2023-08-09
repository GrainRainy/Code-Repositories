#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1000;
int n;
bool type[N], go[N];
// basic things
int head[N << 1], idx;
struct node{
	int nxt, to;
}edge[N * N];
// graph
int match[N << 1];
bool st[N << 1];

inline void add(int a, int b){
	edge[++ idx].to = b;
	edge[idx].nxt = head[a];
	head[a] = idx;
}

inline bool find(int u){
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int t = edge[i].to;
		if (st[t]) continue;
		st[t] = true;
		
		if (!match[t] or find(match[t])){
			match[t] = u;
			return true;
		}
	}
	return false;
}

inline void solve(){
	int ans = 0;
	memset(match, 0, sizeof match);
	memset(head, -1, sizeof head), idx = 0;
	memset(edge, 0, sizeof edge);
	// init 
	input(n);
	int need = n;
	for (int i = 1; i <= n; i ++)
		input(type[i]);
	for (int i = 1; i <= n; i ++){
		input(go[i]);
		if (type[i] and go[i]) need --;
	}
//	cout << need << endl;
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++){
			bool tmp; input(tmp);
			if ((type[i] and go[i]) or !type[j]) continue;
			if (tmp or i == j){
				add(i, j + n);
			}	
		}
	// 连边，注意 ＋ｎ 的是床 
	// input 
	for (int i = 1; i <= n; i ++){
		memset(st, 0, sizeof st);
		if (find(i)) ans ++;
	}

	if (ans == need) puts("^_^");
	else puts("T_T");
	return;
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
