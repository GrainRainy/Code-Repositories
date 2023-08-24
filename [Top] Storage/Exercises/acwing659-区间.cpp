#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n;
	cin >> n;
	if (n >= 0 && n <= 25) cout << "Intervalo [0,25]";
	else if (n > 25 && n <= 50) cout << "Intervalo (25,50]";
	else if (n > 50 && n <= 75) cout << "Intervalo (50,75]";
	else if (n > 75 && n <= 100) cout << "Intervalo (75,100]";
	else cout << "Fora de intervalo";
	return 0;
}
