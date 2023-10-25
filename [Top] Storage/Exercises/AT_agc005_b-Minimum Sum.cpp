#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using LL = long long; 
const int N = 2e5 + 10;
int n;
PII a[N];
LL ans;
set<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i].first, a[i].second = i;
	sort(a + 1, a + n + 1);
	for (int i = 1, l, r; i <= n; ++ i) {
		auto itl = st.lower_bound(a[i].second);
		auto itr = st.upper_bound(a[i].second);
		l = itl == st.begin() ? 1 : *(--itl) + 1;
		r = itr == st.end() ? n : *itr - 1;
		ans += (LL)a[i].first * (a[i].second - l + 1) * (r - a[i].second + 1);
		st.insert(a[i].second);
	}
	return cout << ans << '\n', 0;
}
