#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
char input[N], s[N << 1]; // manacher
int l[N << 1], r[N << 1], p[N << 1];

void init()
{
	int idx = 0;
	s[idx ++] = '$', s[idx ++] = '#';
	for (int i = 0; i < n; i ++)
		s[idx ++] = input[i], s[idx ++] = '#';
	s[idx ++] = '^';
	n = idx - 1;
	cerr << n << endl;
}

void manacher()
{
	int mr = 0, mid = 0;
	for (int i = 1; i < n; i ++)
	{
		if (i < mr) p[i] = min(mr - i, p[mid * 2 - i]);
		else p[i] = 1;
		while (s[i + p[i]] == s[i - p[i]]) p[i] ++;
		if (i + p[i] > mr) mr = i + p[i], mid = i;
		
		l[i - p[i] + 1] = max(l[i - p[i] + 1], p[i] - 1);
		r[i + p[i] - 1] = max(r[i + p[i] - 1], p[i] - 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> input;
	n = strlen(input);
	init();
	
	manacher();
	
	for (int i = 0; i <= n + 1; i += 2)
		l[i] = max(l[i], l[i - 2] - 2);
	for (int i = n + 1; i >= 0; i -= 2)
		r[i] = max(r[i], r[i + 2] - 2);
	
	int ans = 0;
	for (int i = 1; i <= n; i += 2)
		if (l[i] && r[i]) ans = max(ans, l[i] + r[i]);
	cout << ans << endl;
	return 0;
}
