#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x; 
}

typedef long long LL;
const int N = 1e5 + 10;
LL n, mod;
struct Node
{
	int nums, val;
	
	bool operator < (const Node &t) const
	{
		return val < t.val;
	}
}node[N];
LL ans = 0;

int main()
{
	input(n), input(mod);
	for (int i = 1; i <= n; i ++)
	{
		input(node[i].nums);
		input(node[i].val);
		node[i].val %= mod;
		if(!node[i].val)
		{
			-- i,-- n;
			continue;
		}
		ans += (mod - node[i].val) * node[i].nums;
	}
	sort(node + 1, node + n + 1);
	
	int l = 1, r = n;
	while (l < r)
	{
		if (node[l].val + node[r].val > mod)
		{
			r --;
			continue;
		}
		int mul = min(node[l].nums, node[r].nums);
		node[l].nums -= mul, node[r].nums -= mul;
		ans -= mod * mul;
		if (!node[l].nums) l ++;
		if (!node[r].nums) r --;
	}
	if (node[l].val * 2 <= mod) ans -= node[l].nums / 2 * mod;
	
	cout << ans << endl;
	return 0;
}

