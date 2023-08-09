#include <bits/stdc++.h>

#define __DEBUG__ print();

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

const int N = 1e3 + 10;
LL n, m;
struct Array{
	LL a, b, c;
}nums[N], f[N][N][2];
LL res = 0;

inline LL calc(Array x) {
	LL res = 0;
	res = abs(x.a) + abs(x.b) + abs(x.c);
	return res;
}

inline Array operator + (const Array &x, const Array &y) {
	Array tmp;
	tmp.a = x.a + y.a;
	tmp.b = x.b + y.b;
	tmp.c = x.c + y.c;
	return tmp;
}

inline void maxn(Array &ori, Array x, Array y) {
	Array tmp1 = ori + x;
	Array tmp2 = ori + y;
	if (calc(tmp1) > calc(tmp2)) ori = ori + x;
	else ori = ori + y;
	return;
}

void print() {
	puts("");
	for (int i = 1; i <= n; i ++) 
	for (int j = 1; j <= m and j <= i; j ++) {
		cout << "i -> " << i << "  j -> " << j << endl;
		cout << f[i][j][0].a << " " << f[i][j][0].b << " " << f[i][j][0].c << endl;
		cout << f[i][j][1].a << " " << f[i][j][1].a << " " << f[i][j][1].a << endl; 
		puts("");
	}
}

int main() {
	input(n), input(m);
	
	for (int i = 1; i <= n; i ++) {
		input(nums[i].a), input(nums[i].b), input(nums[i].c);
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m and j <= i; j ++) {
			if (j == i) f[i][j][1] = f[i - 1][j - 1][1] + nums[i];
			else {
				maxn(f[i][j][0], f[i - 1][j][0], f[i - 1][j][1]);
				maxn(f[i][j][1], f[i - 1][j - 1][0] + nums[i], f[i - 1][j - 1][1] + nums[i]);
			}
		}
	}
	cout << max(calc(f[n][m][1]), calc(f[n][m][0])) << endl;
	return 0;
}
