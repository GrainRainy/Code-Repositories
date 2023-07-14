#include <bits/stdc++.h>
using namespace std;

int a[105][105];

void print(int a[105][105], int r, int c)
{
	for (int i = 0; i < r; i ++)
	{
		for (int j = 0; j < c; j ++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	
}

int main()
{
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i ++)
		for (int j = 0; j < c; j ++)
			cin >> a[i][j];
	print(a, r, c);
	return 0;
}
