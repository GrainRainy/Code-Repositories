#include <iostream>
#define int long long
#define sonl (idx << 1)
#define sonr (idx << 1 | 1)
#define l(x) (tree[x].l)
#define r(x) (tree[x].r)
#define val(x) (tree[x].val)
using namespace std;

const int N = 4e5;

int n, m;
int nums[N], lazy[N << 2];

struct segmentTree
{
	int l, r;
	int val;
}tree[N << 2];

void build(int idx, int l, int r)
{
	tree[idx].l = l, tree[idx].r = r;
	if (l == r) return tree[idx].val = nums[l], void();
	
	int mid = l + r >> 1;
	build(sonl, l, mid), build(sonr, mid + 1, r);
	tree[idx].val = tree[sonl].val + tree[sonr].val;
	return ;
}

void push_up(int idx)
{
	tree[idx].val = tree[sonl].val + tree[sonr].val;
}

void push_down(int idx)
{
	int l = tree[idx].l, r = tree[idx].r;
	
	lazy[sonl] += lazy[idx];
	lazy[sonr] += lazy[idx];
	
	int mid = l + r >> 1;
	tree[sonl].val += (mid - l + 1) * lazy[idx];
	tree[sonr].val += (r - mid) * lazy[idx];
	lazy[idx] = 0;
}

void change(int idx, int l, int r, int v)
{
	// if (tree[idx].l > r || tree[idx].r < l) return;
	if (l <= tree[idx].l && r >= tree[idx].r)
	{
		lazy[idx] += v;
		tree[idx].val += (tree[idx].r - tree[idx].l + 1) * v;
		return;
	}
	push_down(idx);
	int mid = tree[idx].l + tree[idx].r >> 1;
	if (l <= mid) change(sonl, l, r, v);
	if (r > mid) change(sonr, l, r, v);
	push_up(idx);
}

int query(int idx, int l, int r)
{
	if (tree[idx].l > r || tree[idx].r < l) return 0;
	if (tree[idx].l >= l && tree[idx].r <= r) return tree[idx].val;
	push_down(idx);
	int mid = tree[idx].l + tree[idx].r >> 1;
	return query(sonl, l, r) + query(sonr, l, r);
}

signed main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> nums[i];
	build(1, 1, n);
	// input and init
	while (m --)
	{
		int op, x, y, k;
		cin >> op >> x >> y;
		if (op == 1)
		{
			cin >> k;
			change(1, x, y, k);
		}
		else cout << query(1, x, y) << endl;
	}
}
