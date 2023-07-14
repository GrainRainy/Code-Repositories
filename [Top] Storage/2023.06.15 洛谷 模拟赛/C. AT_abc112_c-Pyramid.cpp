#include <bits/stdc++.h>
#define __DEBUG__ puts("__DEBUG__");

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
const int N = 1e2 + 10;
int n, tmph;
struct SPOT {
	int x, y, h;
	bool operator < (const SPOT &t) const {
		return h > t.h;
	}
}ary[N];

bool check(int x, int y) {
	tmph = 0;
	if (!ary[1].h) tmph = 1;
	for (int i = 1; i <= n; ++ i) {
		if (ary[i].h) {
			if (!tmph) tmph = ary[i].h + abs(x - ary[i].x) + abs(y - ary[i].y);
			else if (tmph != ary[i].h + abs(x - ary[i].x) + abs(y - ary[i].y))
				return false;
		}
		else if (tmph and tmph > abs(x - ary[i].x) + abs(y - ary[i].y))
			return false; 
	}
	return true;
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i)
		input(ary[i].x), input(ary[i].y), input(ary[i].h);
	sort(ary + 1, ary + n + 1);
	
	for (int i = 0; i <= 100; ++ i)
		for (int j = 0; j <= 100; ++ j) {
			if (check(i, j)) {
				output(i, ' '), output(j, ' '), output(tmph);
				return 0;
			}
		}
	return 0;
}
