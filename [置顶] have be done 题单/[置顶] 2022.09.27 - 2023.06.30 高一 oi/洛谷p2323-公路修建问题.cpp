#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;
const int M = 2e4 + 10;

int n, k, m;
int sum; // 存储所有边之和 

int fa[N];
int find(int x)
{
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int idx1;
struct node
{
	int a, b, w1, w2;
	int num;
}edge[M];

int idx2;
struct output
{
	int nums;
	int level;
}ans[M];

void add1(int a, int b, int c1, int c2, int num)
{
	edge[++ idx1] = {a, b, c1, c2, num};
}

bool cmp1(node &a, node &b)
{
	return a.w1 < b.w1;
}
bool cmp2(node &a, node &b)
{
	return a.w2 < b.w2;
}
bool cmpans(output &a, output &b)
{
	return a.nums < b.nums;
}

void kruskal1()
{
	sort(edge, edge + m, cmp1);
	
	int cnt = 0;
	for (int i = 1; i < m; i ++)
	{
		int p = find(edge[i].a), q = find(edge[i].b);
		if (p != q)
		{
			fa[p] = q;
			sum = max(sum, edge[i].w1);
			ans[++ idx2]  = {edge[i].num, 1};
			cnt ++;
		}
		if (cnt == k) return;
	}
}

void kruskal2()
{
	sort(edge, edge + m, cmp2);
	
	int cnt = 0;
	for (int i = 1; i < m; i ++)
	{
		int p = find(edge[i].a), q = find(edge[i].b);
		if (p != q)
		{
			fa[p] = q;
//			if (sum >= edge[i].w1)
//				ans[++ idx2]  = {edge[i].num, 1};
//			else
//			{
				sum = max(sum, edge[i].w2);
				ans[++ idx2]  = {edge[i].num, 2};
//			}
				
		}
		if (cnt == n - k - 1) return;
	}
}

int main()
{
	cin >> n >> k >> m;
	for (int i = 1; i < m; i ++)
	{
		int a, b, c1, c2;
		cin >> a >> b >> c1 >> c2;
		add1(a, b, c1, c2, i);
	}
	for (int i = 1; i <= n; i ++)
		fa[i] = i;
	// init
	
	kruskal1(), kruskal2();
	
	cout << sum << endl;
	
	sort(ans + 1, ans + idx2 + 1, cmpans);
	
	for (int i = 1; i <= idx2; i ++)
		cout << ans[i].nums << " " << ans[i].level << endl;
	
	return 0;
}
