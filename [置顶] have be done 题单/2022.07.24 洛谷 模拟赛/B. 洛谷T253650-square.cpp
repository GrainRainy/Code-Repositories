#include<bits/stdc++.h>
using namespace std;
double a[4];//�洢����֮�� 
int main()
{
	int n,k;
	cin >> n >> k;
	int cnt=1;
	for(int i = 1;i <= 4 * k;i++)
	{
		double r=n*pow(sqrt(2)/2,(i-1)/4);//�����α߳�
		a[cnt]+=r;
		cnt++;
		if(cnt == 4) cnt = 1;
	}
	for (int i=1;i<=3;i++)
		printf("%.3lf ",a[i]);
	return 0;
}
