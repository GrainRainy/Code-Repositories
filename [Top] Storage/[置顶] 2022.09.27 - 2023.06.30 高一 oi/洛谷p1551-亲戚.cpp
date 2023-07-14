#include <iostream>

using namespace std;

int n, m, p;
int father[5010]; 

int find(int u)
{
	if (father[u] != u) return find(father[u]);
	else return u;
}



int main()
{
	cin >> n >> m >> p;
	
	for (int i = 0; i < n; i ++)
		father[i] = i;
	for (int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		int tmp1 = find(x);
		int tmp2 = find(y);
		if (tmp1 != tmp2) father[tmp1] = tmp2;
	}
	
	for (int i = 0; i < p; i ++)
	{
		int x, y;
		cin >> x >> y;
		if(find(x) != find(y)) puts("No");
		else puts("Yes");
	}
	return 0;
}
