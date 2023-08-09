#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n;
char a[N];
int st[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> a + 1;
	
	for (int i = 1; i <= n; i ++)
		st[a[i] - 'a'] ++;
	
	int ans = 0;
	for (int i = 0; i < 26; i ++)
		if (st[i]) ans ++;
		
	cout << ans << endl;
	return 0;
}
