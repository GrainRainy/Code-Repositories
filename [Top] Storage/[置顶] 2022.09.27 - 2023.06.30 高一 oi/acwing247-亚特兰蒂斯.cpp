#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define sonl (idx << 1)
#define sonr (idx << 1 | 1)
using LL = long long;

const int N = 1e5 + 10;
int n;
struct Segment
{
	double x, y1, y2;
	int k;
	
	bool operator < (const Segment t) const
	{
		return x < t.x;
	}
}seg[N << 1];

struct SegmentTree
{
	int l, r;
	int cnt;
	double len;
	
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define cnt(x) tree[x].cnt
	#define len(x) tree[x].len
}tree[N * 8];

vector<double> lis;

int find(double y)
{
	return lower_bound(lis.begin(), lis.end(), y) - lis.begin();
}

void pushup(int idx)
{
	if (cnt(idx)) len(idx) = lis[r(idx) + 1] - lis[l(idx)];
	else if (l(idx) != r(idx)) len(idx) = len(sonl) + len(sonr);
	else len(idx) = 0;
}

void build(int idx, int l, int r)
{
	tree[idx] = {l, r, 0, 0};
	if (l != r)
	{
		int mid = l + r >> 1;
		build(sonl, l, mid), build(sonr, mid + 1, r);
	}
}

void modify(int idx, int l, int r, int k)
{
	if (l(idx) > r or r(idx) < l) return;
	if (l(idx) >= l and r(idx) <= r)
	{
		cnt(idx) += k;
		pushup(idx);
		return;
	}
	modify(sonl, l, r, k), modify(sonr, l, r, k);
	pushup(idx);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int t = 1;
	while (cin >> n, n)
	{
		for (int i = 0, j = 0; i < n; i ++)
		{
			double x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			seg[j ++] = {x1, y1, y2, 1};
			seg[j ++] = {x2, y1, y2, -1};
			lis.push_back(y1), lis.push_back(y2);
		}
	
		sort(lis.begin(), lis.end());
		lis.erase(unique(lis.begin(), lis.end()), lis.end());
		
		sort(seg, seg + 2 * n);
		
		build(1, 0, lis.size() - 2);
		
		double ans = 0;
		for (int i = 0; i < 2 * n; i ++)
		{
			if (i > 0) ans += len(1) * (seg[i].x - seg[i - 1].x);
			modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
		}
		
	    printf("Test case #%d\n", t ++ );
	    printf("Total explored area: %.2lf\n\n", ans);
	}
	return 0;
}
