#include <bits/stdc++.h>
#define lson ((idx) << 1)
#define rson ((idx) << 1 | 1)
using namespace std;

const int N = 5e5 + 10;

int n, m;

struct SegmentTree
{
	int len;
	int val, lval, rval;
	int lazy;
	// 0 means nothing to do
	// 1 refers to ¿ª·¿ 
	// 2 refers to ÍË·¿ 
	
	#define len(x) (tree[(x)].len)
	#define val(x) (tree[(x)].val)
	#define lval(x) (tree[(x)].lval)
	#define rval(x) (tree[(x)].rval)
	#define lazy(x) (tree[(x)].lazy)
}tree[N << 2];

void build(int idx, int l, int r)
{
	val(idx) = lval(idx) = rval(idx) = len(idx) = r - l + 1;
	if (l == r) return;
	
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
}

void spread(int idx)
{
	if (lazy(idx) == 1)
	{
		lazy(lson) = lazy(rson) = 1, lazy(idx) = 0;
		val(lson) = lval(lson) = rval(lson) = 0;
		val(rson) = lval(rson) = rval(rson) = 0;
	}
	if (lazy(idx) == 2)
	{
		lazy(lson) = lazy(rson) = 2, lazy(idx) = 0;
		val(lson) = lval(lson) = rval(lson) = len(lson);
		val(rson) = lval(rson) = rval(rson) = len(rson);
	}
}

void push_up(int idx)
{
	if (lval(lson) == len(lson)) lval(idx) = len(lson) + lval(rson);
	else lval(idx) = lval(lson);
	if (rval(rson) == len(rson)) rval(idx) = len(rson) + rval(lson);
	else rval(idx) = rval(rson);
	val(idx) = max(max(val(lson), val(rson)), rval(lson) + lval(rson));
}

void change(int idx, int tl, int tr, int l, int r, int type)
{
	spread(idx);
	if (l <= tl && r >= tr)
	{
		if (type == 1) val(idx) = lval(idx) = rval(idx) = 0;
		else val(idx) = lval(idx) = rval(idx) = len(idx);
		lazy(idx) = type;
		return;
	}
	
	int mid = tl + tr >> 1;
	if (l <= mid) change(lson, tl, mid, l, r, type);
	if (r > mid) change(rson, mid + 1, tr, l, r, type);
	push_up(idx);
}

int query(int idx, int tl, int tr, int length)
{
	spread(idx);
	if (tl == tr) return tl;
	
	int mid = tl + tr >> 1;
	if (val(lson) >= length) return query(lson, tl, mid, length);
	if (rval(lson) + lval(rson) >= length) return mid - rval(lson) + 1;
	else return query(rson, mid + 1, tr, length);
}

int main()
{
	cin >> n >> m;
	build(1, 1, n);
	
	while (m --)
	{
		int op, x, y;
		cin >> op >> x;
		if (op == 1)
		{
			if (val(1) >= x)
			{
				int tmp = query(1, 1, n, x);
				change(1, 1, n, tmp, tmp + x - 1, 1);
				cout << tmp << endl;
			}
			else cout << 0 << endl;
		}
		else
		{
			cin >> y;
			change(1, 1, n, x, x + y - 1, 2);
		}
	}
}
