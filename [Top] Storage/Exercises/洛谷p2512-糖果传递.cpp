#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;
template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; c < '0' or c > '9'; c = getchar())
		f |= (c == '-');
	for (; c >= '0' and c <= '9'; c = getchar())
		x = x * 10 + (c ^ '0');
	x = f ? -x : x;
}

const int N = 1e6 + 10;
LL n, aver;
LL nums[N];
LL optim[N];

int main()
{
	input(n);
	for (int i = 1; i <= n; i ++)
	{
		input(nums[i]);
		aver += nums[i];
	}
	aver /= n;
	// input
	for (int i = 1; i <= n; i ++)
		optim[i] = optim[i - 1] - nums[i] + aver;
	
	sort(optim + 1, optim + n + 1);
	
	LL mid = optim[(n + 1) / 2];
	LL ans = 0;
	for (int i = 1; i <= n; i ++)
		ans += abs(optim[i] - mid);
	cout << ans << endl;
	return 0;
}
