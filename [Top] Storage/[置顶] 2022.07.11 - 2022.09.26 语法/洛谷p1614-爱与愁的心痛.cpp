#include <bits/stdc++.h>

using namespace std;

int a[3005];

long long sum(int a[3005], int beginning, int m)
{
	long long ans = 0;
	for (int i = 0; i < m; i ++)
		ans += a[beginning + i];
	return ans;
}

int main()
{
	long long n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	
	long long min_ans = 1e11;
	for (int i = 0; i <= n - m; i ++)
	{
		if (sum(a, i, m) < min_ans)
			min_ans = sum(a, i, m);
	}
	cout << min_ans << endl;
	return 0;
}
