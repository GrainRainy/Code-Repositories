#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[64], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed); 
}

int n, w, ans;
int gph[15][15], path[25];

bool check(int x, int y)
{
	return (x > 0 and x <= n and y > 0 and y <= w);
}

bool judge(int max)
{	
	for (int i = 1; i <= max; i ++)
		for (int j = i + 1; j <= max; j ++)
			if (path[i] == path[j]) return false;
	return true;
}

inline void dfs(int x, int y, int cnt)
{
	path[cnt] = gph[x][y];
	if (cnt == n + w - 1 and judge(cnt)) ans ++;
	if (check(x + 1, y)) dfs(x + 1, y, cnt + 1);
	if (check(x, y + 1)) dfs(x, y + 1, cnt + 1);
}

int main()
{
	input(n), input(w);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= w; j ++)
			input(gph[i][j]);
	
	dfs(1, 1, 1);
	
	output(ans);
	return 0;
}
