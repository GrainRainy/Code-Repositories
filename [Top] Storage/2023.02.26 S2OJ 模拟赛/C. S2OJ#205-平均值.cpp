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

const int N = 250010;
int n, l, r;
int nums[N];
int sum[N];
double ans = -1;
int ansx, ansy;

int main()
{
	input(n), input(l), input(r);
	for (int i = 1; i <= n; ++ i)
	{
		input(nums[i]);
		sum[i] = nums[i] + sum[i - 1];
	}
	
	for (int i = 1; i <= n; ++ i)
		for (int len = l; len <= r; ++ len)
		{
			int j = i + len - 1;
			if (j > n) break;
			if (nums[j] < ans) continue;
			
			if (1.0 * (sum[j] - sum[i - 1]) / len > ans)
			{
				ans = 1.0 * (sum[j] - sum[i - 1]) / len;
				ansx = sum[j] - sum[i - 1];
				ansy = len;
			}
		}
	
	int t = __gcd(ansx, ansy);
	ansx /= t; ansy /= t;
	printf("%d/%d\n", ansx, ansy);
	return 0;
}
