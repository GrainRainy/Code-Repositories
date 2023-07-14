#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

long long n, x;
long long lose[N], win[N], use[N];
long long f[N];

int main()
{
	cin >> n >> x;
	for (int i = 1; i <= n; i ++)
		scanf("%lld %lld %lld", &lose[i], &win[i], &use[i]);
	
	for (int i = 1; i <= n; i ++)
		for (int j = x; j >= 0; j --)
			{
				if (j < use[i])
					f[j] = f[j] + lose[i];
				else
					f[j] = max(f[j] + lose[i], f[j - use[i]] + win[i]);
			}

	cout << 5 * f[x] << endl;

	return 0;
}

/*
6 8
21 52 1
21 70 5
21 48 2
14 38 3
14 36 1
14 36 2

1060

*/
