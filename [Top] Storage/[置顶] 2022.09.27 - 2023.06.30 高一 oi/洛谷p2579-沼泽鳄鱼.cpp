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

template <typename T> inline void output(T x, char ed = ' ') {
	if (x < 0) putchar('-'), x = -x;
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 55;
const int NFISH = 25;
const int MOD = 1e4;
int n, m, start, end, nfish;

struct Matrix{
	LL a[N][N], mx, my;
	
	LL* operator [] (const int k) { return a[k]; }
	Matrix(int n, int m) {
		mx = n, my = m;
		memset(a, 0, sizeof 0);
	}
	
	Matrix operator * (const Matrix &b) const {
		Matrix ans(mx, b.my);
		for (int i = 1; i <= mx; i ++)
			for (int k = 1; k <= my; k ++)
				for (int j = 1; j <= b.my; j ++)
					ans[i][j] = (ans[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
		return ans;
	}
	
	void print() {
		for (int i = 1; i <= mx; i ++, puts(""))
			for (int j = 1; j <= my; j ++)
				output(a[i][j]);
	}
};

int main() {
	input(n), input (m), input(start), input(end), input(nfish);
	
}
