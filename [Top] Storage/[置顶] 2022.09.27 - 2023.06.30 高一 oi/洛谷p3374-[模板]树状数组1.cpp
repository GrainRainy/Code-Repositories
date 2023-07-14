#include <iostream>
using namespace std;

const int N = 5e5 + 10;

int n, m;
int tree[N];

int lowbit(int x)
{
	return x & -x;
}

void change(int x, int k)
{
	for (int i = x; i <= n; i += lowbit(i))
		tree[i] += k;
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
		change(i, tmp);
	}
	// input and init
	
	while (m --)
	{
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 1) change(a, b);
		else cout << query(b) - query(a - 1) << endl;
	}
	return 0;
}
