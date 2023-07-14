#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e5 + 10;
int ary[N];
int st[N];

void solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	int sum = (n + 1) * n / 2;
	int smaller_sum = (1 + n / 2) * n / 4;
	int bigger_sum = sum - smaller_sum;
	
	if (a + b > sum || max(a, b) > bigger_sum)
		return cout << "-1" << endl, void();
	// нч╫Беп╤╗ 
	
	if (a <= b)
	{
		if (smaller_sum >= a)
			for (int i = 1; i <= n; i ++)
				ary[i] = i;
		else
		{
			for (int i = 1; i <= n / 2; i ++)
			{
				ary[i] = i + (a - smaller_sum) / (n / 2);
				st[ary[i]] ++;
			}
			for (int i = n / 2 - ((a - smaller_sum) % (n / 2)) + 1; i <= n / 2; i ++)
			{
				st[ary[i]] --;
				ary[i] ++;
				st[ary[i]] ++;
			}
			
			int idx = n / 2 + 1;
			for (int i = 1; i <= n; i ++)
				if (!st[i]) ary[idx ++] = i;
		}
	}
	else
	{
		if (smaller_sum >= b)
			for (int i = 1; i <= n; i ++)
				ary[i] = n - i + 1;
		else
		{
			for (int i = 1; i <= n / 2; i ++)
			{
				ary[n / 2 + i] = i + (b - smaller_sum) / (n / 2);
				st[ary[n / 2 + i]] ++;
			}
			for (int i = n - ((a - smaller_sum) % (n / 2)) + 1; i <= n; i ++)
			{
				st[ary[i]] --;
				ary[i] ++;
				st[ary[i]] ++;
			}
			
			int idx = 1;
			for (int i = 1; i <= n; i ++)
				if (!st[i]) ary[idx ++] = i;
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		cout << ary[i] << " ";
		ary[i] = st[i] = 0;
	}
	cout << endl;
	return;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
