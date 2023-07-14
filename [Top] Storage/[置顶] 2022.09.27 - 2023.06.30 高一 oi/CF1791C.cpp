#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	int ans = n;
	int idx1 = 0, idx2 = n - 1;
	while ((s[idx1] == '0' && s[idx2] == '1') || (s[idx1] == '1' && s[idx2] == '0'))
		idx1 ++, idx2 --;
	ans = max(idx2 - idx1 + 1, 0);
	cout << ans << endl;
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
