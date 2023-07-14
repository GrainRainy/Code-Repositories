#include <bits/stdc++.h>

using namespace std;

bool lights[2000005];

int main()
{
	int n;
	cin >> n;
	double a;
	int t;
	while (n --)
	{
		cin >> a >> t;
		for (int i = 1; i <= t; i ++)
			lights[(int)(i * a)] = !lights[(int)(i * a)];
	}
	for (int i = 1; i <= 2000004; i ++)
		if (lights[i])
		{
			cout << i << endl;
			return 0;
		}
}
