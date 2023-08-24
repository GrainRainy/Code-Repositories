#include <bits/stdc++.h>
using namespace std;

int cnt[26];
string a;

void solve()
{
	memset(cnt, 0, sizeof cnt);
	int len, k;
	cin >> len >> k >> a;
	for (int i = 0; i < len; i ++)
	{
		if (a[i] >= 'a' and a[i] <= 'z')
			cnt[a[i] - 'a'] ++;
		if (a[i] >= 'A' and a[i] <= 'Z')
			cnt[a[i] - 'A'] --;
	}
	for (int i = 0; i < 26 and k > 0; i ++)
	{
		int change = min(abs(cnt[i] / 2), k);
		k -= change;
		if (cnt[i] < 0) cnt[i] += change * 2;
		else cnt[i] -= change * 2;
	}
	
	int res = 0;
	for (int i = 0; i < 26; i ++)
		res += abs(cnt[i]);
	cout << (len - res) / 2 << endl;
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
