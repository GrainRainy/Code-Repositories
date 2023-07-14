#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int smoke = n;
	int have = n;
	while (have / k != 0)
	{
		smoke += have / k;
		have = have / k + have % k;
	}
	cout << smoke << endl;
	return 0;
}
