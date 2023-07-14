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
	static short st[30], idx;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

const int N = 110, M = 11;
const int S = 1 << 10;
int n, m;
int gpq[N];
// basic thintmpidxs 
vector<int> state;
// ?¨´¨®Do?¡¤¡§¡Á¡ä¨¬? 
int cnt[S];
int f[2][S][S];
// 2?¨ºy¡ê?¦Ì¡À?¡ã2?¡Á¡ä¨¬?¡ê?¨¦?¨°?2?¡Á¡ä¨¬? 

bool judge(int s)
{
	return !(s & s >> 1 || s & s >> 2);
}

int count(int s)
{
	int tmp = s;
	int res = 0;
	while (tmp) res += tmp & 1, tmp >>= 1;
	return res;
}

int main()
{
	input(n), input(m);
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < m; j ++)
		{
			char tmp; cin >> tmp;
			gpq[i] += (tmp == 'H') << j;
		}
	// input
	for (int i = 0; i < (1 << m); i ++)
		if (judge(i))
		{
			state.push_back(i);
			cnt[i] = count(i);
		}
	// init
	
	for (int i = 1; i <= n + 2; i ++)
		for (int j = 0; j < state.size(); j ++) // i - 2
			for (int k = 0; k < state.size(); k ++) // i - 1
			    if (!(gpq[i - 1] & state[k]))
					for (int u = 0; u < state.size(); u ++) // i
					{
						if (gpq[i] & state[u]) continue;
						int a = state[j], b = state[k], c = state[u];
						if ((a & b) | (b & c) | (a & c)) continue;
						f[i & 1][k][u] = max(f[i & 1][k][u], f[i - 1 & 1][j][k] + cnt[c]);
					}
	cout << f[n + 2 & 1][0][0] << endl;
	return 0;
}
