#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;
using ULL = unsigned long long;

template <typename T> inline void input(T &x ){
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
	static short st[16], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int MOD = 1e9 + 7;
const int N = 5;
LL n;

struct Matrix {
	LL a[N][N], mx, my;
	
	LL* operator [](LL x) { return a[x]; }
	
	Matrix(int n, int m) {
		mx = n, my = m;
		memset(a, 0, sizeof a);
	}
	
	void build() {
		for (int i = 1; i <= mx; i ++)
			a[i][i] = 1;
	}
	
	Matrix operator * (Matrix b) {
		Matrix ans(mx, b.my);
		for (int i = 1 ; i <= mx; i ++) 
			for (int k = 1; k <= my; k ++)
				for (int j = 1; j <= b.my; j ++)
					ans[i][j] = (ans[i][j] + (LL)a[i][k] * b[k][j] % MOD) % MOD;
		return ans;
	}
	
	void print(){
		for (int i = 1; i <= mx; i ++, puts(""))
			for (int j = 1; j <= my; j ++) output(a[i][j]);
	}
};

Matrix fpow(Matrix a, LL b) {
	Matrix ans(a.mx, a.my); ans.build();
	
	while (b) {
		if (b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int main() {
	input(n);
	Matrix a(1, 2), b(2, 2);
	a[1][1] = 0, a[1][2] = 1;
	b[1][1] = 0, b[1][2] = b[2][1] = b[2][2] = 1;
		
	a = a * fpow(b, n);
	output(a[1][1], '\n');
	return 0;
}
