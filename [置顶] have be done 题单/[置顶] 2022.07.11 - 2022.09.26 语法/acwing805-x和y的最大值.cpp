#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	if (a > b) return a;
	else if (a < b) return b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << max(a, b) << endl;
	return 0;
	
}
