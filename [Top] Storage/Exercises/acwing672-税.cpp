#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n;
	cin >> n;
	double shui;
	if (n >= 0 && n <= 2000) 
	{
		cout << "Isento";
		return 0;
	}
	else if (n >= 2000.01 && n <= 3000)
		shui = (n - 2000) * 0.08;
	else if (n >= 3000.01 && n <= 4500)
		shui = 80 + (n - 3000) * 0.18;
	else 
		shui = 80 + 270 + (n - 4500) * 0.28;
	printf("R$ %.2lf\n",shui);
	return 0;
}
