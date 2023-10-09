#include <bits/stdc++.h>
using namespace std;
using UI = unsigned int;
const int N = 5e5 + 10;
const int LOGN = 33;
UI n, k, a[N], tr[N * LOGN][2], ttp, siz[N * LOGN];
struct Item {
	UI v, rk, ori;
	bool operator < (const Item &t) const { return v < t.v; }
};
priority_queue<Item> q;
UI res, rk, ori;
unsigned long long ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
} 

void insert(UI u) {
	UI p = 0, sn;
	for (int i = 31; ~i; -- i) {
		sn = (u >> i) & 1;
		if (!tr[p][sn]) tr[p][sn] = ++ ttp;
		siz[p] ++, p = tr[p][sn];
	}
	siz[p] ++;
}

UI query(UI u, int rk) {
	UI ans = 0, p = 0, sn;
	for (int i = 31; ~i; -- i) {
		sn = (u >> i) & 1;
		if (!tr[p][sn ^ 1]) p = tr[p][sn];
		else if (siz[tr[p][sn ^ 1]] >= rk) p = tr[p][sn ^ 1], ans |= 1ll << i;
		else rk -= siz[tr[p][sn ^ 1]], p = tr[p][sn];
	}
	return ans;
}

int main() {
	rd(n), rd(k), k <<= 1;
	insert(0);
	for (int i = 1; i <= n; ++ i) rd(a[i]), a[i] ^= a[i - 1], insert(a[i]);
	for (int i = 0; i <= n; ++ i) q.push({query(a[i], 1), 1, a[i]});
	while (k --) {
		res = q.top().v, rk = q.top().rk, ori = q.top().ori, q.pop();
		if (rk < n) q.push({query(ori, rk + 1), rk + 1, ori}); 
		ans += res;
	} 
	return cout << (ans >> 1) << '\n', 0;
}
