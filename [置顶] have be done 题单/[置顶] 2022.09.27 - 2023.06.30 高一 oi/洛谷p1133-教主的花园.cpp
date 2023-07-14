#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
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

const int N = 1e5 + 20;

int n;
int ans;
int w[N][3];
int f[N][3][2];
// i refers to tree i
// j refers to the type of tree
// 0 refers to height 10, 1 refers to height 20, 2 refers to height 30
// k refers to the height which is related to the tree between it
// k == 1 refers to higher, 0 is opposite

int main()
{
	input(n);
	for (int i = 1; i <= n; i ++)
	{
		input(w[i][0]), input(w[i][1]), input(w[i][2]);
	}
	// input
	
	for (int first = 0; first < 3; ++ first)
	{
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 2; j ++)
				f[1][i][j] = 0;
		f[1][first][0] = f[1][first][1] = w[1][first];
		for (int i = 2; i <= n; i ++)
		{
			f[i][0][0] = max(f[i - 1][1][1], f[i - 1][2][1]) + w[i][0];
			f[i][1][0] = f[i - 1][2][1] + w[i][1];
			f[i][1][1] = f[i - 1][0][0] + w[i][1];
			f[i][2][1] = max(f[i - 1][0][0], f[i - 1][1][0]) + w[i][2];
		}
		for(int i = 0; i < first; i ++)
            ans = max(ans, f[n][i][0]);
        for(int i = 2; i > first; i --)
            ans = max(ans, f[n][i][1]);
	}
	cout << ans << endl;
	return 0;
}
