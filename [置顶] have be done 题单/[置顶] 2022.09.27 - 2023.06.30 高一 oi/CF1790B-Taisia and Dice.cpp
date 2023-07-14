#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, s, r;
	cin >> n >> s >> r;
	int base = r / (n - 1); 
	int cntadd = r - base * (n - 1);
	cout << s - r << " ";
	for (int i = 1; i <= n - 1 - cntadd; i ++)
		cout << base << " ";
	for (int i = 1; i <= cntadd; i ++)
		cout << base + 1 << " ";
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
