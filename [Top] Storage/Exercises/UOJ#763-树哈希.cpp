#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
mt19937_64 mt(chrono::system_clock::now().time_since_epoch().count());
const ULL msk = mt();
const int N = 1e6 + 10;
int n, head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
ULL hsh[N];
set<ULL> st;

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

ULL xrsft(ULL x) {
	x ^= msk, x ^= x << 13, x ^= x >> 7;
	x ^= x << 17, x ^= msk;
	return x;
}

void sol(int u, int fa) {
	hsh[u] = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if ((v = edge[i].to) != fa) sol(v, u), hsh[u] += xrsft(hsh[v]);
	st.insert(hsh[u]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i)
		cin >> a >> b, add(a, b), add(b, a);
	sol(1, 0);
	return cout << st.size() << '\n', 0;
}
