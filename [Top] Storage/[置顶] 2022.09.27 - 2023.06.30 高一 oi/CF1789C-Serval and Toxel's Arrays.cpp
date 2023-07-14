#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
using LL = long long;

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

void solve()
{
	LL n; input(n);
	LL m; input(m);
	vector<LL> nums(n);
	map<int, int> cnt;
	for (auto &it : nums)
	{
		input(it);
		cnt[it] = m + 1;
	}
	// input
	for (int i = 0; i < m; i ++)
	{
		int now; input(now);
		int tag; input(tag);
		cnt[nums[-- now]] -= m - i;
		cnt[tag] += m - i;
		nums[now] = tag;
	}
	// count numbers
	
	LL ans = 0;
	for (auto t : cnt)
		ans += 1ll * t.second * (t.second - 1) / 2 + t.second * (m + 1 - t.second);
	cout << ans << endl;
	return;
}

int main()
{
	int t;
	input(t);
	while (t --) solve();
	return 0;
}
