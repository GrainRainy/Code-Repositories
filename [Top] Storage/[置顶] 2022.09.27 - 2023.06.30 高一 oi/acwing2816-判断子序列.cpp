#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5;
int a[N + 10], b[N + 10];

int main()
{
	int n, m;
	cin >> n >> m;
	memset(a, -1, sizeof a); // ∑¿÷π∆•≈‰µΩø’Œª÷√µƒ 0  
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= m; i ++)
		cin >> b[i];
	
	int j = 1;
	for (int i = 1; i <= m; i ++)
		if (b[i] == a[j]) j ++;
		
	if (j == n + 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
} 
