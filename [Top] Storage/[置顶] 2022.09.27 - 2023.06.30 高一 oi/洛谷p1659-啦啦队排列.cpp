#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int N = 1e6 + 100;
const int MOD = 19930726;

int n, k;
int p[N << 1];
char input[N], s[N << 1];
int cnt[N << 1];

int fast_pow(int x, int y)
{
	if (x == 1) return 1;
	int ans = 1, base = x;
	while (y)
	{
		if (y & 1) ans = ans *  base % MOD;
		base = base * base % MOD;
		y >>= 1;
	}
	return ans;
} 

void init()
{
	int idx = 0;
	s[idx ++] = '$', p[idx ++] = '#';
	for (int i = 0; i < n; i ++)
		s[idx ++] = input[i], p[idx ++] = '#';
	p[idx ++] = '^';
	n = idx;
}

void manacher()
{
	int mr = 0, mid = 0;
	for (int i = 1; i < n; i ++)
	{
		if (i < mr) p[i] = min(mr - i, p[2 * mid - i]);
		else p[i] = 1;
		while (s[i + p[i]] == s[i - p[i]]) p[i] ++;
		if (i + p[i] > mr) mr = i + p[i], mid = i;
		if ((p[i] - 1) & 1) cnt[p[i] - 1] ++;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> k;
	cin >> input;
	init();
	manacher();
	
	int sum = 0, ans = 1;
	for (int i = strlen(input); i >= 1; i --)
	{
		if (!(i & 1)) continue;
		sum += cnt[i];
		if (k >= sum) ans = ans * fast_pow(i, sum) % MOD;
		else
		{
			ans = ans * fast_pow(i, k) % MOD;
			k = 0;
			break;
		}
		k -= sum;
	}
	if (k > 0) ans = -1;
	cout << ans << endl;
	return 0;
}
