#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <queue>
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
	do st[++ idx] = x % 10, x /= 10; while(x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}
typedef pair<int, int> PII;

const int N = 1010;
int n;
int peak, valley;
int gph[N][N];
bool st[N][N];
queue<PII> q;

inline void bfs(int x, int y, bool &has_higher, bool &has_lower)
{
	q.push({x, y});
	st[x][y] = true;
	
	while (q.size())
	{
		auto t = q.front(); q.pop();
		
		for (int i = t.first - 1; i <= t.first + 1; i ++)
			for (int j = t.second - 1; j <= t.second + 1; j ++)
			{
				if (i < 0 or i >= n or j < 0 or j >= n) continue;
				if (gph[i][j] != gph[t.first][t.second])
				{
					if (gph[i][j] > gph[t.first][t.second])
						 has_higher = true;
					else has_lower = true;
				}
				else if (!st[i][j])
				{
					q.push({i, j});
					st[i][j] = true;
				}
			}
	}
}

int main()
{
	input(n);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			input(gph[i][j]);
	// input
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (!st[i][j])
			{
				bool has_higher = false;
				bool has_lower = false;
				bfs(i, j, has_higher, has_lower);
				if (!has_higher) peak ++;
				if (!has_lower) valley ++;
			}
	cout << peak << " " << valley << endl;
	return 0;
}
