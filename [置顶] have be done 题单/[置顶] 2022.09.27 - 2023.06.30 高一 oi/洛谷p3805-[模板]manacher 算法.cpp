#include <bits/stdc++.h>
using namespace std;

const int N = 1.1e7 + 10;

int n;
int p[N << 1];
char input[N], s[N << 1];

void stringinit()
{
	int idx = 0;
	s[idx ++] = '$', s[idx ++] = '#';
	for (int i = 0; i < n; i ++)
		s[idx ++] = input[i], s[idx ++] = '#';
	s[idx ++] = '^';
	n = idx;
}

void manacher()
{
	int mr = 0, mid;
	for (int i = 1; i < n; i ++)
	{
		if (i < mr) p[i] = min(mr - i, p[2 * mid - i]);
		else p[i] = 1;
		while (s[i + p[i]] == s[i - p[i]]) p[i] ++;
		if (i + p[i] > mr)
		{
			mr = i + p[i];
			mid = i;
		}
	}
}

int main()
{
	cin >> input;
	n = strlen(input);
	stringinit();
	
	manacher();
	
	int maxn = 0;
	for (int i = 0; i < n; i ++)
		maxn = max(maxn, p[i]);
	cout << maxn - 1 << endl;
	return 0; 
}
