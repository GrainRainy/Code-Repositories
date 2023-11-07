#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' <<x << '\n';
using namespace std;
const int N = 1e3 + 10;
const int L = 5e5 + 10;
int n, stk[N] = {-19260817}, tp, pre;
int dp[N][2];
bitset<L> st;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

namespace sub3 {
	int ans = 0;
	void solve() {
		for (int i = 1, a; i <= n; ++ i) {
			rd(a), ans += !st[a], st[a] = true;
			cout << ans << ' ';
		}
		return cout << '\n', void();
	}
}

int main() {
	rd(n);
	if (n > 1000) return sub3::solve(), 0;
	for (int i = 1, a; i <= n; ++ i) {
		rd(a);
		if (st[a]) { cout << pre << ' '; continue; }
		st[a] = true, stk[++ tp] = a, sort(stk + 1, stk + tp + 1);
		memset(dp[0], 0, sizeof(int) * (n + 10));
		memset(dp[1], 0, sizeof(int) * (n + 10));
		for (int j = 1; j <= tp; ++ j) {
			dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]);
			if (stk[j] - stk[j - 1] < 2) dp[j][1] = dp[j - 1][0] + 1;
			else dp[j][1] = dp[j][0] + 1;
		}
		cout << (pre = max(dp[tp][0], dp[tp][1])) << ' ';
	}
	return cout << '\n', 0;
}



/*
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int L = 5e5 + 10;
int n, mx, a[N], pre[L], suf[L], v[L], ans;
struct Node {
	int id, v;
	bool operator < (const Node &t) const { return v < t.v; }
};
bitset<L> st;
priority_queue<Node> q;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) rd(a[i]), mx = max(mx, a[i]);
	for (int i = 1; i <= n; ++ i) {
		q.push({a[i], v[a[i]] = 1}), pre[i] = i - 1, suf[i] = i + 1;
		while (q.size()) {
			int id = q.top().id; q.pop();
			if (st[id]) continue;
			ans += v[id], st[pre[id]] = st[suf[id]] = true;
			v[id] = v[pre[id]] + v[suf[id]] - v[id];
			pre[id] = pre[pre[id]], suf[id] = suf[suf[id]];
			suf[pre[id]] = pre[suf[id]] = id;
			q.push({id, v[id]});
		}
		cout << ans << ' ';
	}
	return cout << '\n', 0;
}
*/
