#include <bits/stdc++.h>
template <typename T>
void input(T &x)
{
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
typedef long long LL;
using namespace std;

const int N = 2e5 + 10;
const long long MOD = 998244353;
int n, q;
string s;

int odd_idx, even_idx;
LL hash_odd[N], hash_even[N];
LL p[N];
int cnt0[N];

int count0(int l, int r)
{
	return cnt0[r] - cnt0[l - 1];
}

void init_pow()
{
	p[0] = 1;
	for (int i = 1; i <= n; i ++)
		p[i] = (1ll * p[i - 1] << 1) % MOD;
}

void init_strings()
{
	odd_idx = 1, even_idx = 2;
	for (int i = 1; i <= n; i ++)
	{
		if (s[i] == '0')
		{
			cnt0[i] = cnt0[i - 1] + 1;
			hash_odd[i] = ((1ll * hash_odd[i - 1] << 1) % MOD + odd_idx) % MOD;
			hash_even[i] = ((1ll * hash_even[i - 1] << 1) % MOD + even_idx) % MOD;
		}
		else
		{
			cnt0[i] = cnt0[i - 1];
			hash_odd[i] = hash_odd[i - 1];
			hash_even[i] = hash_even[i - 1];
		}
		odd_idx = (odd_idx == 1) ? 2 : 1;
		even_idx = (even_idx == 1) ? 2 : 1;
	}
}

bool judge_hash(int l1, int l2, int len)
{	
	int cnt1 = count0(l1, l1 + len - 1);
	int cnt2 = count0(l2, l2 + len - 1);
	if ((l1 & 1) != (l2 & 1))
	{
		int tmphash1 = (hash_odd[l1 + len - 1] - 1ll * hash_odd[l1 - 1] * p[cnt1] % MOD + MOD) % MOD;
		int tmphash2 = (hash_even[l2 + len - 1] - 1ll * hash_even[l2 - 1] * p[cnt2] % MOD + MOD) % MOD;
		return (cnt1 == cnt2 && tmphash1 == tmphash2);
	}
	else
	{
		int tmphash1 = (hash_odd[l1 + len - 1] - 1ll * hash_odd[l1 - 1] * p[cnt1] % MOD + MOD) % MOD;
		int tmphash2 = (hash_odd[l2 + len - 1] - 1ll * hash_odd[l2 - 1] * p[cnt2] % MOD + MOD) % MOD;
		return (cnt1 == cnt2 && tmphash1 == tmphash2);
	}
}

signed main()
{
	input(n); cin >> s; input(q);
	s = "0" + s;
	init_strings(), init_pow();
	while (q --)
	{
		int l1, l2, len;
		input(l1), input(l2), input(len);
		if (judge_hash(l1, l2, len))
			puts("Yes");
		else puts("No");
	}
	return 0;
}
