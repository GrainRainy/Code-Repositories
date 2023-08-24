#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, B = 110;

int n, m, gap;
int gaps[N], times[N], cnt1[N];
bool nums[N]; 

void change(int a, int b)
{
	for (int i = a; i <= min(gaps[a] * gap, b); i ++)
	{
		cnt1[gaps[a]] -= nums[i] ^ times[gaps[a]];
		nums[i] ^= 1;
		cnt1[gaps[a]] += nums[i] ^ times[gaps[a]];
	}
	if (gaps[a] != gaps[b])
		for (int i = (gaps[b] - 1) * gap + 1; i <= b; i ++)
		{
			cnt1[gaps[b]] -= nums[i] ^ times[gaps[b]];
			nums[i] ^= 1;
			cnt1[gaps[b]] += nums[i] ^ times[gaps[b]];
		}
	
	for (int i = gaps[a] + 1; i <= gaps[b] - 1; i ++)
	{
		times[i] ^= 1;
		cnt1[i] = gap - cnt1[i];
	}
}

void query(int a, int b)
{
	int res = 0;
	for (int i = a; i <= min(gaps[a] * gap, b); i ++)
		res += nums[i] ^ times[gaps[a]];
	if (gaps[a] != gaps[b])
		for (int i = (gaps[b] - 1) * gap + 1; i <= b; i ++)
			res += (nums[i] ^ times[gaps[b]]);
	
	for (int i = gaps[a] + 1; i <= gaps[b] - 1; i ++)
		res += cnt1[i];
		
	cout << res << endl;
	return;
}

int main()
{
	cin >> n >> m;
	gap = sqrt(n);
	for (int i = 1; i <= n; i ++)
		gaps[i] = (i - 1) / gap + 1;
	// init
	while (m --)
	{
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0) change(a, b);
		else query(a, b);
	}
	return 0;
}
