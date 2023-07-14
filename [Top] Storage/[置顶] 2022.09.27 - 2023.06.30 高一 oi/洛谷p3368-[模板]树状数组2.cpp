#include <iostream>
using namespace std;

const int N = 5e5 + 10;

int n, m;
int tree[N];
// 基本思路：维护差分数组 

int lowbit(int x)
{
	return x & -x;
}

void change(int l, int r, int k)
{
	for (int i = l; i <= n; i += lowbit(i))
		tree[i] += k;
	for (int i = r + 1; i <= n; i += lowbit(i))
		tree[i] -= k;
}

int query(int x)
{
	int res = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		res += tree[i];
	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		int tmp;
		cin >> tmp;
		change(i, i, tmp);
	}
	// input and init
	while (m --)
	{
		int op, x, y, k;
		cin >> op >> x;
		if (op == 1)
		{
			cin >> y >> k;
			change(x, y, k);
		}
		else cout << query(x) << endl;
	}
	return 0;
}
