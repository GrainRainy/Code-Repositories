#include <iostream>
#include <cctype>
#include <cmath>
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
	static short st[30], idx;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

typedef pair<int, int> PII;
const int N = 60;
const int M = N * N;
int m, n;
int cnt, maxn;
int gph[N][N];
bool st[N][N];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

queue<PII> q;

int bfs(int x, int y)
{
	int count = 0;
	st[x][y] = true;
	q.push({x, y});
	
	while (q.size())
	{
		auto t = q.front(); q.pop();
		++ count;
		
		for (int i = 0; i < 4; i ++)
		{
			int tmpx = t.first + dx[i], tmpy = t.second + dy[i];
			
			if (tmpx < 0 or tmpx >= m or tmpy < 0 or tmpy >= n) continue;
			if (gph[t.first][t.second] >> i & 1) continue;
			if (st[tmpx][tmpy]) continue;
			
			q.push({tmpx, tmpy});
			st[tmpx][tmpy] = true;
		}
	}
	return count;
}

int main()
{
	input(m), input(n);
	for (int i = 0; i < m; i ++)
		for (int j = 0; j < n; j ++)
			input(gph[i][j]);
	// input		
	
	for (int i = 0; i < m; i ++)
		for (int j = 0; j < n; j ++)
			if (!st[i][j])
			{
				maxn = max(maxn, bfs(i, j));
				++ cnt;
			}
	
	output(cnt), output(maxn);
	return 0;
}
