#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], delp, suf[N], sp[N];
set<int> st;

void solve() {
	cin >> n, delp = 0, st.clear();
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		if (a[i]) st.insert(a[i]);
	}
	for (int i = 1; i <= n; ++ i)  {
		if (st.find(i) == st.end()) st.insert(i);
		else st.erase(i);
	}
	suf[n + 1] = n + 1;
	for (int i = n; i; -- i) {
		suf[i] = a[i] ? min(suf[i + 1], a[i]) : suf[i + 1];
		sp[i] = suf[i] == a[i] ? i : sp[i + 1];
	}
	for (int i = 1, x, nxt; i <= n; ++ i) {
		if (!a[i]) x = *st.begin(), st.erase(st.begin());
		else x = a[i];
		nxt = a[i + 1] ? a[i + 1] : *st.begin();
		if (!a[i] and suf[i] < x) { delp = sp[i]; break; }
		if (nxt < x) { delp = i; break; }
	}
	st.clear();
	if (!delp) delp = n;
	for (int i = 1; i <= n; ++ i) if (a[i] and i != delp) st.insert(a[i]);
	for (int i = 1; i <= n; ++ i) {
		if (st.find(i) == st.end()) st.insert(i);
		else st.erase(i);
	}
	for (int i = 1; i <= n; ++ i) {
		if (i == delp) continue;
		if (!a[i]) a[i] = *st.begin(), st.erase(st.begin());
		cout << a[i] << ' ';
	}
	return cout << '\n', void();
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
