#include <bits/stdc++.h>
using namespace std;

int a[1005];
int b[1000];//�洢�Ƿ���ֹ������� 
int getabaaba(int a[1005], int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i ++)
	{
		if (b[a[i]] == 0) cnt ++;
		b[a[i]] ++;
	}
	
	return cnt;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	printf("%d\n", getabaaba(a, n));
	return 0;
}
