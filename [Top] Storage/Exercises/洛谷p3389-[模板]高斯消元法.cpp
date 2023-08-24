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

const int N = 1e2 + 10;
const double eps = 1e-8;
int n;
double nums[N][N];

void print() {
	puts("");
	for (int m = 1; m <= n; m ++, puts(""))
		for (int j = 1; j <= n + 1; j ++)	
			cout << nums[m][j] << " ";
	puts("");
}

void gauss() {
	for (int r = 1, c = 1; c <= n; c ++, r ++) {
	// row and line 
		int t = r;
		for (int i = r + 1; i <= n; i ++)
			if (fabs(nums[i][c]) > fabs(nums[t][c]))
				t = i;
		swap(nums[t], nums[r]);
		
		if (fabs(nums[r][r]) <= eps) return puts("No Solution"), void();
		for (int i = n + 1; i >= c; i --) nums[r][i] /= nums[r][c];
		for (int i = r + 1; i <= n; i ++)
			for (int j = n + 1; j >= c; j --)
				nums[i][j] -= nums[i][c] * nums[r][j];
	}
	for (int i = n; i > 1; i --)
		for (int j = i - 1; j; j --) {
			nums[j][n + 1] -= nums[i][n + 1] * nums[j][i];
			nums[j][i] = 0;
		} 
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n + 1; ++ j)
			scanf("%lf", &nums[i][j]);
	
	gauss();
	
	for (int i = 1; i <= n; i ++)
		printf("%.2lf\n", nums[i][n + 1]);
	return 0;
}
