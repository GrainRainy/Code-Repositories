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

const int N = 510 << 1;
const int M = 5e4 + 100;
int n, m, e;
// basic things
int h[N], idx;
struct node{
	int to, nxt; 
}edge[M << 1];
// graph
int ans;
int match[N];
bool st[N];

inline void add(int a, int b){
	edge[++ idx].to = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

inline bool find(int u){
	for (int i = h[u]; ~i; i = edge[i].nxt){
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

int main(){
	memset(h, -1, sizeof h);
	// init 
	input(n), input(m), input(e);
	int tmpa, tmpb;
	for (int i = 1; i <= e; i ++){
		input(tmpa), input(tmpb);
		add(tmpa, tmpb + n), add(tmpb + n, tmpa);
	}
	// input
	for (int i = 1; i <= n; i ++){
		memset(st, 0, sizeof st);
		if (find(i)) ans ++;
	}
		
	cout << ans << endl;
	return 0;
}
