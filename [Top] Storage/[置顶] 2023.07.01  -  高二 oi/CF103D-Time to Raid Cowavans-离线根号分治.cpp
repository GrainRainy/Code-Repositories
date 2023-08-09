#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
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
const int N = 3e5 + 10;
int n, m, a[N], len;
struct Queries {
	int t, k, id;
	bool operator < (const Queries &t) const { return k < t.k; }
}q[N];
LL s[N], ans[N];

void init(int k) {
	for (int i = 0; i < k; ++ i) s[i] = a[i];
	for (int i = k; i <= n; ++ i) s[i] = a[i] + s[i - k];
}

int main() {
	input(n); len = sqrt(n);
	for (int i = 1; i <= n; ++ i) input(a[i]);
	input(m);
	for (int i = 1; i <= m; ++ i) input(q[i].t), input(q[i].k), q[i].id = i;
	sort(q + 1, q + m + 1);
	
	for (int i = 1; i <= m; ++ i) {
		if (q[i].k > len) {
			LL res = 0;
			for (int j = q[i].t; j <= n; j += q[i].k) res += a[j];
			ans[q[i].id] = res;
		} else {
			if (q[i].k != q[i - 1 /* bug */ ].k) init(q[i].k);
			int ed = q[i].t + ((n - q[i].t) / q[i].k) * q[i].k;
			ans[q[i].id] = s[ed] - ((q[i].t >= q[i].k) ? s[q[i].t - q[i].k] : 0); 
		}
	}
	for (int i = 1; i <= m; ++ i) output(ans[i], '\n');
	return 0;
}
