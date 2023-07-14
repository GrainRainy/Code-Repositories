#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 110;
int n, a[N][N];

int Gauss() {
	int r, c;
	for (r = c = 1; c <= n; c ++) {
		int pivot = r;
		for (int i = r + 1; i <= n; i ++)
			if (a[i][c]){ pivot = i; break; }
		if (!a[pivot][c]) continue;
		swap(a[pivot], a[r]);
		
		for (int i = r + 1; i <= n; i ++) {
			if (!a[i][c]) continue;
			for (int j = n + 1; j >= c; j --)
				a[i][j] ^= a[r][j];
		}
		
		r ++;
	}
	
	if (r <= n) {
		for (int i = r; i <= n; i ++)
			if (a[i][n + 1]) return 0;
		return 2;
	}
	
	for (int i = n; i >= 1; i --) {
		for (int j = i + 1; j <= n; j ++)
			a[i][n + 1] ^= a[i][j] * a[j][n + 1];  
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n + 1; j ++)
			scanf("%d", &a[i][j]);
	// input 
	int type = Gauss();
	if (type == 0) return puts("No solution"), 0;
	if (type == 2) return puts("Multiple sets of solutions"), 0;
	for (int i = 1; i <= n; i ++) printf("%d\n", a[i][n + 1]);
	return 0;
}
