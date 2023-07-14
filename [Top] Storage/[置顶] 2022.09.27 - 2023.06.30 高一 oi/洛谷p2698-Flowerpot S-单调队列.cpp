#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |+ (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;

const int N = 1e5 + 10;
int n, d;
struct Rain {
	int x, y;
	bool operator < (const Rain &t) const { return x < t.x; }
}ary[N];
int qa[N], ha = 1, ta, qb[N], hb = 1, tb;
int ans = 0x3f3f3f3f;

int main() {
	input(n), input(d);
	for (int i = 1; i <= n; ++ i) input(ary[i].x), input(ary[i].y);
	sort(ary + 1, ary + n + 1);
	for (int l = 0, r = 0; l <= n; ++ l) {
		while (ha <= ta and qa[ha] < l) ha ++;
		while (ha <= ta and qb[hb] < l) hb ++;
		while (ary[qa[ha]].y - ary[qb[hb]].y < d and r < n) {
			r ++;
			while (ha <= ta and ary[qa[ta]].y < ary[r].y) ta --;
			while (hb <= tb and ary[qb[tb]].y > ary[r].y) tb --;
			qa[++ ta] = r, qb[++ tb] = r;
		}
		if (r < n) ans = min(ans, ary[r].x - ary[l].x);
	}
	if (ans >= 0x3f3f3f3f) return puts("-1") & 0;
	cout << ans << endl;
	return 0;
}
