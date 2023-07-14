#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define __DEBUG__ print();

using namespace std;
using LL = long long;
using ULL = unsigned long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
} 

const int N = 20;
const double eps = 1e-8;
int n;
double a[N][N], b[N][N];

void gauss() {
	for (int i = 1; i <= n; ++ i) {
		int pivot = i;
		for (int j = i + 1; j <= n; ++ j) {
			if (fabs(b[j][i]) < fabs(b[pivot][i]))
				pivot = j;
		}
		swap(b[pivot], b[i]);
		if (fabs(b[i][i]) <= eps) return puts("No Solution"), void();
		
		for (int k = n + 1; k >= i; -- k) {
			b[i][k] /= b[i][i];
		}
		
		for (int j = 1; j <= n; j ++) {
			if (i != j and fabs(b[j][i]) > eps) {
				double t = b[j][i] / b[i][i];
				for (int k = i; k <= n + 1; k ++)
					b[j][k] -= t * b[i][k]; 
			}
		}
	}
}

void Gauss() {
	for (int r = 1, c = 1; c <= n; c ++, r ++) {
	// row and line 
		int pivot = r;
		for (int i = r + 1; i <= n; i ++)
			if (fabs(b[i][c]) > fabs(b[pivot][c]))
				pivot = i;
		swap(b[pivot], b[r]);
		
		for (int i = n + 1; i >= c; i --) b[r][i] /= b[r][c];
		for (int i = r + 1; i <= n; i ++)
			for (int j = n + 1; j >= c; j --)
				b[i][j] -= b[i][c] * b[r][j];
		// 得到上三角矩阵 
	}
	for (int i = n; i > 1; i --)
		for (int j = i - 1; j; j --) {
			b[j][n + 1] -= b[i][n + 1] * b[j][i];
			b[j][i] = 0;
		} 
	// 得到对角矩阵 
}

int main() {
	input(n);
    for (int i = 0; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            scanf("%lf", &a[i][j]);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            b[i][j] = 2 * (a[i][j] - a[0][j]);
            b[i][n + 1] += a[i][j] * a[i][j] - a[0][j] * a[0][j];
        }
    
	gauss();
	
	for (int i = 1; i <= n; i ++)
		printf("%.3lf ", b[i][n + 1]);
	return 0;
}
