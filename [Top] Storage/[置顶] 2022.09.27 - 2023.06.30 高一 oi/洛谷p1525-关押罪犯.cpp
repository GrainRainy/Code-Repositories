#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20000 + 10;
const int M = 1e5 + 10;

int n, m;
int father[N], foe[N];

struct relation
{
	int a, b, w;
	
	bool operator > (const relation &t) const
	{
		return w > t.w;
	}
}rela[M];

int find(int x)
{
	if (father[x] != x) father[x] = find(father[x]);
	return father[x];
}

void merge(int a, int b)
{
	int x = find(a), y = find(b);
	father[x] = y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
	{
		int tmpa, tmpb, tmpc;
		cin >> tmpa >> tmpb >> tmpc;
		rela[i] = {tmpa, tmpb, tmpc};
	}
	for (int i = 1; i <= n; i ++)
		father[i] = i;
	
	sort(rela + 1, rela + m + 1, greater<relation>());
	
	for (int i = 1; i <= m + 1;i ++)
	{
		int tmpa = find(rela[i].a), tmpb = find(rela[i].b);
		
		if (tmpa == tmpb) return (cout << rela[i].w << endl), 0;
		if (!foe[rela[i].a]) foe[rela[i].a] = rela[i].b;
		else merge(foe[rela[i].a], rela[i].b);
		if (!foe[rela[i].b]) foe[rela[i].b] = rela[i].a;
		else merge(foe[rela[i].b], rela[i].a);
	}
	return 0;
}
