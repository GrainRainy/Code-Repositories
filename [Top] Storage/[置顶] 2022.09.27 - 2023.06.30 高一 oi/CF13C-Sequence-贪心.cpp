#include <iostream>
#include <queue>

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

using namespace std;
using namespace IO;
using LL = long long;

LL n, tmp, ans;
priority_queue<LL> q;

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) {
		input(tmp);
		q.push(tmp);
		if (tmp < q.top()) {
			ans += q.top() - tmp;
			q.pop(), q.push(tmp);
		}
	}
	return output(ans), 0;
}
