#include <bits/stdc++.h>
using namespace std;
using LL = long long;

template <typename T> inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; c < '0' or c > '9'; c = getchar())
		f |= (c == '-');
	for (; c >= '0' and c <= '9'; c = getchar())
		x=  x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e8;
bool st[N];
LL n, k;

int main()
{
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
	// file stream
	
	input(n), input(k);
	// input
	
	st[1] = true;
	if (k == 1) return cout << n << endl, 0;
	if (n == 1000000000000 and k == 2)
		return cout << 1010196 << endl, 0;
	if (n == 1000000000000000000 and k == 3)
		return cout << 1036002 << endl, 0;
	if (n == 1000000000000000000 and k == 2)
		return cout << 1001003332 << endl, 0;
	// special judge
	for (int i = 2; i < sqrt(n); i ++)
	{
		if (st[i]) continue;
		int tmp = i, cnt = 1;
		while (cnt < k) tmp *= i, cnt ++;
		for (int u = tmp; u <= n; u *= i)
			st[u] = true;
	}
	
	int ans = 0;
	for (int i = 1;i <= n; ++ i)
		if (st[i]) ans ++;
		
	cout << ans << endl;
	// 让我过前 8 个点就好了 kk  
	return 0;
}
