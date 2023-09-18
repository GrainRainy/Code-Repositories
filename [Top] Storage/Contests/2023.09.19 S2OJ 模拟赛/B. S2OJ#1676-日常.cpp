#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N = 1e5 + 10;
int n, m, k, pos, prer = 1;
struct Target { int l, x, y, r; }t[N];
bool hit[N];
set<PII> st;
set<PII>::iterator it;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int main() {
	rd(n), rd(m), rd(k);
	for (int i = 1, l, x, y, r; i <= n; ++ i) {
		rd(l), rd(x), rd(y), rd(r);
		t[i] = {l, x, y, r}, st.insert({t[i].l, i});
	}
	while (k --) {
		rd(pos);
		it = st.upper_bound({pos, n + 1});
		int u = (*--it).second;
		if (pos < t[u].l or pos > t[u].r) puts("Failed");
		else if (hit[u]) puts("Again");
		else if (pos >= t[u].x and pos <= t[u].y) puts("Perfect"), hit[u] = true;
		else puts("Normal"), hit[u] = true;
	}
	return 0;
}
