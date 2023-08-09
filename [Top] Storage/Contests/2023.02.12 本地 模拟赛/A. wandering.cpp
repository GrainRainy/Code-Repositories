#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T>
void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 2e5 + 10;
int n, t;
bool gph[3][N];
// basic things

bool judge()
{
	for (int i = 1; i <= n; i ++)
		if (gph[1][i] && gph[2][i]) return false;
	return true;
}

int main()
{
	freopen("wandering.in","r",stdin);
	freopen("wandering.out","w",stdout);
	input(n), input(t);
	// input
	while (t --)
	{
		int tmpx, tmpy;
		input(tmpx), input(tmpy);
		gph[tmpx][tmpy] = !gph[tmpx][tmpy];
		if (judge()) puts("YES");
		else puts("NO");
	}
}

