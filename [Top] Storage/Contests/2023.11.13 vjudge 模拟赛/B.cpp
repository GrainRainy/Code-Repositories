#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e6 + 10;
int sub, n, l[5], a[N], len, pre;
int stk[N], tp, pe[N], sf[N];
string s;

inline void ot(int tp) {
	cout << "Case #" << sub << ": ";
	if (tp == 1) cout << "DISLIKE\n";
	else if (tp == 2) cout << "LIKE\n";
	else cout << "SURPRISE\n";
}

void solve() {
	cin >> s >> l[0] >> l[1], len = pre = tp = 0, n = s.size();
	a[0] = a[n] = 2, l[2] = 3e8, pe[0] = pe[n + 1] = sf[0] = sf[n + 1] = 0;
	for (int i = 0; i < s.size(); ++ i) {
		if (s[i] == '?') a[i + 1] = -1, stk[++ tp] = i + 1;
		else if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i') a[i + 1] = 0;
		else if (s[i] == 'o' or s[i] == 'u') a[i + 1] = 0;
		else a[i + 1] = 1;
	}
//	for (int i = 1; i <= n; ++ i) cout << a[i] << ' ';
//	cout << '\n';
	if (l[0] == 1) {
		for (int i = 1; i <= tp; ++ i) a[stk[i]] = 1;
		for (int i = 1; i <= n; ++ i) {
			if (a[i] == a[i - 1]) pe[i] = pe[i - 1] + 1;
			else pe[i] = 1;
			if (pe[i] >= l[a[i]]) return ot(1);
		}
	} else if (l[1] == 1) {
		for (int i = 1; i <= tp; ++ i) a[stk[i]] = 0;
		for (int i = 1; i <= n; ++ i) {
			if (a[i] == a[i - 1]) pe[i] = pe[i - 1] + 1;
			else pe[i] = 1;
			if (pe[i] >= l[a[i]]) return ot(1);
		}
	}
	for (int i = 1; i <= n; ++ i) {
		if (a[i] == a[i - 1]) pe[i] = pe[i - 1] + 1;
		else pe[i] = 1;
		if (~a[i] and pe[i] >= l[a[i]]) return ot(1);
	}
	for (int i = n; i; -- i) {
		if (a[i] == a[i + 1]) sf[i] = sf[i + 1] + 1;
		else sf[i] = 1;
		if (~a[i] and sf[i] >= l[a[i]]) return ot(1);
	}
	for (int i = 1; i <= n; ++ i) {
		if (a[i] != -1 or a[i - 1] == -1 or a[i + 1] == -1 or a[i - 1] == a[i + 1])
			continue;
		if (pe[i - 1] + 1 >= l[a[i - 1]] and sf[i + 1] + 1 >= l[a[i + 1]])
			return ot(1);
	}
	for (int i = 1; i <= tp; ++ i) a[stk[i]] = 0;
	for (int i = 1; i <= n; ++ i) {
		if (a[i] == a[i - 1]) pe[i] = pe[i - 1] + 1;
		else pe[i] = 1;
		if (pe[i] >= l[a[i]]) return ot(3);
	}
	for (int i = 1; i <= tp; ++ i) a[stk[i]] = 1;
	for (int i = 1; i <= n; ++ i) {
		if (a[i] == a[i - 1]) pe[i] = pe[i - 1] + 1;
		else pe[i] = 1;
		if (pe[i] >= l[a[i]]) return ot(3);
	}
	return ot(2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) ++ sub, solve();
	return 0;
}
