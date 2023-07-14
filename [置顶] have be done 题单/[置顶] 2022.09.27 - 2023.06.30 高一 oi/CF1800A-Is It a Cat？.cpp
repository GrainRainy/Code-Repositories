#include <bits/stdc++.h>
using namespace std;

string ans = "meow";
string a;
int len;

void solve()
{
	cin >> len >> a;
	for (int i = 0; i < len; i ++)
	{
		if (a[i] >= 'A' and a[i] <= 'Z') a[i] += 32;
	}
	int i = 0;
	int f = 0;
	while (a[i] == ans[0]) i ++, f |= 1;
	while (a[i] == ans[1]) i ++, f |= 2;
	while (a[i] == ans[2]) i ++, f |= 4;
	while (a[i] == ans[3]) i ++, f |= 8;
	if (i == len and f == 15) cout << "YES" << endl;
	else cout << "NO" << endl;
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
