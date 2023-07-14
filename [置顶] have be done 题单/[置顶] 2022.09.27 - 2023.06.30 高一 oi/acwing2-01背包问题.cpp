#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000;
int n, m;
// n ��ʾ������Ʒ�ĸ�����m ��ʾ��������
int v[N + 10], w[N + 10];
// v ��ʾ������Ʒ��ռ�������w ��ʾ������Ʒ�ļ�ֵ 
int f[N + 10][N + 10];
// ״̬ 

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> v[i] >> w[i];
	
	// for (int j = 0; j <= m; j ++) f[0][j] = 0;
	// һ����Ʒ����ѡ����ʡ�� 
	
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= m; j ++)
		{
			f[i][j] = f[i - 1][j];
			// ��ȡ i �����
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
			// �ܹ�װ�� i ʱȡ i ����� 
		}
		
	cout << f[n][m] << endl;
	return 0;
}
