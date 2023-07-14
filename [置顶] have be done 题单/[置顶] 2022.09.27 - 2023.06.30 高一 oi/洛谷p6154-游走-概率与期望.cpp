#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input (T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e5 + 10;
const int M = 7e5 + 10;
const int MOD = 998244353;
int n, m, u, v;
LL val[N], cnt[N];
LL tval, tcnt;

int head[N], idx;
struct Edge {
	int nxt, to;
}edge[M];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dp(int u) {
	if (cnt[u]) return;
	cnt[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		dp(j);
		cnt[u] = ((LL)cnt[u] + cnt[j]) % MOD;
		val[u] = ((LL)val[u] + val[j] + cnt[j]) % MOD;
	}
	return;
}

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	memset(head, -1, sizeof head);
	input(n), input(m);
	for (int i = 1; i <= m; ++ i) {
		input(u), input(v);
		add(u, v);
	}
	
	for (int i = 1; i <= n; ++ i) if (!cnt[i]) dp(i);
	for (int i = 1; i <= n; ++ i) {
		tval = (tval + val[i]) % MOD;
		tcnt = (tcnt + cnt[i]) % MOD;
	}
	cout << tval * qpow(tcnt, MOD - 2) % MOD << endl;
	return 0;
}
