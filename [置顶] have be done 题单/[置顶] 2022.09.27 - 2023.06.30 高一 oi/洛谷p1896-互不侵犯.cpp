#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
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
	static short st[30], idx = 0;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

const int N = 13;
const int K = 110;
const int S = 1 << N;
int n, k;
// basic things
vector <int> state;
vector <int> to[S];
int cnt[S];
long long dp[N][K][S];
// line count state

bool judge(int s)
// return if Available
{
	return !((s >> 1) & s);
}

int calculate(int s)
{
	int tmp = s, cnt = 0;
	while (tmp)
	{
		if (tmp & 1) cnt ++;
		tmp >>= 1;
	}
	return cnt;
}

signed main()
{
	input(n), input(k);

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
			if (!(a & b) && judge(a | b)) to[a].push_back(b);
		}
	// init
	dp[0][0][0] = 1;
	for (int i = 1; i <= n + 1; i ++)
		for (int j = 0; j <= k; j ++)
			for (auto p : state)
				for (auto q : to[p])
					if (j >= cnt[p])
						dp[i][j][p] += dp[i - 1][j - cnt[p]][q];
	// dp
	cout << dp[n + 1][k][0] << endl;
	return 0;
}
