#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
mt19937_64 mt(chrono::system_clock::now().time_since_epoch().count());
const ULL msk = mt();
const int N = 50 + 10;
int n, m, head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int rt[2], siz[N], mx[N];
map<ULL, int> mp;

ULL xrsft(ULL x) {
	x ^= msk, x ^= x << 13, x ^= x >> 7;
	x ^= x << 17, x ^= msk;
	return x;
}

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void solrt(int u, int fa) {
	siz[u] = 1, mx[u] = 0;
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if ((v = edge[i].to) != fa)
			solrt(v, u), siz[u] += siz[v], mx[u] = max(mx[u], siz[v]);
	if (max(mx[u], n - siz[u]) <= n >> 1) rt[(bool)rt[0]] = u;
}

ULL solhs(int u, int fa) {
	ULL hsh = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if ((v = edge[i].to) != fa) hsh += xrsft(solhs(v, u));
	return hsh;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> m;
	for (int i = 1; i <= m; ++ i) {
		cin >> n, rt[0] = rt[1] = etp = 0;
		memset(head, -1, sizeof(int) * (n + 10));
		for (int j = 1, x; j <= n; ++ j) {
			cin >> x;
			if (x) add(j, x), add(x, j);
		}
		solrt(1, 0);
		ULL hsh = solhs(rt[0], 0);
		if (rt[1]) hsh = max(hsh, solhs(rt[1], 0));
		if (!mp[hsh]) mp[hsh] = i;
		cout << mp[hsh] << '\n';
	}
	return 0;
}
