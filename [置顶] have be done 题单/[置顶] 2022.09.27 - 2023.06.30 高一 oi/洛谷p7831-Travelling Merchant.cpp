#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

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
	static short st[10], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 2e5 + 10;
int n, m;
int ans[N], oudg[N];
struct Edge{
	int from, to, r, p;
	
	bool operator < (const Edge &t) const{
		return r > t.r; // sort from big to small 
	}
}nums[N];
// vertex attribute 
bool st[N];
int head[N], idx;
struct Node{
	int nxt, to;
}edge[N];
queue<int> q;
// edge attribute

inline void add(const int &a, const int &b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

int main(){
	memset(ans, 0x3f, sizeof ans);
	memset(head, -1, sizeof head);
	// init 
	input(n), input(m);
	for (int i = 1; i <= m; i ++){
		input(nums[i].from), input(nums[i].to);
		input(nums[i].r), input(nums[i].p);
		oudg[nums[i].from] ++;
	}
	// input part 
	sort (nums + 1, nums + 1 + m);
	for(int i = 1; i <= m; ++ i) add(nums[i].to, i);
	for (int i = 1; i <= n; ++ i){
		if (!oudg[i]) q.push(i);
	}
	for (int i = 1; i <= m; ++ i){
		while (q.size()){
			auto u = q.front(); q.pop();
			for (int j = head[u]; ~j; j = edge[j].nxt){
				int t = edge[j].to; if (st[t]) continue;
				st[t] = true, oudg[nums[t].from] --;
				if (!oudg[nums[t].from]) q.push(nums[t].from);
				if (ans[u] != 0x3f3f3f3f){
					ans[nums[t].from] = min(ans[nums[t].from], max(nums[t].r, ans[u] - nums[t].p)); 
				}
			}
		}
		if (!st[i]){
			st[i] = true; oudg[nums[i].from] --;
			if (!oudg[nums[i].from]) q.push(nums[i].from);
			ans[nums[i].from] = min(ans[nums[i].from], nums[i].r);
		}
	}
	
	for (int i = 1; i <= n; i ++){
		if (ans[i] == 0x3f3f3f3f) output(-1);
		else output(ans[i]);
	}
	puts("");
	return 0;
}
