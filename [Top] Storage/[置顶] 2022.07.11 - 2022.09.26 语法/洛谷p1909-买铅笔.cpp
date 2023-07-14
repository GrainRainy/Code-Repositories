#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;//总需铅笔数 
	int a,b;//第一种包装 
	int c,d;//第二种包装 
	int e,f;//第三种包装
	int p1,p2,p3;//价格 
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
