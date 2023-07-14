#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;
template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
inline void output(T x, char ed = '\n') // '\n' or ' ', remember to check
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], idx;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

typedef pair<double, double> PDD;

const int N = 18; 
const int S = 1 << 18;
const double eps = 1e-8;

int n, m;
PDD nums[N];
int path[N][N]; // save state from i to j
int f[S];

int cmp(double x, double y)
{
	if (fabs(x - y) < eps) return 0; // equal
	if (x < y) return -1; // smaller
	return 1; // bigger
}

void solve()
{
	memset(path, 0, sizeof path);
	memset(f, 0x3f, sizeof f);
	
	input(n), input(m);
	for (int i = 0; i < n; i ++)
		cin >> nums[i].first >> nums[i].second;
		
	// input
	
	for (int i = 0; i < n; i ++)
	{
		path[i][i] = (1 << i);
		for (int j = 0; j < n; j ++)
		{
			double x1 = nums[i].first, y1 = nums[i].second;
			double x2 = nums[j].first, y2 = nums[j].second;
			if (!cmp(x1, x2)) continue;
			
			double a = ((y1 / x1) - (y2 / x2)) / (x1 - x2);
			double b = y1 / x1 - a * x1;
			if (a >= 0) continue;
			
			path[i][j] = 0;
			for (int k = 0; k < n; k ++)
			{
				double x3 = nums[k].first, y3 = nums[k].second;
				if (!cmp(a * x3 * x3 + b * x3, y3))
					path[i][j] += (1 << k);
			}
		}
	}
	
	f[0] = 0;
	for (int i = 0; i < (1 << n) - 1; i ++)
	{
		int x = 0;
		for (int k = 0; k < n; k ++)
		{
			if (!((i >> k) & 1))
			{
				x = k;
				break;
			}
		}
		// x refers to 0 state
		
		for (int j = 0; j < n; j ++)
			f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
	}
	cout << f[(1 << n) - 1] << endl;
	
	return;
}

int main()
{
	int t;
	input(t);
	while (t --) solve();
	return 0;
}
