#include <iostream>

using namespace std;

int lowbit(int x)
{
	return x & -x;
}

int main()
{
	int n;
	cin >> n;
	while (n --)
	{
		int x;
		cin >> x;
		int cnt = 0;
		while (x)
		{
			x -= lowbit(x);
			cnt ++;
		}
		cout << cnt << " ";
	}
}
