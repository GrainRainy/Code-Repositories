#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n'){
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
} 

const int N = 1e5 + 100;
int n, k, t;
int depth[N], father[N], id[N];
bool st[N];
int cnte, cntv;

bool cmp(int a, int b){
	return depth[a] > depth[b];
}

void solve(){
	cnte = cntv = 0;
	memset(depth, 0, sizeof depth);
	memset(st, 0, sizeof st);
	// init 
	input(n), input(k);
	id[1] = 1; // root based on 1 
	for (int i = 2; i <= n; i ++){
		input(father[i]);
		id[i] = i, depth[i] = depth[father[i]] + 1;
	}
	sort(id + 1, id + 1 + n, cmp);
	for (int i = 1; i <= n; ++ i){
		int cur = id[i], fa = father[id[i]];
		if (st[cur] or st[fa] or id[i] == 1) continue;
		cnte ++, cntv += 2;
		st[cur] = st[fa] = true;
		if (cntv >= k){ output(cnte); return; } 
	}
	
	for (int i = 1; i <= n; ++ i){
		int cur = id[i], fa = father[id[i]];
		if (st[cur]) continue;
		cnte ++, cntv ++;
		st[cur] = true;
		if (cntv >= k){ output(cnte); return; } 
	}
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
