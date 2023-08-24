#include <iostream>

using namespace std;

int main()
{
	int tmp = 0, n, t;
	cin >> n;
	int WA = 0;
	int cnt = 0;
	for (int i = 1 ;i < n; i ++)
	{
		cin >> t;
		if (tmp > t) WA = 1;
		if (tmp < t && WA)
		{
			cnt ++;
			WA = 0;
		}
		tmp = t;
	}
	cout << cnt << endl;
	return 0;
}
