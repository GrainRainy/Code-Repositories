#include <iostream>
using namespace std;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; c < '0' or c > '9'; c = getchar())
		f |= (c == '-');
	for (; c >= '0' and c <= '9'; c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T> inline void output(T x, char ed = '\n'){
	static short st[12], top;
	do st[++ top] =x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int n, k, idx, ans, i;
int a[100010], head[100010], nxt[100010], to[100010];

inline void add(int a, int b){
	nxt[++ idx] = head[a], to[idx] = b, head[a] = idx;
}

int dfs(int u, int step){
	int res = step;
	for (int i = head[u]; i; i = nxt[i])
		res = max(res, dfs(to[i], step + 1));
	if (a[u] != 1 and res - step == k - 1) return ans ++, 0;
	return res;
}

int main(){
	input(n), input(k);
	input(a[1]); if (a[1] != 1) ans ++, a[1] = 1;
	for (int i = 2; i <= n; ++ i) input(a[i]), add(a[i], i);
	dfs(1, 0);
	return output(ans), 0;
}
