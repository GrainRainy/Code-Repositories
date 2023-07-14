#include <bits/stdc++.h>
#define debug(x) cout << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std;
using LL = long long;

const int N = 5e5 + 10;
const int LOGN = 20; 
int n, k, l, r;
LL st[N][LOGN], sum[N], ans;

void init() {
	int tmpx, tmpy;
	for (int i = 0; i < LOGN; ++ i)
		for (int j = 1; j + (1 << i) - 1 <= n; ++ j) {
			if (!i) st[j][i] = j;
			else {
				tmpx = st[j][i - 1], tmpy = st[j + (1 << i - 1)][i - 1];
				st[j][i] = sum[tmpx] > sum[tmpy] ? tmpx : tmpy;
			}
		}
}

int query(int l, int r) {
	int k = log2(r - l + 1);
	int tmpx = st[l][k], tmpy = st[r - (1 << k) + 1][k];
	return sum[tmpx] > sum[tmpy] ? tmpx : tmpy;
}

struct Element {
	int st, l, r, pos;
	Element();
	Element(int a, int b, int c) : st(a), l(b), r(c), pos(query(l, r)) {}
	bool operator < (const Element &t) const {
		return sum[pos] - sum[st - 1] < sum[t.pos] - sum[t.st - 1];
	}
};
priority_queue<Element> q;

int main() {
	input(n), input(k), input(l), input(r);
	for (int i = 1; i <= n; ++ i) 
		input(sum[i]), sum[i] += sum[i - 1];
	init();
	for (int i = 1; i + l - 1 <= n; ++ i) 
		q.push(Element(i, i + l - 1, min(i + r - 1, n)));	
	while (k --) {
		int st = q.top().st, l = q.top().l, r = q.top().r, pos = q.top().pos;
		q.pop();
		ans += sum[pos] - sum[st - 1];
		if (l != pos) q.push(Element(st, l, pos - 1));
		if (r != pos) q.push(Element(st, pos + 1, r));
	}
	printf("%lld\n", ans);
	return 0;
}
