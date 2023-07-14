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

void solve(int n)
{
	aver = 0;
	for (int i = 1; i <= n; i ++)
	{
		input(nums[i]);
		aver += nums[i];
	}
	aver /= n;
	// input
	optim[1] = nums[1] - aver;
	for (int i = 2; i <= n; i ++)
		optim[i] = optim[i - 1] + nums[i] - aver;
	
	sort(optim + 1, optim + n + 1);
	
	LL mid = optim[n / 2];
	LL ans1 = 0;
	for (int i = 1; i <= n; i ++)
		ans1 += abs(optim[i] - mid);
	LL ans2 = 0;
    for (int i = 1; i <= n; i ++)
		ans2 += abs(mid - optim[i]); 
	cout << min(ans1, ans2) << endl;
	return;
}

int main()
{
	while (scanf("%d", &n) != EOF) solve(n);
	return 0;
}
