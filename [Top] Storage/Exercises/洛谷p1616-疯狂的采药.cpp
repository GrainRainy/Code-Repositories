#include <iostream>

using namespace std;

const int N = 1e7 + 10;
const int ITEMS = 1e4 + 10;

// typedef long long LL;

int n, m;
long long v[ITEMS], w[ITEMS];
long long f[N];

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i ++)
		cin >> v[i] >> w[i];
	
	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= m; j ++)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		
	cout << f[m] << endl;
	
	return 0;
}
