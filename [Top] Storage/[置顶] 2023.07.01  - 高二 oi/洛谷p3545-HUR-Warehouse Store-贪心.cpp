#include <bits/stdc++.h>
#define fi first
#define se second
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
using LL = long long;
using PII = pair<int, int>;
const int N = 2.5e5 + 10;
int n, a[N], b[N], top;
LL sum;
priority_queue<PII> q;
int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(a[i]);
	for (int i = 1, tmp; i <= n; ++ i) {
		input(tmp);
		sum += a[i];
		if (sum >= tmp) sum -= tmp, q.push({tmp, i});
		else if (q.size() and q.top().fi > tmp) 
			sum += q.top().fi - tmp, q.pop(), q.push({tmp, i});
	} 
	output(sum = q.size());
	while (q.size()) b[++ top] = q.top().se, q.pop();
	sort(b + 1, b + sum + 1);
	for (int i = 1; i <= sum; ++ i) output(b[i], " \n"[i == sum]);
	return 0;
}
