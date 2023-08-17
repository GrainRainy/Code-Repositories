#include <bits/stdc++.h>
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar(); 
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
using namespace std;
const int N = 3e6 + 10;
int k, n, a[N], l = 1, ans;
int mxq[N], mnq[N], mxh = 1, mnh = 1, mxt, mnt;

int main() {
	rd(k), rd(n);
	for (int i = 1; i <= n; ++ i) {
		rd(a[i]);
		while (mxh <= mxt and a[mxq[mxt]] < a[i]) mxt --;
		while (mnh <= mnt and a[mnq[mnt]] > a[i]) mnt --;
		mxq[++ mxt] = mnq[++ mnt] = i;
		while (a[mxq[mxh]] - a[mnq[mnh]] > k) {
			if (mxq[mxh] < mnq[mnh]) l = mxq[mxh] + 1, mxh ++;
			else l = mnq[mnh] + 1, mnh ++;
		}
		ans = max(ans, i - l + 1);
	}
	return printf("%d\n", ans), 0;
}
