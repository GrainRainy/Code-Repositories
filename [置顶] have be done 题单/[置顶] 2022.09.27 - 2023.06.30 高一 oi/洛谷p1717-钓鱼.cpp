#include <iostream>
#include <cctype>
#include <cstring>
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

const int N = 30;
const int H = 1e5 +  10;
int n, h;
int f[N], d[N], t[N];
int dp[N][H];
int ans = -1;

int main()
{
	input(n), input(h);
	h = h * 60 / 5;
	for (int i = 1; i <= n; i ++)
		input(f[i]);
	for (int i = 1; i <= n; i ++)
		input(d[i]);
	for (int i = 1; i < n; i ++)
		input(t[i]);
	// input
	
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	// init
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= h; j ++)
			for (int k = 0; k <= j - t[i - 1]; k ++)
				if ((k - 1) * d[i] < f[i] and dp[i - 1][j - t[i - 1] - k] != -1)
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - t[i - 1] - k] + k * f[i] - k * (k - 1) / 2 * d[i]);
					ans = max(ans, dp[i][j]);
				}
				
	cout << ans << endl;
	return 0;
}
