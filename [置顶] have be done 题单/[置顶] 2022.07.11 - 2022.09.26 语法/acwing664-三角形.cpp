#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c;
	cin >> a >> b >> c;
	double maxab = (a > b) ? a : b;
	double maxabc = (maxab > c) ? maxab : c;
	if (a + b + c - maxabc > maxabc) 
		printf("Perimetro = %.1lf",a + b + c);
	else 
		printf("Area = %.1lf",(a + b) * c / 2);
	return 0;
}
