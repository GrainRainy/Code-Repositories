#include <iostream>
#include <cstring>
#include <algorithm>

#define lowbit(x) ((x) & -(x))

using namespace std;
using LL = long long;

template <typename T> inline void input (T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		 f|= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
} 

const int N = 20;
const int M = 1 << N;

int n, m;
int x, y;
int graph[N][N];
LL f[M][N];
LL ans;

int main() {
	input(n), input(m);
	for (int i = 1; i <= m; i ++) {
		input(x), input(y);
		x --, y --;
		graph[x][y] = graph[y][x] = 1;
	}
	// input
	
	for (int i = 0; i < n; i ++) f[1 << i][i] = 1;
	
	for (int i = 1; i <= (1 << n); i ++) {
		for (int j = 0; j < n; j ++) {
			if (!f[i][j]) continue;
			for (int k = 0; k < n; k ++) {
				if (!graph[j][k]) continue;
				if ((i & -i) > (1 << k)) continue;
				// available 
				if (i & (1 << k)) {
					if ((i & -i) == (1 << k)) ans += f[i][j];
				}
				else f[i | (1 << k)][k] += f[i][j];
			}
		}
	}
	cout << (ans - m) / 2 << '\n';
	return 0;
}
