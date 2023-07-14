#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n;
	cin >> n;
	double ics;//涨工资的价格 
	int a;//涨幅% 
	if (n >= 0 && n <= 400)
	{
		ics = n * 0.15;
		a = 15;
	}
	else if (n >= 400.01 && n <= 800)
	{
		ics = n * 0.12;
		a = 12;
	}
	else if (n >= 800.01 && n <= 1200)
	{
		ics = n * 0.1;
		a = 10;
	}
	else if (n >= 1200.01 && n <= 2000)
	{
		ics = n * 0.07;
		a = 7;
	}
	else
	{
		ics = n * 0.04;
		a = 4;
	}
	printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d",n + ics,ics,a);
	cout << " %";
	return 0;
}
