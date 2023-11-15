#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 5e5 + 10;
int n, k;
LL dt, w[N];
struct Node {
	int pos; LL sm;
	bool operator > (const Node &t) const { return sm > t.sm; }
};
priority_queue<Node, vector<Node>, greater<Node>> q;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int main() {
	rd(n), rd(k);
	for (int i = 1; i <= n; ++ i) {
		rd(w[i]);
		if (w[i] < 0) dt += w[i], w[i] = -w[i];
	}
	sort(w + 1, w + n + 1), q.push({0, dt});
	while (k --) {
		auto t = q.top(); q.pop();
		ot(t.sm);
		if (t.pos == n) continue;
		q.push({t.pos + 1, t.sm + w[t.pos + 1]});
		if (t.pos) q.push({t.pos + 1, t.sm - w[t.pos] + w[t.pos + 1]});
	}
	return 0;
}
