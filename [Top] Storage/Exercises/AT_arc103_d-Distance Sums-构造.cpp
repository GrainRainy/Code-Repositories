#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void ot(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int n, siz[N], u[N], v[N];
struct Req {
	LL val; int id;
	bool operator > (const Req &b) const { return val > b.val; }
}req[N];
LL tmp, tot;

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) rd(tmp), req[i] = {tmp, i}, siz[i] = 1;
	sort(req + 1, req + 1 + n, greater<Req>());
	for (int i = 1, pos; i < n; ++ i) {
		tmp = req[i].val - n + (siz[i] << 1);
		pos = lower_bound(req + 1, req + n + 1, (Req){tmp, 0}, greater<Req>()) - req;
		if (req[pos].val != tmp) return puts("-1"), 0;
		u[i] = req[pos].id, v[i] = req[i].id, siz[pos] += siz[i], tot += siz[i];
	}
	if (tot != req[n].val) return puts("-1"), 0;
	for (int i = 1; i < n; ++ i) ot(u[i], ' '), ot(v[i], '\n');
}
