#include <iostream>
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
const int N = 1e6 + 10;
int n, k, hi = 1, ha = 1, ti, ta;
int ary[N], qi[N], qa[N], ansa[N];

int main() {
	input(n), input(k);
	for (int i = 1; i <= n; ++ i) {
		input(ary[i]);
		while (hi <= ti and qi[hi] + k <= i) hi ++;
		while (hi <= ti and ary[qi[ti]] > ary[i]) ti --;
		qi[++ ti] = i;
		if (i >= k) output(ary[qi[hi]], " \n"[i == n]);
		
		while (ha <= ta and qa[ha] + k <= i) ha ++;
		while (ha <= ta and ary[qa[ta]] < ary[i]) ta --;
		qa[++ ta] = i;
		ansa[i] = ary[qa[ha]];
	}
	for (int i = k; i <= n; ++ i) output(ansa[i], " \n"[i == n]);
	return 0;
}
