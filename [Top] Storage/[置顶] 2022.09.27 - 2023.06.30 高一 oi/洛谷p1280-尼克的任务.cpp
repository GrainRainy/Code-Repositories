#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

int f[N], cnt = 1, be[N];
// be[] ��ʾ��ǰλ���Ƿ��������Լ��ж��ٸ����� 
struct tasks
{
	int bg,tm;
	
	bool operator < (const tasks &a) const 
	{
		return bg > a.bg;
	}
	// ��Ϊ�ǴӺ���ǰɨ�����԰��ս������� 
}tot[N];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i ++)
	{
		cin >> tot[i].bg >> tot[i].tm;
		be[tot[i].bg] ++;
	}
	// input
	
	sort(tot + 1, tot + k + 1);
	
	for (int i = n; i >= 1; i --)
	{
		if (!be[i]) f[i] = f[i + 1] + 1;
		else
			for (int j = 1; j <= be[i]; j ++)
			{
				f[i] = max(f[i], f[i + tot[cnt].tm]);
				// cnt ��Ϊ�������жϵ�ǰ�������ĸ����� 
				cnt ++;
			}
	}
	
	cout << f[1] << endl;
	// ��Ϊ�ǴӺ���ǰ������������� f[1] ���� 
	
	return 0;
}
