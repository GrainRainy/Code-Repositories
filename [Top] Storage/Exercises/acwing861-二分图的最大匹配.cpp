#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 1e5 + 10;

int n1, n2, m;

int h[N], idx;
struct node
{
	int val, nxt;
}edge[M];

int match[N];
// �洢�Ҳ�Ķ�Ӧ��ϵ 
bool st[N];
// �洢�Ƿ��ǹ��õ� 

void add(int a, int b)
{
	edge[++ idx].val = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

bool find(int x)
{
	for (int i = h[x]; i != -1; i = edge[i].nxt)
	{
		int t = edge[i].val;
		if (!st[t])
		{
			st[t] = true;
			if (match[t] == 0 || find(match[t]))
			// �Ҳ����� 
			{
				match[t] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	memset(h, -1, sizeof h);
	// init
	cin >> n1 >> n2 >> m;
	while (m --)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	// input
	int res = 0;
	// ��ǰƥ������
	for (int i = 1; i <= n1; i ++)
	{
		memset(st, false, sizeof st);
		if (find(i)) res ++;
	}
	cout << res << endl;
	return 0;
}
