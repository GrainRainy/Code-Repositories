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

const int N = 100 + 10;
const int M = N * N;

int m, n;
int h[N], idx;
struct node{
	int to, nxt;
}edge[M];
// graph

int ans = 0;
int match[N];
bool st[N];
// match

inline void add(int a, int b){
	edge[++ idx].to = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

inline bool find(int cur){
	for (int i = h[cur]; ~i; i = edge[i].nxt){
		int t = edge[i].to;
		if (!st[t]){
			st[t] = true;
			if (!match[t] or find(match[t])){
				match[t] = cur;
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	memset(h, -1, sizeof h);
	input(m), input(n);
	int tmpa, tmpb;
	while (input(tmpa), input(tmpb), ~tmpa and ~tmpb)
		add(tmpa, tmpb), add(tmpb, tmpa);
	// input
	
	for (int i = 1; i <= m; i ++){
		memset(st, 0, sizeof st);
		if (find(i)) ans ++; 
	}
	
	cout << ans << endl;
	for (int i = m + 1; i <= n; i ++)
		if (match[i]) cout << i << " " << match[i] << endl;
	return 0;
}
