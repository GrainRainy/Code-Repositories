#include <iostream>

using namespace std;

const int N = 100000;
int ans[N + 10];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> ans[i];
	
	for (int i = 1; i <= n; i ++)
		ans[i] += ans[i - 1];
	
	while (m --)
	{
		int a, b;
		cin >> a >> b;
		cout << ans[b] - ans[a - 1] << endl;
	}
	
	return 0;
}
