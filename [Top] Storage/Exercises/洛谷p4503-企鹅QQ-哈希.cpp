#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
const int N = 3e4 + 10;
const int L = 2e2 + 10;
const int BASE = 13331;
int n, l, mxs, ans;
ULL p[L] = {1};
char s[N][L];
unordered_map<ULL, int> mp;

void hsh(const char s[], int pos) {
	ULL val = 0;
	for (int i = 1; i <= l; ++ i) {
		if (i != pos) val = val * BASE + (s[i] - '0' + 1);
		else val = val * BASE + ('{' - '0' + 1);
	}
	mp[val] ++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> l >> mxs;
	for (int i = 1; i <= n; ++ i) cin >> s[i] + 1;
	for (int i = 1; i <= l; ++ i) p[i] = p[i - 1] * BASE;
	for (int i = 1; i <= l; ++ i) {
		for (int j = 1; j <= n; ++ j) hsh(s[j], i);
		for (auto t : mp) ans += t.second * (t.second - 1) / 2;
		mp.clear();
	}
	return cout << ans << '\n', 0;
}
