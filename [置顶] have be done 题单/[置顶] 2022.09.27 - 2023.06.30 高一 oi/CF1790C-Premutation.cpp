#include <bits/stdc++.h>

using namespace std;

const int N = 110, INF = 1e9;

int nums[N][N];
bool st[N];

void solve()
{
	memset(st, 0, sizeof st);

	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n - 1; j ++)
		{
			cin >> nums[i][j];
			if (i == 1) st[nums[i][j]] = true;
		}                        
	nums[1][0] = nums[1][0] = nums[1][0] = -INF;
	nums[1][n] = nums[2][n] = nums[3][n] = INF;
	
	int t = -1;
	for (int i = 1; i <= n; i ++)
		if (!st[i])
		{
			t = i;
			break;
		}
	
	int lt1 = 0, rt1 = n, lt2 = 0, rt2 = n;
	for (int i = 1; i < n; i ++)
	{
		if (nums[2][i] == t) lt1 = nums[2][i - 1], rt1 = nums[2][i + 1];
		if (nums[3][i] == t) lt2 = nums[3][i - 1], rt2 = nums[3][i + 1];
	}
	
	int ansl = 0, ansr = n;
	
	for (int i = 1; i < n; i ++)
	{
		if (nums[1][i] == lt1 || nums[1][i] == lt2) ansl = max(ansl, i);
		if (nums[1][i] == rt1 || nums[1][i] == rt2) ansr = min(ansr, i);
	}
	
	if (ansl == 0) cout << t << " ";
	for (int i = 1; i < n; i ++)
		if (i == ansl) cout << nums[1][i] << " " << t << " ";
		else cout << nums[1][i] << " ";
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
