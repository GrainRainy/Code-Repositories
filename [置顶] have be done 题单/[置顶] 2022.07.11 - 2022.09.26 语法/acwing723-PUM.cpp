#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int cnt = 1;
	for (int i = 1;i <= n;i ++)
	{
		for (int j = 1;j <= m;j ++,cnt ++)
		{
			if (cnt % m == 0)
				cout << "PUM";
			else 
			cout << cnt << " ";
		}
		cout << endl;
	}
	return 0;
}
