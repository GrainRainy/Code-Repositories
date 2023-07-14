#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
const int M = N * 2;

int n, m, ans = N;
// ans ��̬ά����Сֵ 
int h[N], e[M], ne[M], idx;


bool st[N];

int dfs(int u)
// ������ u Ϊ���ڵ�����ӽڵ����� 
// u ��ʾ��ǰ�������ĵ� 
{
	st[u] = true;
	// ��������״̬
	
	int sum = 1, res = 0;
	// sum ά���� u Ϊ���ڵ���ӽڵ���� 
	// res ά��ɾ�� u �ڵ�����ͨ���нڵ���������ֵ 
	for (int i = h[u]; i != -1; i = ne[i])
	// ������ u ����ͷ�ڵ�ĵ����� 
	{
		int j = e[i];
		// ���ڴ洢ԭͼ������ĵ� 
		if (!st[j])
		// ����õ�û�б�������
		{
			int s = dfs(j);
			// �����õ�
			// s ά�� u ����ͨ�� �� i �������Ĵ�С
			res = max(res, s);
			// �Ե�ǰ�ڵ������ά�����ֵ 
			sum += s;
		}
	}
	
	res = max(res, n - sum);
	// �Գ�ȥ������������������ά��
	
	ans = min(ans, res);
	
	return sum; 
}

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n ;
	
	for (int i = 0; i < n - 1; i ++)
	// n ����, n - 1 ���� 
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	
	dfs(1);
	
	cout << ans << endl;
	
	return 0;
}
