#include <iostream>
#define int long long
#define sonl (idx << 1)
#define sonr (idx << 1 | 1)
using namespace std;

const int N = 1e5 + 10;

int n, m, MOD;
int nums[N];

struct SegmentTree
{
	int l, r, val;
	int add, mul = 1;
	
	#define l(x) (tree[(x)].l)
	#define r(x) (tree[(x)].r)
	#define val(x) (tree[(x)].val)
	#define add(x) (tree[(x)].add)
	#define mul(x) (tree[(x)].mul)
}tree[N << 2];

void build(int idx, int l, int r)
{
	l(idx) = l, r(idx) = r;
	if (l == r) return val(idx) = nums[l], void();
	
	int mid = l + r >> 1;
	build(sonl, l, mid);
	build(sonr, mid + 1, r);
	val(idx) = val(sonl) + val(sonr);
}

void spread(int idx)
{
	if (mul(idx) != 1)
	{
		mul(sonl) = mul(sonl) * mul(idx) % MOD;
		add(sonl) = add(sonl) * mul(idx) % MOD;
		val(sonl) = val(sonl) * mul(idx) % MOD;
		mul(sonr) = mul(sonr) * mul(idx) % MOD;
		add(sonr) = add(sonr) * mul(idx) % MOD;
		val(sonr) = val(sonr) * mul(idx) % MOD;
		mul(idx) = 1;
	}
	if (add(idx))
	{
		add(sonl) = (add(sonl) + add(idx)) % MOD;
		val(sonl) = (val(sonl) + 1ll * (r(sonl) - l(sonl) + 1) * add(idx)) % MOD;
		add(sonr) = (add(sonr) + add(idx)) % MOD;
		val(sonr) = (val(sonr) + 1ll * (r(sonr) - l(sonr) + 1) * add(idx)) % MOD;
		add(idx) = 0;
	}
}

void change(int idx, int l, int r, int k, int op)
// add when op == 2, multiply when op == 1
{
	if (l(idx) > r || r(idx) < l) return;
	if (l <= l(idx) && r >= r(idx))
	{
		if (op == 2)
		{
			add(idx) = (add(idx) + k) % MOD;
			val(idx) = (val(idx) + 1ll * (r(idx) - l(idx) + 1) * k) % MOD;
		}
		else
		{
			mul(idx) = mul(idx) * k % MOD;
			add(idx) = add(idx) * k % MOD;
			val(idx) = val(idx) * k % MOD;
		}
		return;
	}
	spread(idx);
	change(sonl, l, r, k, op);
	change(sonr, l, r, k, op);
	val(idx) = val(sonl) + val(sonr);
}

int query(int idx, int l, int r)
{
	if (l(idx) > r || r(idx) < l) return 0;
	if (l <= l(idx) && r >= r(idx)) return val(idx);
	spread(idx);
	return (query(sonl, l, r) + query(sonr, l, r)) % MOD;
}

signed main()
{
	cin >> n >> m >> MOD;
	for (int i = 1; i <= n; i ++)
		cin >> nums[i];
	
	build(1, 1, n);
	
	while (m --)
	{
		int op, x, y, k;
		cin >> op >> x >> y;
		if (op == 1)
		{
			cin >> k;
			change(1, x, y, k, op);
		}
		else if (op == 2)
		{
			cin >> k;
			change(1, x, y, k, op);
		}
		else cout << query(1, x, y) << endl;
	}
	return 0;
}
