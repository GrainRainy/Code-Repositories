#include <iostream>
using namespace std;

const int N = 5e4;

int n, k;
int father[N * 3];

int find(int x)
{
	if (father[x] != x) father[x] = find(father[x]);
	return father[x];
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= 3 * n; i ++)
		father[i] = i;
	
	int ans = 0;
	while (k --)
	{
		int op, x ,y;
		cin >> op >> x >> y;
		if (x > n || y > n) ans ++;
		else if(op == 1)
		{
			if (find(x + n) == find(y) || find(x) == find(y + n))
				ans ++;
			else
			{
				father[find(x)] = find(y);
				father[find(x + n)] = find(y + n);
				father[find(x + n + n)] = find (y + n + n);
			}
		}
		else
		{
			if (find(x) == find(y) || find(x) == find(y + n)) ans ++;
			else
			{
				father[find(x)] = find(y + n + n);
				father[find(x + n)] = find(y);
				father[find(x + n + n)] = find(y + n);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
