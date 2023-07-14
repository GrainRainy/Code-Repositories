#include <bits/stdc++.h>
using namespace std;

int a[1005];

int find(int n)
{
	if (a[n] != 0) return a[n];
	int sum = 0;
	for (int i = 1; i <= n / 2; i ++)
		sum += find(i);
		sum += find(i);
		
	sum += 1;
	a[n] = sum; 
	return sum;
		
}
int main()
{
	int n;
	cin >> n;
	cout << find(n) << endl;
	return 0;
}
