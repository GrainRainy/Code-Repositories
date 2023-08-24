#include <iostream>

using namespace std;

const int N = 100000;
int a[N + 10];
int s[N + 10];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	
	int res = 0;
	for (int i = 0, j = 0; i < n; i ++)
	{
		s[a[i]] ++;
		while (s[a[i]] > 1)
		{
			s[a[j]] --;
			j ++;
		}
		res = max(res, i - j + 1);
	}
	
	cout << res << endl;
	return 0;
}
