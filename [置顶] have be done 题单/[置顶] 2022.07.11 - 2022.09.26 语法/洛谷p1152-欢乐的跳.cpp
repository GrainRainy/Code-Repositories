#include <bits/stdc++.h>

using namespace std;

int a[1005];
bool is[100000005];

bool Jolly(int a[], int n, bool is[])
{
	for (int i = 1; i < n; i ++)
		is[abs(a[i] - a[i - 1])] = 1;
	
	for (int i = 1; i < n; i ++)
		if (!is[i]) return 0;
	
	return 1;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	
	if (Jolly(a, n, is)) cout << "Jolly" << endl;
	else cout << "Not jolly" << endl;
	return 0;
}
