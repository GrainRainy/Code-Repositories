#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace std; 
using namespace IO;
using LL = long long;

const int N = 1e6 + 10;
int n, x, ary[N], vt[N], bt[N];
// basis 
int hh = 1, tt = 0, q[N];
// queue 
int hn, gap;
LL ans, cnt;

int main() {
	input(n), input(x);
	for (int i = 1; i <= n; ++ i) input(ary[i]);
	for (int i = 1; i <= n; ++ i) {
		while (hh <= tt and q[hh] <= i - x) hh ++;
		while (hh <= tt and ary[q[tt]] > ary[i]) tt --;
		tt ++;
		q[tt] = i;
		if (i - x + 1 >= 0) vt[i - x + 1] = ary[q[hh]];
	}
	hh = 1, tt = 0;
	for (int i = 1; i <= n; ++ i) {
		while (hh <= tt and q[hh] <= i - x) hh ++;
		while (hh <= tt and vt[q[tt]] < vt[i]) tt --;
		tt ++;
		q[tt] = i;
		bt[i] = vt[q[hh]];
	}
	for (int i = 1; i <= n; ++ i) ans += ary[i] - bt[i];
	cout << ans << endl;
	for (int i = 1; i <= n; ++ i) {
		if (bt[i] != hn or gap < i) {
			hn = bt[i];
			gap = i + x - 1;
			cnt ++;
		}
	}
	cout << cnt << endl;
	return 0;
}
