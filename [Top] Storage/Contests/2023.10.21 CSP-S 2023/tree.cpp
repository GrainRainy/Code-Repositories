#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], b[N], c[N], head[N], idx;
struct Node { int nxt, to; }edge[N << 1];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i] >> b[i] >> c[i];
	cout << n << '\n';
}
