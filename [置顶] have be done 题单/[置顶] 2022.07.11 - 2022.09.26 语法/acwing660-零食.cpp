#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,a;
	double money;
	cin >> t >> a;
	switch(t)
	{
		case(1): money = a * 4.0; break;
		case(2): money = a * 4.5; break;
		case(3): money = a * 5.0; break;
		case(4): money = a * 2.0; break;
		case(5): money = a * 1.5; break;
	}
	printf("Total: R$ %.2f",money);
	return 0;
}
