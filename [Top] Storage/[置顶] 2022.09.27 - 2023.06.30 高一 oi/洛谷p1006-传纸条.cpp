#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 60;
int n, m;
int graph[N][N];
LL f[N << 1][N][N];

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) 
			input(graph[i][j]);
	}
	
	for (int k = 2; k <= n + m; k ++) {
		for (int i1 = 1; i1 < k and i1 <= n; i1 ++) {
			for (int i2 = 1; i2 < k and i2 <= n; i2 ++) {
				LL &x = f[k][i1][i2];
				x = max(x, f[k - 1][i1 - 1][i2 - 1]);
				x = max(x, f[k - 1][i1 - 1][i2]);
				x = max(x, f[k - 1][i1][i2 - 1]);
				x = max(x, f[k - 1][i1][i2]);
				x += graph[i1][k - i1] + (i1 != i2) * graph[i2][k - i2];
			}
		}
	} 
	cout << f[n + m][n][n] << endl;
	return 0;
}
