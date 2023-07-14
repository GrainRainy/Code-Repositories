#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c;
	cin >> a >> b >> c;
	double r1,r2;
	if (a == 0 || b * b - a * 4 * c < 0)
	{
		cout << "Impossivel calcular" << endl;
		return 0; 
	}
	else 
	{
		r1 = (-b + sqrt(b * b - 4 * a * c) * 1.0)/(2 * a);
		r2 = (-b - sqrt(b * b - 4 * a * c) * 1.0)/(2 * a);
	}
	printf("R1 = %.5lf\nR2 = %.5lf\n",r1,r2);
	return 0;
}
