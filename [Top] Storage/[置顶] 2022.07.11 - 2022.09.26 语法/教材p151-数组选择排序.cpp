#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k=i;
		for(int j=i+1;j<=n;j++)
		{
			if(a[k]>a[j]) k=j;//������Сֵ 
		}
		int temp;//��ű��滻��ֵ��
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
