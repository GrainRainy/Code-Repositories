#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;
const int N = 1e5 + 10;
int n, ary[N];
int sta[N], stb[N];
int ca1, va1, ca2, va2;
int cb1, vb1, cb2, vb2;
int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(ary[i]);
	for (int i = 1; i <= n; i += 2) {
		sta[ary[i]] ++;
		if (ary[i] == va1) ca1 ++;
		else if (sta[ary[i]] > ca1) {
			ca2 = ca1, ca1 = sta[ary[i]];
			va2 = va1, va1 = ary[i];
		} else if (sta[ary[i]] > ca2) {
			ca2 = sta[ary[i]], va2 = ary[i];
		}
	}
	for (int i = 2; i <= n; i += 2) {
		stb[ary[i]] ++;
		if (ary[i] == vb1) cb1 ++;
		else if (stb[ary[i]] > cb1) {
			cb2 = cb1, cb1 = stb[ary[i]];
			vb2 = vb1, vb1 = ary[i];
		} else if (stb[ary[i]] > cb2) {
			cb2 = stb[ary[i]], vb2 = ary[i];
		}
	}
	if (va1 == vb1) cout << min(n - ca1 - cb2, n - ca2 - cb1) << endl;
	else cout << n - ca1 - cb1 << endl;
	return 0;
}
