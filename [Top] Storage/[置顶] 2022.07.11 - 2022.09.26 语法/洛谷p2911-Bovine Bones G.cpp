#include <bits/stdc++.h>

using namespace std;

int a[100];

int main()
{
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	
	int sum;
	for (int i = 1; i <= s1; i ++)
		for (int j = 1; j <= s2; j ++)
			for (int k = 1; k <= s3; k ++)
			{
				sum = i + j + k;
				a[sum] ++;
			}
			
	int ans = 0;
	int save;
	for (int i = 0; i < 50; i ++)
		if (a[i] > ans)
		{
			ans = a[i];
			save = i;
		}
		
	cout << save << endl;
	return 0;
}
