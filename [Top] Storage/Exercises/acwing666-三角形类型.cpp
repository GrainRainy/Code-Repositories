#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x,y,z;
	cin >> x >> y >> z;
	double maxxy = (x > y) ? x : y;
	double a = (maxxy > z) ? maxxy : z;
	double minxy = (x < y) ? x : y;
	double c = (minxy < z) ? minxy : z;
	double b = x + y + z - a - c;
	if (a >= b + c)
		cout << "NAO FORMA TRIANGULO" << endl;
	else
	{
		if (a * a == b * b + c * c) cout << "TRIANGULO RETANGULO" << endl;
		if (a * a > b * b + c * c) cout << "TRIANGULO OBTUSANGULO" << endl;
		if (a * a < b * b + c * c) cout << "TRIANGULO ACUTANGULO" << endl;
		if (a == b && b == c) cout << "TRIANGULO EQUILATERO" << endl;
		else if (a == b || b == c || c == a) cout << "TRIANGULO ISOSCELES" << endl;
	}
}
