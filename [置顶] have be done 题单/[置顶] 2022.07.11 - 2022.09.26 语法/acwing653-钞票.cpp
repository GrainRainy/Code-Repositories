#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	m=n;
	int p100,p50,p20,p10,p5,p2,p1;
	p100=n/100;
	n=n%100;
	p50=n/50;
	n=n%50;
	p20=n/20;
	n=n%20;
	p10=n/10;
	n=n%10;
	p5=n/5;
	n=n%5;
	p2=n/2;
	n=n%2;
	p1=n;
	cout<<m<<endl;
	printf("%d nota(s) de R$ 100,00\n",p100);
	printf("%d nota(s) de R$ 50,00\n",p50);
	printf("%d nota(s) de R$ 20,00\n",p20);
	printf("%d nota(s) de R$ 10,00\n",p10);
	printf("%d nota(s) de R$ 5,00\n",p5);
	printf("%d nota(s) de R$ 2,00\n",p2);
	printf("%d nota(s) de R$ 1,00\n",p1);
	return 0;
 } 
