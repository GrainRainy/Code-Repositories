#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

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

const double EPS = 1e-8;
int n;
const int N = 110;
double coe[N][N]; 

void print(){
	puts("");
    for (int i =1; i <= n; i ++, puts(""))
        for (int j = 1; j <= n + 1; j ++)
            cout << coe[i][j] << " ";
    puts("");
}

int Gauss() {
	int c, r; // column and row 
//	for (c = 1, r = 1; c <= 1; c ++){
	for (c = 1, r = 1; c <= n; c ++){
		int pivot = r;
		for (int i = r; i <= n; i ++) {
			if (fabs(coe[i][c]) > fabs(coe[pivot][c]))
				pivot = i;
		}
		if (fabs(coe[pivot][c]) < EPS) continue;
		swap(coe[pivot], coe[r]);
		
		for (int i = n + 1; i >= c; i --) coe[r][i] /= coe[r][c];
		for (int i = r + 1; i <= n; i ++) {
			if (fabs(coe[i][c]) > EPS){
				for (int j = n + 1; j >= c; j --) 
					coe[i][j] -= coe[r][j] * coe[i][c];
			}
		}
		
		r ++;
	}
	// calculate coefficient  
	
	if (r <= n) {
		for (int i = r; i <= n; i ++) {
			if (fabs(coe[i][n + 1]) > EPS) return 2	; // No Solutions. 
		}
		return 1; // Many Solutions. 
	}
	// special judgements 
	
	for (int i = n; i >= 1; i --) {
		for (int j = i + 1; j <= n; j ++)
			coe[i][n + 1] -= coe[i][j] * coe[j][n + 1];
	}
	// calculate answers
	return 0; // Only One Solution. 
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n + 1; ++ j)
			scanf("%lf", &coe[i][j]);
	
	int type = Gauss();
	if (type == 1) return puts("Infinite group solutions"), 0;
	if (type == 2) return puts("No solution"), 0;

	for (int i = 1; i <= n; i ++){
		if (fabs(coe[i][n + 1]) < EPS) coe[i][n + 1] = 0;
		printf("%.2lf\n", coe[i][n + 1]);
	}
	return 0;
}
