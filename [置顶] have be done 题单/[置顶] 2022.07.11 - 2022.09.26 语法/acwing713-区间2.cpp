#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int x;
	int cnt = 0;
	int tot = 0;
	for (int i = 1;i <= n;i ++)
	{
		cin >> x;
		tot ++;
		if (x >= 10 && x <= 20)
			cnt ++;
	}
	cout << cnt << " in" << endl;
	cout << tot - cnt << " out" << endl;
	return 0;
}
