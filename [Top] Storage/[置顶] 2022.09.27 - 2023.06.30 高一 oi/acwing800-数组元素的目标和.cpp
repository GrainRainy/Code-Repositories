#include <iostream>

using namespace std;

const int N = 1e5;
int A[N + 10];
int B[N + 10];

int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < n; i ++)
		scanf("%d", &A[i]);
	for (int i = 0; i < m; i ++)
		scanf("%d", &B[i]);
		
	for (int i = 0, j = m - 1; i < n; i ++)
	{
		while (j >= 0 && A[i] + B[j] > x) j --;
		if (A[i] + B[j] == x) 
		{
			cout << i << " " << j << endl;
			return 0;
		}
	}
	return 0; 
} 
