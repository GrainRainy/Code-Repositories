#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n;
int a[N];
int f[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i ++)
	{
		f[i] = 1;
		// ���������������Ϊ 1 ,��Ϊ��ǰ��
		for (int j = 1; j <= i - 1; j ++)
			if (a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
	}
	
	int res = -1e9;
	for (int i = 1; i <= n; i ++)
		res = max(res, f[i]);
	
	cout << res << endl;
	
	return 0;
}
