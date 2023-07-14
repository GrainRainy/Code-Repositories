#include<bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x>=0&&x<=18) a[1]++;
		else if (x>=19&&x<=35) a[2]++;
		else if (x>=36&&x<=60) a[3]++;
		else if (x>=61) a[4]++;
	}
	//cout<<a[1]<<endl<<a[2]<<endl<<a[3]<<endl<<a[4]<<endl;
	double ans1=a[1]*1.0/n*100;
	double ans2=a[2]*1.0/n*100;
	double ans3=a[3]*1.0/n*100;
	double ans4=a[4]*1.0/n*100;
	printf("%.2lf%\n%.2lf%\n%.2lf%\n%.2lf%\n",ans1,ans2,ans3,ans4);
	return 0;
}
