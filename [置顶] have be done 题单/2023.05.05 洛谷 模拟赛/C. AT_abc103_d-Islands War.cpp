#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e5 + 10;
int n, m, ans;
struct Segment{
	int l, r;
	
	bool operator < (const Segment &t) const {
		if (l != t.l) return l < t.l;
		return r < t.r;
	}
}seg[N];

int main() {
	input(n), input(m);
	for (int i = 1; i <= m; i ++) {
		input(seg[i].l), input(seg[i].r);
	}
	sort(seg + 1, seg + 1 + m);
	
	int tmpl = seg[1].l, tmpr = seg[1].r, ans = 1;
	for (int i = 2; i <= m; i ++) {
		if (seg[i].l >= tmpr)
			ans ++, tmpl = seg[i].l, tmpr = seg[i].r;
		else tmpl = max(tmpl, seg[i].l), tmpr = min(tmpr, seg[i].r);
	}
	cout << min(ans, n - 1) << endl;
	return 0;
}
