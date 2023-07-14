#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 2e5 + 10;
int n, k, a, m;
int res;
int nums[N];
bool st[N];
// basic things
int father[N];
int cnt[N];

inline int find(int x)
{
	if (father[x] != x) return father[x] = find(father[x]);
	return x;
}

inline int calc(int x)
{
	return (x + 1) / (a + 1);
}

inline bool check(int a)
{
	return (a > 0 and a <= n);
}

inline void merge(int a, int b)
{
	int father_a = find(a);
	int father_b = find(b);
	if (father_a == father_b) return;
	
	res -= calc(cnt[father_a]);
	res -= calc(cnt[father_b]);
	father[father_a] = b;
	cnt[father_b] += cnt[father_a];
	res += calc(cnt[father_b]);
}

int main()
{
	input(n), input(k), input(a), input(m);
	for (int i = 1; i <= m; i ++)
		input(nums[i]), st[nums[i]] = true;
	// input
	
	res = (n - m) * (2 / (a + 1));
	for (int i = 1; i <= n; i ++)
		father[i] = i, cnt[i] = 1;
	for (int i = 1; i <= n; i ++)
		if (!st[i] and !st[i - 1]) merge(i, i - 1);
	// init
	
	if (res >= k) return puts("-1"), 0;
	// special judge
	
	for (int i = m; i; i --)
	{
		st[nums[i]] = false;
		res += 2 / (a + 1);
		if (check(nums[i] - 1) and !st[nums[i] - 1])
			merge(nums[i] - 1, nums[i]);
		if (check(nums[i] + 1) and !st[nums[i] + 1])
			merge(nums[i], nums[i] + 1);
		if (res >= k) return cout << i << endl, 0;
	}
	return 0;
}

