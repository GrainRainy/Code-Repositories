#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
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

const int N = 15;
const int S = 1 << 12;
const int MOD = 1e8;
int m, n;
int gph[N];
// basic
vector<int> state;
vector<int> to[S];
int f[N][S];

bool judge(int s)
{
	return !(s & (s << 1));
}

int main()
{
	input(n), input(m);
	for (int i = 1; i <= n; i ++)
	{
		int sum = 0;
		for (int j = 1; j <= m; j ++)
		{
			bool tmp; input(tmp);
			tmp = !tmp;
			sum = sum * 2 + tmp;
		}
		gph[i] = sum;
	}
	// input
	for (int i = 0; i < (1 << m); i ++)
		if (judge(i)) state.push_back(i);
	for (int i = 0; i < state.size(); i ++)
		for (int j = 0; j < state.size(); j ++)
		{
			int a = state[i], b = state[j];
			if (!(a & b)) to[i].push_back(j);
		}		
	// init
	f[0][0] = 1;
	for (int i = 1; i <= n + 1; i ++)
		for (int a = 0; a < state.size(); a ++)
			if (!(state[a] & gph[i]))
				for (auto b : to[a])
					if (!(state[b] & gph[i - 1])) 
						f[i][a] = (f[i][a] + f[i - 1][b]) % MOD;
	// dp
	cout << f[n + 1][0] << endl;
	return 0;
}
