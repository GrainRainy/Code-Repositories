#include <iostream>
using namespace std;

const int N = 60;
int n, k;
char s[N];
int nxt[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> k >> s;
	// input
	int pos = 0;
	for (int i = 2; i <= n; i ++)
	{
		while (pos && s[i] != s[pos + 1]) pos = nxt[pos];
		if (s[i] == s[pos + 1]) pos ++;
		nxt[i] = pos;
	}
	// n * k - nxt[n] * k = len(ans);
	while (k --)
	{
		for (int i = 0; i < n - nxt[n] - 1; i ++)
			cout << s[i];
	}
	for (int i = 0; i < nxt[n]; i ++)
		cout << s[i];
	cout << endl;
	return 0;
}
