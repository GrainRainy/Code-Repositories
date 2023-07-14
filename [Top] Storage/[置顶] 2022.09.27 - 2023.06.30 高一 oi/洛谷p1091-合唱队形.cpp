#include <iostream>

using namespace std;

const int N = 110;

int stuh[N];
int ff[N], bf[N];
int ans;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> stuh[i];
	// input
	
	
	for (int i = 1; i <= n; i ++)
	{
		ff[i] = 1;
		for (int j = 1; j <= i - 1; j ++)
			if (stuh[j] < stuh[i]) ff[i] = max(ff[i], ff[j] + 1);
	}
	// flis
	for (int i = n; i >= 1; i --)
	{
		bf[i] = 1;
		for (int j = n + 1; j > i; j --)
			if (stuh[i] > stuh[j]) bf[i] = max(bf[i], bf[j] + 1);
	}
	// blis
	
	for (int i = 1; i <= n; i ++)
		ans = max(ans, bf[i] + ff[i] - 1);
	cout << n - ans << endl;
	
	return 0;
}
