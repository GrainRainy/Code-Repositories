#include <iostream>

using namespace std;

const int N = 310;
const int INF = 1e8;

int n;
int s[N], f[N][N];
// s �洢ǰ׺��
 
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> s[i];
	// input
	for (int i = 2; i <= n; i ++) s[i] += s[i - 1];
	// ����ǰ׺��
	
	for (int len = 2; len <= n; len ++)
	// ö�ٴ��ϲ������䳤��
		for (int i = 1; i + len - 1 <= n; i ++)
		// ö�����䳤�� 
		{
			int l = i, r = i + len - 1;
			//  ȡ����ʼλ�� 
			f[l][r] = INF;
			// ��ʼ��һ�����ֵ��ѭ���ҳ���Сֵ 
			for (int k = l; k < r; k ++)
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
				// ���ϲ�����ķֽ��߷���ö�� 
		}
	cout << f[1][n] << endl;
	
	return 0; 
	
}
