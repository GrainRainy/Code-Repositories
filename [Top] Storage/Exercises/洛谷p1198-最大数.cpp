#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10, J = 19;

int m, MOD;
int tmp;
int idx, nums[N];

int f[N][J]; // ST

void add(int n)
{
	nums[++ idx] = (n % MOD + tmp % MOD) % MOD;
	f[idx][0] = nums[idx];
	for (int i = 1; idx - (1 << i) >= 0; i ++)
		f[idx][i] = max(f[idx][i - 1], f[idx - (1 << i - 1)][i - 1]);
}

void ask(int n)
{
	if (n == 1)
	{
		tmp = nums[idx];
		tmp = nums[idx];
		cout << tmp << endl;
		return;
	}
	int l = idx - n + 1, r = idx, len = n;
	int k = log(len) / log(2);
	tmp = max(f[idx][k], f[l + (1 << k) - 1][k]);
	cout << tmp << endl;
	return;
}

signed main()
{
	cin >> m >> MOD;
	while (m --)
	{
		char op; int n;
		cin >> op >> n;
		if (op == 'A') add(n);
		else if (op == 'Q') ask(n);
	}
	return 0;
}
