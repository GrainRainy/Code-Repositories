#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;

const int N = 2e4 + 10;
int n, pos[N][2];
int f[N][2]; // 0-> left, 1 -> right 

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(pos[i][0]), input(pos[i][1]);
	memset(f, 0x3f, sizeof f);
	pos[n + 1][0] = pos[n + 1][1] = n;
	f[1][0] = pos[1][1] * 2 - pos[1][0] - 1, f[1][1] = pos[1][1] - 1;
	for (int i = 2; i <= n + 1; ++ i) 
		for (int a = 0; a < 2; ++ a)
			for (int b = 0; b < 2; ++ b) 
				f[i][b] = min(f[i][b], f[i - 1][a] + 1 + abs(pos[i - 1][a] - pos[i][b ^ 1]) + pos[i][1] - pos[i][0]);
	cout << f[n + 1][1] - 1 << endl;
	return 0;
}
