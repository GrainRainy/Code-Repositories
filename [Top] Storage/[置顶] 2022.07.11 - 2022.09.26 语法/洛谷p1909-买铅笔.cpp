#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;//����Ǧ���� 
	int a,b;//��һ�ְ�װ 
	int c,d;//�ڶ��ְ�װ 
	int e,f;//�����ְ�װ
	int p1,p2,p3;//�۸� 
	cin>>n;
	cin>>a>>b>>c>>d>>e>>f;
	p1=ceil(n*1.0/a)*b;
	p2=ceil(n*1.0/c)*d;
	p3=ceil(n*1.0/e)*f;
	int k=(p1<p2)?p1:p2;
	int z=(k<p3)?k:p3;
	cout<<z;
	return 0;
}
