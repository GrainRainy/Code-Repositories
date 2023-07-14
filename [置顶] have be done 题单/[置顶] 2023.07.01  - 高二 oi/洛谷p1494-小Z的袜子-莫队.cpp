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
using LL = long long;

const int N = 5e4 + 10;
int n, m, ary[N];
int len, cnt[N];
LL ans1[N], ans2[N], sum;
struct Query {
	int l, r, id;
	bool operator < (const Query &t) const {
		if (l / len != t.l / len) return l < t.l;
		return l / len & 1 ? r < t.r : r > t.r;
	}
}q[N];

inline void add(int a) {
	sum += cnt[a];
	cnt[a] ++;
}

inline void del(int a) {
	cnt[a] --;
	sum -= cnt[a];
}

int main() {
	input(n), input(m);
	len = sqrt(n);
	for (int i = 1; i <= n; ++ i) input(ary[i]);
	for (int i = 1; i <= m; ++ i) {
		input(q[i].l), input(q[i].r);
		q[i].id = i;
	}
	sort(q + 1, q + m + 1);
	for (int i = 1, l = 1, r = 0; i <= m; ++ i) {
		if (q[i].l == q[i].r) continue;
		while (l > q[i].l) add(ary[-- l]);
		while (r < q[i].r) add(ary[++ r]);
		while (l < q[i].l) del(ary[l ++]);
		while (r > q[i].r) del(ary[r --]);
		ans1[q[i].id] = sum;
		ans2[q[i].id] = (LL)(r - l + 1) * (r - l) / 2;
	}
	for (int i = 1; i <= m; ++ i) {
		if (!ans1[i]) puts("0/1");
		else {
			LL tmp = __gcd(ans1[i], ans2[i]);
			printf("%d/%d\n", ans1[i] / tmp, ans2[i] / tmp);
		}
	}
	return 0;
}

