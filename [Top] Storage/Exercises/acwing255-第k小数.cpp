#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
using LL = long long;

const int N = 1e5 + 10;
const int M = 1e4 + 10;

int n, m;
int a[N];
vector<int> nums;

int root[N], idx;
struct SegmentTree
{
	int idxl, idxr;
	int cnt;
	
	#define idxl(x) tree[x].idxl
	#define idxr(x) tree[x].idxr
	#define cnt(x) tree[x].cnt
}tree[N * 4 + N * 17]; // 4n + nlogn

int find(int x)
{
	return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

int build(int l, int r)
{
	int cur = ++ idx; // start from 1
	if (l != r)
	{
		int mid = l + r >> 1;
		idxl(cur) = build(l, mid);
		idxr(cur) = build(mid + 1, r);
	}
	return cur;
}

int insert(int cur, int l, int r, int k)
{
//	cerr << "insert ------- " << l << " " << r  << " " << k << endl;
	int to = ++ idx;
	tree[to] = tree[cur];
	if (l == r) cnt(to) ++; // attention to this part 
	else
	{
		int mid = l + r >> 1;
		if (k <= mid) idxl(to) = insert(idxl(cur), l, mid, k);
		else idxr(to) = insert(idxr(cur), mid + 1, r, k);
		cnt(to) = cnt(idxl(to)) + cnt(idxr(to));
	}
	return to;
}

int query(int to, int cur, int l, int r, int k)
{
	
	if (l == r) return r;
	int cnt = cnt(idxl(to)) - cnt(idxl(cur));
//	cerr << "------- " << l << " " << r  << " " << to << " " << cnt << " " << k<< endl;
	int mid = l + r >> 1;
	if (k <= cnt) return query(idxl(to), idxl(cur), l, mid, k);
	else return query(idxr(to), idxr(cur), mid + 1, r, k - cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{ 
		cin >> a[i];
		nums.push_back(a[i]);
	}	
	// input
	
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	
//	root[0] = build(0, nums.size() - 1);
//	 insert(0, 0, nums.size() - 1, find(a[0]));
	
	for (int i = 1; i <= n; i ++)
		root[i] = insert(root[i - 1], 0, nums.size() - 1, find(a[i]));
	
	while (m --)
	{
		int l, r, k;
		cin >> l >> r >> k;
		cout << nums[query(root[r], root[l - 1], 0, nums.size() - 1, k)] << endl;
	}
	return 0;
}
