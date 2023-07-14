#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], b[N];
int son[N];
int f[N], k[N];
int len;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		son[a[i]] = i;
	}
	for (int i = 1; i <= n; i ++)
		cin >> b[i];
	// input
	
	for (int i = 1; i <= n; i ++)
	{
		if (son[b[i]] > k[len])
		{
			k[++ len] = son[b[i]];
			f[i] = len;
			continue;
		}
		
		int t = lower_bound(k + 1, k + len + 1, son[b[i]]) - k;
		k[t] = son[b[i]];
		f[i] = t;
	}
		
		
		
	cout << len << endl;
	
	return 0;
}
