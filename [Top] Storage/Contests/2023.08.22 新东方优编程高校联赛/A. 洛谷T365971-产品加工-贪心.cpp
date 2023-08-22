#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}
using IO::rd;
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int P = 1e6 + 10;
int n, m, q;
LL d[N], t[N], tmp[P << 1], ans;
struct Machine {
	int id; LL val;
	bool operator < (const Machine &t) const {
		return val > t.val;
	}
};
priority_queue<LL> tg;
priority_queue<Machine> mc;

bool check(LL u) {
	LL res = 0;
	for (int i = 1; i <= n; ++ i) {
		res += u / t[i];
		if (res >= q) return true;
	}
	return false;
}

int main() {
	rd(q), rd(n), rd(m);
	if (!q) return cout << 0 << endl, 0;
	for (int i = 1; i <= n; ++ i) rd(t[i]);
	for (int i = 1; i <= m; ++ i) rd(d[i]);
	LL l = 1, r = 1e15, mid;
	while (l < r) {
		mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= l / t[i]; ++ j)
			tmp[++ tmp[0]] = (LL)j * t[i];
	sort(tmp + 1, tmp + tmp[0] + 1);
	for (int i = 1; i <= q; ++ i) tg.push(tmp[i]);
	for (int i = 1; i <= m; ++ i) mc.push({i, d[i]});
	while (tg.size()) {
		LL u = tg.top(); tg.pop();
		auto m = mc.top();
		mc.pop(), mc.push({m.id, m.val + d[m.id]});
		ans = max(ans, u + m.val);
	}
	cout << ans << endl;
	return 0;
}
