#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
#define int long long 
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
template <typename T>
inline void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], idx;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

const int N = 15;
const int K = 110;
const int S = 1 << 10;
int n, k;
int cnt[S]; // count the numbers of 1
vector<int> state;
vector<int> to[S]; 
// basic thins
int dp[N][K][S];
// dp

bool judge(int s)
{
	return !(s & (s << 1));
}

int calculate(int s)
{
	int cnt = 0;
	for (int i = 0; i < n; i ++)
		cnt += s >> i & 1;
	return cnt;
}

signed main()
{
	input(n), input(k);
	// input
	for (int i = 0; i < (1 << n); i ++)
		if (judge(i))
		{
			state.push_back(i);
			cnt[i] = calculate(i);
		}
	for (int i = 0; i < state.size(); i ++)
		for (int j = 0; j < state.size(); j ++)
		{
			int a = state[i], b = state[j];
			if (!(a & b) && judge(a | b))
				to[a].push_back(b);
		}
	// init 
	dp[0][0][0] = 1;
	for (int i = 1; i <= n + 1; i ++)
		for (int s = 0; s <= k; s ++)
			for (auto a : state)
				for (auto b : to[a])
					if (s >= cnt[a])
						dp[i][s][a] += dp[i - 1][s - cnt[a]][b];
	
	// dp
	output(dp[n + 1][k][0]);
	return 0;
}
