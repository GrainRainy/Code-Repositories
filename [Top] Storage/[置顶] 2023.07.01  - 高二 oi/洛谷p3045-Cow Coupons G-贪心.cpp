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
}

using IO::input;
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int N = 5e4 + 10;
int n, k;
LL res, sum;
struct Item { 
	int p, c;
	bool operator < (const Item &t) const {
		return c < t.c;
	}
}a[N];
bool st[N];
priority_queue<int, vector<int>, greater<int>> hd; // delta heap
priority_queue<PII, vector<PII>, greater<PII>> hp, hc; // p heap and c heap

int main() {
	input(n), input(k), input(sum);
	for (int i = 1; i <= n; ++ i) input(a[i].p), input(a[i].c);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= k; ++ i) {
		res += a[i].c;
		hd.push(a[i].p - a[i].c);
		if (res > sum) return printf("%d\n", i - 1), 0;
	}
	for (int i = k + 1; i <= n; ++ i)
		hp.push({a[i].p, i}), hc.push({a[i].c, i});
	for (int i = k + 1; i <= n; ++ i) {
		while (st[hc.top().se]) hc.pop();
		while (st[hp.top().se]) hp.pop();
		int pria = hc.top().fi + hd.top();
		int prib = hp.top().fi;
		if (pria < prib) {
			res += pria;
			st[hc.top().se] = true;
			hd.pop(); hd.push(a[hc.top().se].p - a[hc.top().se].c);
			hc.pop(); 
		} else {
			res += prib;
			st[hp.top().se] = true;
			hp.pop();
		}
		if (res > sum) return printf("%d\n", i - 1), 0;
	}
	return printf("%d\n", n), 0;
}
