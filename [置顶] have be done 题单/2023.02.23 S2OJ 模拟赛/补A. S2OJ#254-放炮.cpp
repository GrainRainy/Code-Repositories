#include <iostream>
#include <cstring>
#include <cctype>
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

const int N = 110;
const int MOD = 9999973;
int n, m; 
int f[N][N][N];

int main()
{
	input(n), input(m);
	
	f[0][0][0] = 1;
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= m; j ++)
			for (int k = 0; k + j <= m; k ++)
			{
				int l = m - j - k;
				f[i + 1][j][k] = (f[i + 1][j][k] + f[i][j][k]) % MOD;
				// puts 0 dots
				f[i + 1][j + 1][k] = (f[i + 1][j + 1][k] + 1ll * f[i][j][k] * (m - j - k)) % MOD; // 0
				if (j >= 1) f[i + 1][j - 1][k + 1] = (f[i + 1][j - 1][k + 1] + 1ll * f[i][j][k] * j) % MOD; // 1
				// puts 1 dots
				f[i + 1][j + 2][k] = (f[i + 1][j + 2][k] + 1ll * f[i][j][k] * (m - j - k) * (m - j - k - 1) / 2) % MOD; // 0 0
				f[i + 1][j][k + 1] = (f[i + 1][j][k + 1] + 1ll * f[i][j][k] * (m - j - k) * j) % MOD; // 0 1
				if (j >= 2) f[i + 1][j - 2][k + 2] = (f[i + 1][j - 2][k + 2] + 1ll * f[i][j][k] * j * (j - 1) / 2) % MOD; // 1 1
				// puts 2 dots
				
				// ะดนามหตฤ  
//				f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % MOD;
//				// puts 0 dots
//				if (m - j - k >= 1) f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k] * (m - j - k)) % MOD; // 0
//				if (j >= 1) f[i][j][k] = (f[i][j][k] + f[i - 1][j + 1][k - 1] * j) % MOD; // 1
//				// puts 1 dots
//				if (m - j - k >= 2) f[i][j][k] = (f[i][j][k] + f[i - 1][j - 2][k] * (m - j - k) * (m - j - k - 1) / 2) % MOD; // 0 0
//				if (m - j - k >= 1 and j >= 1) f[i][j][k] = (f[i][j][k] + f[i - 1][j][k + 1] * (m - j - k) * j) % MOD; // 0 1
//				if (j >= 2) f[i][j][k] = (f[i][j][k] + f[i - 1][j - 2][k + 2] * j * (j - 1) / 2) % MOD;	// 1 1
//				// puts 2 dots
			}
	
//	for (int i = 1; i <= n; i ++)
//		for (int i)
	
	int ans = 0;
	for (int j = 0; j <= m; j ++)
		for (int k = 0; k + j <= m; k ++)
			(ans += f[n][j][k]) %= MOD;
		
	cout << ans << endl;
	return 0;
} 
