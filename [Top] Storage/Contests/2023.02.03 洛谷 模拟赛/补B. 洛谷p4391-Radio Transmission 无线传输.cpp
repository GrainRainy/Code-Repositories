#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
char s[N];
int nxt[N];

int main()
{
	cin >> n >> s + 1;
	
	int pos = 0;
	for (int i = 2; i <= n; i ++)
	{
		while (pos && s[pos + 1] != s[i]) pos = nxt[pos];
		if (s[i] == s[pos + 1]) pos ++;
		nxt[i] = pos;
	}
	cout << n - nxt[n] << endl;
	return 0; 
}
