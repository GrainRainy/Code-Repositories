#include <bits/stdc++.h>
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
const int N = 5e5 + 10;
int n, a[N];
double sqt[N], p[N];
int pot[N], stk[N], head, tail;

inline double Y(int x, int id) { return a[id] + sqt[x - id]; }

int binary(int i, int j) {
	int l = j, r = n + 1, mid;
	while (l < r) {
		mid = l + r >> 1;
		if (Y(mid, i) <= Y(mid, j)) r = mid;
		else l = mid + 1;
	}
	return l;
}

void solve() {
	head = 1, tail = 0;
	for (int i = 1; i <= n; ++ i) {
		while (head < tail and pot[tail - 1] >= binary(stk[tail], i)) tail --;
		pot[tail] = binary(stk[tail], i);
		stk[++ tail] = i;
		while (head < tail and pot[head] <= i) ++ head;
		p[i] = max(p[i], Y(i, stk[head]));
	}
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(a[i]), sqt[i] = sqrt(i);
	solve();
	for (int i = 1; i < n - i + 1; ++ i)
		swap(a[i], a[n - i + 1]), swap(p[i], p[n - i + 1]);
	solve();
	for (int i = n; i; -- i) output((int)ceil(p[i]) - a[i]);
	return 0;
}
