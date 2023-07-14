#include <bits/stdc++.h>

using namespace std;

string ans = "314159265358979323846264338327";

void solve()
{
	string a;
	cin >> a;
	int res = 0;
	for (int i = 0; i < min(a.size(), ans.size()); i ++)
	{
		if (a[i] == ans[i]) res ++;
		else break;
	}
	cout << res << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t --) solve();
	
	return 0;
}
