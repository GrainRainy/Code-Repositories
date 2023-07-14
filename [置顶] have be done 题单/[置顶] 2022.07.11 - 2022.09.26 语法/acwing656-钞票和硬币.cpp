#include<bits/stdc++.h>
using namespace std;
int main()
{
	double m;
	cin>>m;
	int n=m*100;
	int p100,p50,p20,p10,p5,p2,c1,c2,c3,c4,c5,c6;
	p100=n/10000;
	n=n%10000;
	p50=n/5000;
	n=n%5000;
	p20=n/2000;
	n=n%2000;
	p10=n/1000;
	n=n%1000;
	p5=n/500;
	n=n%500;
	p2=n/200;
	n=n%200;
	c1=n/100;
	n=n%100;
	c2=n/50;
	n=n%50;
	c3=n/25;
	n=n%25;
	c4=n/10;
	n=n%10;
	c5=n/5;
	n=n%5;
	c6=n;
	cout<<"NOTAS:"<<endl;
	printf("%d nota(s) de R$ 100.00\n",p100);
	printf("%d nota(s) de R$ 50.00\n",p50);
	printf("%d nota(s) de R$ 20.00\n",p20);
	printf("%d nota(s) de R$ 10.00\n",p10);
	printf("%d nota(s) de R$ 5.00\n",p5);
	printf("%d nota(s) de R$ 2.00\n",p2);
	cout<<"MOEDAS:"<<endl;
	printf("%d moeda(s) de R$ 1.00\n",c1);
	printf("%d moeda(s) de R$ 0.50\n",c2);
	printf("%d moeda(s) de R$ 0.25\n",c3);
	printf("%d moeda(s) de R$ 0.10\n",c4);
	printf("%d moeda(s) de R$ 0.05\n",c5);
	printf("%d moeda(s) de R$ 0.01\n",c6);
	return 0;
 } 
