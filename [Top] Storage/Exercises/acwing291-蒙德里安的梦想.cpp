#include <iostream>
#include <cstring>
using namespace std;

const int N = 11;

int n, m;
long long f[N + 2][1 << N];
bool able[1 << N];

void judge()
{
	for (int i = 0; i < (1 << m); i ++)
	{
		bool flag = 0, cnt = 0;
		for (int j = 0; j < m; j ++)
			if ((i >> j) & 1) flag |= cnt, cnt = false;
			else cnt ^= 1;
		able[i] = flag | cnt ? 0 : 1;
	}
	return;
}

void solve()
{
	judge();
	f[0][0] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < (1 << m); j ++)
		{
			f[i][j] = 0;
			for (int k = 0; k < (1 << m); k ++)
				if (!(j & k) && able[j | k])
					f[i][j] += f[i - 1][k];
		}
	cout << f[n][0] << endl;
	memset(f, 0, sizeof f);
	return;
}

int main()
{
	while (cin >> n >> m && (n && m))
		solve();
	return 0;
}
