#include <iostream>
#include <cstring>
#include <algorithm>

#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#define putchar(a) _putchar_nolock()
#endif

using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int MOD = 1e9 + 7;
const int N = 110;
LL n, k;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = ' ') {
	if (x < 0) putchar('-'), x = -x;
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

struct Matrix {
	ULL a[N][N];
	
	ULL* operator [](LL x) { return a[x]; }
	Matrix() { memset(a, 0, sizeof a); } // identity matrix 
	
	inline void build(LL n) {
		for (int i = 1; i <= n; i ++) {
			a[i][i] = 1;
		}
	}
	
	Matrix operator * (Matrix b) {
		Matrix ans;
		for (int i = 1; i <= n; i ++) {
			for (int k = 1; k <= n; k ++) {
				for (int j = 1; j <= n; j ++) {
					ans[i][j] = (ans[i][j] +  a[i][k] * b[k][j] % MOD) % MOD;
				}
			}	
		}
		return ans;
	}
	
	void print(int n) {
		for (int i = 1; i <= n; i ++, puts("")) 
			for (int j = 1; j <= n; j ++) output(a[i][j]);
	}
}a, ans;

Matrix fpow(Matrix a, LL k) {
	Matrix ans; ans.build(n);
	while (k) {
		if (k & 1) ans = ans * a;
		a = a * a;
		k >>= 1;
	}
	return ans;
}

int main() {
	input(n), input(k);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			input(a[i][j]);
	
	return fpow(a, k).print(n), 0;
}
