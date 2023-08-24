#include <iostream>
#include <cstring>

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
int n, maxw, v, w, m;
int maxk, lim, d, i, k, k1, head, tail, now;
int f[N], g[N], q[N];

inline void update(int &x, int y) { (x < y) ? x = y : 0; } 

int main() {
	input(n), input(maxw);
	for (int i = 1; i <= n; ++ i) {
		input(v), input(w), input(m);
		for (int d = 0; d < w; ++ d) {
			maxk = (maxw - d) / w;
			lim = max(maxk - m, 0);
			for (tail = 0, k = maxk - 1; k >= lim; -- k) {
				now = f[k * w + d] - k * v;
				while (tail and g[tail] <= now) -- tail;
				g[++ tail] = now, q[tail] = k;
			}
			for (head = 1, k1 = maxk; ~k1; -- k1, -- k) {
				if (head <= tail and q[head] >= k1) ++ head;
				if (head <= tail) update(f[k1 * w + d], g[head] + k1 * v);
				if (k < 0) continue;
				now = f[k * w + d] - k * v;
				while (head <= tail and g[tail] <= now) -- tail;
				g[++ tail] = now, q[tail] = k;
			}
		}
	}
	cout << f[maxw] << '\n';
	return 0;
}
