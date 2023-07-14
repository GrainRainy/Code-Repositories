#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N];
int size[N];
// ��ʾÿ�������е��������ֻ��֤���ڵ�� size ������ 

int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x]; 
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++) 
	{
		p[i] = i;
		size[i] = 1;
	}
	
	while (m --)
	{
		char op[2];
		int a, b;
		cin >> op;
		if (op[0] == 'C') 
		{
			cin >> a >> b;
			if (find(a) == find(b)) continue;
			size[find(b)] += size[find(a)];
			// �ںϲ����ϵ�ͬʱ����Ԫ�ظ���ͬʱ�ϲ� 
			p[find(a)] = find(b);
		}
		else if (op[1] == '1')
		{
			cin >> a >> b;
			if (find(a) == find(b)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else 
		{
			cin >> a;
			cout << size[find(a)] << endl;
		}
	}
	
	return 0;
}
