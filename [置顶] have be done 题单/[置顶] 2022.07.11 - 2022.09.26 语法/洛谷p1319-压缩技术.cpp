#include <bits/stdc++.h>
using namespace std;

int ans[40005];

int main()
{
	int n;
	cin >> n;
	int a, b;
	int cnt = 0;
	while (cin >> a >> b)
	{
		cnt += a;
		for (int i = cnt + 1; i <= cnt + b; i ++)
			ans[i] = 1;
		cnt += b;
	}
	
	int enter = 0;
	for (int i = 1; i <= n * n; i ++)
	{
		cout << ans[i];
		enter ++;
		if (enter % n == 0) cout << endl;
	}
	return 0;
}
