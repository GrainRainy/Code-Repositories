#include <iostream>

using namespace std;

const int N = 1e5, M = 1e6;
// N Ϊģ�崮���ȣ�M Ϊģʽ������ 
char p[N + 10], s[M + 10];
// p Ϊ�Ӵ���s Ϊ���� 
int ne[N + 10];
// �Ӵ� p �� next ���� 
int n, m;
// �Ӵ����� n ���������� m  

int main()
{
	cin >> n >> p + 1 >> m >> s + 1;
	// ���Ӵ��������� 1 ��ʼ���� 
	
	for (int i = 2, j = 0; i <= n; i ++)
	{
		while (j && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j ++;
		ne[i] = j;
	}
	// ���Ӵ��� next ���� 
	
	for (int i = 1, j = 0; i <= m; i ++)
	{
		while (j && s[i] != p[j + 1]) j = ne[j];
		if (s[i] == p[j + 1]) j ++;
		if (j == n)
		{
			printf("%d ", i - n);
			// ƥ��ɹ���������ִ�в��� 
			
			j = ne[j];
			// �������е�ƥ����� 
		}
	}
	// ���� KMP ƥ��Ĺ��� 
	return 0;
}
