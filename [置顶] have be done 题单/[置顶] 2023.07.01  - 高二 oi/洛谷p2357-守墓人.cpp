#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
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
		static short st[40], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
LL n, f, op, l, r, k;
LL d[N], di[N]; // d, di 

void modify(int pos, LL val) {
	for (int i = pos; i <= n; i += lowbit(i))
		d[i] += val, di[i] += (LL)val * pos;
}

LL query(int r) {
	LL res = 0;
	for (int i = r; i; i -= lowbit(i))
		res += (r + 1) * d[i] - di[i];
	return res;
}

void modifyRange(int l, int r, LL val) {
	modify(l, val), modify(r + 1, -val);
}

int main() {
	input(n), input(f);
	LL tmp, lst = 0;
	for (int i = 1; i <= n; ++ i)
		input(tmp), modify(i, tmp - lst), lst = tmp;
	while (f --) {
		input(op);
		if (op == 1) input(l), input(r), input(k), modifyRange(l, r, k);
		if (op == 2) input(k), modifyRange(1, 1, k);
		if (op == 3) input(k), modifyRange(1, 1, -k); 
		if (op == 4) input(l), input(r), output(query(r) - query(l - 1));
		if (op == 5) output(query(1));
	}
	return 0;
}
