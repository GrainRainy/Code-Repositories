#include <bits/stdc++.h>
#include <cmath>
using namespace std;

template <typename T> inline void input( T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = ' ')
{
	static short st[30], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar (st[top --] | '0');
	putchar(ed);
}

const int N = 110;
int n;
vector<int> path;
double x[N], y[N];
bool st[N];
int ans = 0x3f3f3f3f;

double get_dist(int a, int b)
{
	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

void bfs(int u, int cnt, int res)
{
	st[u] = true;
	if (u == n and cnt == n)
	{
		path.push_back(u);
		if (res < ans)
		{
			st[u] = false;
			path.pop_back();
			ans = res;
		}
		return;
	}
	
	for (int i = 1; i <= n; i ++)
	{
		if (!st[i])
		{
			path.push_back(i);
			bfs(i, cnt + 1, get_dist(u, i));
			st[i] = false;
			path.pop_back();
		}
	}
	return;
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	// file stream
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	input(n);
	
	bool flagb = true;
	int max_idx = 0, maxy = -1;
	for (int i = 1; i <= n; i ++)
	{
		cin >> x[i] >> y[i];
		if (y[i] > maxy) max_idx = i, maxy = y[i];
		if (i != 1 and y[i - 1] <= y[i]) flagb = false;
	}
	
	if (flagb)
	{
		for (int i = 1; i <= n; i ++)
			output(i);
		puts("");
		return 0;
	}

	bfs(max_idx, 1, 0);
	
	for (auto a : path)
		output(a);
	puts("");
	return 0;
}
