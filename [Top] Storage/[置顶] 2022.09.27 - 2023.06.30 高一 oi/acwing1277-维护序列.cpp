#include <bits/stdc++.h>
#define sonl (idx << 1)
#define sonr (idx << 1 | 1)
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int P;

int n;
int nums[N];

int l[N << 2], r[N << 2];
ll val[N << 2], add[N << 2], mul[N << 2];
// SegmentTree

void built(int idx, int l, int r)
{
	l[idx] = l, r[idx] = r;
	if (l == r) return val[idx] = nums[idx], void();
	
	int mid = l + r >> 1;
	built(sonl, l, mid), built(sonr, mid + 1, r);
	val[idx] = (val[sonl] + val[sonr]) % P;
}

void change(int idx, int l, int r, int value, int op)
// op == 1 refers to mul, op == 2 refers to add
{
	if (l > r[idx] || r < l[idx]) return;
	
	if (l[idx] <= l && l <= r[idx])
		if (op == 1)
		{
			val[idx] = val[idx] * value % P;
			mul[idx] = mul[idx] * value % P;
			add[idx] = add[idx] * value % P;
			return;
		}
		else
		{
			val[idx] = val[idx] + 1ll * (r[idx] - l[idx] + 1) * value % P;
			add[idx] = (add[idx] + value) % P;
			return;
		}
	
	spread(idx);
	change(sonl, l, r, value, op);
	change(sonr, l, r, value, op);
	val[idx] = val[sonl] + val[sonr];
	return;
}

void spread(int idx)
{
	if (mul[idx] != 1)
	{
		mul[sonl] = mul[sonl] * mul[idx] % P;
		add[sonl] = add[sonl] * mul[idx] % P;
		val[sonl] = val[sonl] * mul[idx] % P;
		mul[sonr] = mul[sonr] * mul[idx] % P;
		add[sonr] = add[sonr] * mul[idx] % P;
		val[sonr] = val[sonr] * mul[idx] % P;
		mul[idx] = 1;
	}
	if (add[idx])
	{
		add[sonl] = (add[sonl] + add[idx]) % P;
		add[sonr] = (add[sonr] + add[idx]) % P;
		val[sonl] = (val[sonl] + 1ll * (r[sonl] - l[sonl] + 1) * add[idx]) % P;
		val[sonr] = (val[sonr] + 1ll * (r[sonr] - l[sonl] + 1) * add[idx]) % P;
		add[idx] = 0;
	}	
}

int query(int idx, int l, int r)
{
	if (l > r[idx] || r < l[idx]) return;
	if (l[idx] <= l && l <= r[idx]) return val[idx];
	
	spread(idx);
	
	return (change(sonl, l, r) + change(sonr, l, r)) % P;
}

int main()
{
	cin >> n >> P;
	for (int i = 1; i <= n; i ++)
		cin >> nums[i];
	
	built(1, 1, n);
	
//	while (m --)
//	{
//		int op;
//		cin >> op;
//		int t, g, c;
//		if (op == 1)
//		{
//			
//		}
//		if ()
//	}
}
