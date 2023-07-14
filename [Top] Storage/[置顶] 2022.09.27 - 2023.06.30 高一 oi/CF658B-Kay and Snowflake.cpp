#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (;!isdigit(c); c = getchar())
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

const int N = 3e5 + 100;

int n, q, tmp;
int father[N], siz[N], mx[N], core[N];
// basic things
int head[N], idx;
struct Node{
	int nxt, to;
}edge[N];

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

void dfs(int root){
	siz[root] = 1;
	for (int i = head[root]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		dfs(j);
		siz[root] += siz[j];
		mx[root] = max(mx[root], siz[j]);
	}
	
	int id = root, mn = mx[root];
	for (int i = head[root]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		int step = core[j], val = max(mx[step], siz[root] - siz[step]);
		int pos = step;
		while (father[step] != root){
			step = father[step];
			int nw = max(mx[step], siz[root] - siz[step]);
			if (nw < val){ // update
				val = nw;
				pos = step;	
			}
			else break;
		}
		if (mn > val){
			mn = val;
			id = pos;
		}
	}
	core[root] = id;
}

inline void query(int x){
	output(core[x]);
}

int main(){
	memset(head, -1, sizeof head);
	input(n), input(q);
	
	for (int i = 2; i <= n; i ++){
		input(father[i]);
		add(father[i], i);
	}
	// input
	dfs(1);
	
//	for (int i = 1; i <= n; i ++){
//		cout << i << " --> ";
//		for (int j = head[i]; ~j; j = edge[j].nxt)
//			cout << edge[j].to << " ";
//		cout << endl;
//	}
	
	while (q --) input(tmp), query(tmp);
	return 0;
}
