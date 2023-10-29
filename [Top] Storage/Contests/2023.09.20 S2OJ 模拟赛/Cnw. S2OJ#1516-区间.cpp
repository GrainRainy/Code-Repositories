#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 2.5e3 + 10;
int n, k, l[N], r[N], w[N];
long long sm, val, f[N << 1];
vector<int> nums;
vector<pair<int, int>> seg[N << 1];
priority_queue<int, vector<int>, greater<int>> q;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int v) {
	if (q.size() < k) q.push(v), val += v;
	else if (v > q.top()) val -= q.top(), q.pop(), q.push(v), val += v;
}

int main() {
	rd(n), rd(k);
	for (int i = 1; i <= n; ++ i) {
		rd(l[i]), rd(r[i]), rd(w[i]), sm += w[i];
		nums.push_back(l[i]), nums.push_back(r[i]);
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	for (int i = 1; i <= n; ++ i) {
		l[i] = lower_bound(nums.begin(), nums.end(), l[i]) - nums.begin() + 1;
		r[i] = lower_bound(nums.begin(), nums.end(), r[i]) - nums.begin() + 1;
		seg[l[i]].push_back({r[i], w[i]});
	}
	for (int i = 1; i <= nums.size(); ++ i) {
		val = 0;
		while (q.size()) q.pop();
		for (int j = i - 1; ~j; -- j) {
			for (auto t : seg[j + 1]) if (t.first <= i) add(t.second);
			f[i] = max(f[i], f[j] + val);
		}
	}
	return cout << sm - *max_element(f + 1, f + nums.size() + 1) << '\n', 0;
}
