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

const int N = 15;
const int M = 110;
int n, g, sum;
int p[N], c[N]; 
int f[N][M * N];

int main() {
	input(n), input(g);
	for (int i = 1; i <= n; ++ i) {
		input(p[i]), input(c[i]);
		sum += p[i];
	}
	// input
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j <= p[i]; ++ j){
			for (int k = 0; k <= sum - j; ++ k){
				if (j != p[i]) f[i][j + k] = max(f[i][j + k], f[i - 1][k] + j * i * 100); 
				else f[i][j + k] = max(f[i][j + k], f[i - 1][k] + i * j * 100 + c[i]);
			}
		}
	}
	
	for (int i = 1; i <= sum; i ++) {
		if (f[n][i] >= g) return cout << i << endl, 0;
	}
}
