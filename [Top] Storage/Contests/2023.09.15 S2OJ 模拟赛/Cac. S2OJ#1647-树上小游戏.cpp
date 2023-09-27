#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
#define DEBUG cerr << "-- DEBUG --\n";
using namespace std;
const int N = 3e4 + 10;
int n, l[N], r[N];
bool c[N];
int cnt;
set<int> st;

bool dfs(bool who) {
	if (!st.size()) return !(cnt & 1);
	set<int> tmp;
	int tmpcnt = 0;
	bool f = who;
	tmp = st, tmpcnt = cnt;
	for (auto t : tmp) {
		if (c[t]) cnt ++;
		st.erase(t);
		if (l[t]) st.insert(l[t]);
	}
	who ? f &= dfs(0) : f |= dfs(1);
	if (f != who) return f;
	st = tmp, cnt = tmpcnt;
	for (auto t : tmp) {
		if (c[t]) cnt ++;
		st.erase(t);
		if (r[t]) st.insert(r[t]);
	}
	who ? f &= dfs(0) : f |= dfs(1);
	if (f != who) return f;
	st = tmp, cnt = tmpcnt;
	
	for (auto t : tmp) {
		if (c[t]) cnt ++;
		st.erase(t);
		if (l[t]) st.insert(l[t]);
		if (r[t]) st.insert(r[t]);
	}
	who ? f &= dfs(0) : f |= dfs(1);
	return f;
}

bool solve(int u) {
	cnt = 0;
	st.clear(); st.insert(u);
	return dfs(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> l[i] >> r[i] >> c[i];
	for (int i = 1; i <= n; ++ i)
		cout << (solve(i) ? "Alice" : "Bob") << '\n';
	return 0;
}
