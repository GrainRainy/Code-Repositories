#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N];
// father ���飬����ָ��ÿ���ڵ�ĸ��ڵ�

int find(int x)
// ���� x �ĸ��ڵ㣬ͬʱ����·��ѹ�� 
{
	if (p[x] != x)
	// ��� x ��Ϊ���ڵ� 
		p[x] = find(p[x]);
		// ���ϲ���ͬʱ�� x �ĸ��ڵ�ָ����ڵ� 
	
	return p[x];
	// ���� p[x] ��ʱ�ĸ��ڵ� ( ��Ϊ���ڵ� ) 
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++) p[i] = i;
	// ���鼯�ĳ�ʼ������ÿ���ڵ�ĸ��ڵ�ָ���Լ�
	
	while (m --)
	{
		char op[2];
		int a, b;
		cin >> op >> a >> b;
		if (op[0] == 'M') 
			p[find(a)] = find(b);
			// ���� a �� b �ĸ��ڵ�
			//ͬʱ�� a ���ڼ��ϵĸ��ڵ�ָ�� b ���ڼ��ϵĸ��ڵ� 
		else
		{
			if (find(a) == find(b)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	
	return 0;
}
