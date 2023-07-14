#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>

#define reduce 0.96

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e5 + 10;
const double eps = 1e-8;
int n, tmp;
double sum[N], c[N];
double lmin[N], rmax[N];

bool check(double u){
	for (int i = 0; i <= n; i ++) c[i] = sum[i] - u * i;
	
	lmin[1] = c[1], rmax[n - 1] = c[n - 1];
	for (int i = 2; i <= n; i ++) lmin[i] = min(lmin[i - 1], c[i]);
	for (int i = n - 2; i >= 1; i --) rmax[i] = max(rmax[i + 1], c[i]);
	
	for (int i = 2; i < n; i ++) if (rmax[i] - lmin[i - 1] > c[n]) return false;
	return true; 
}

int main(){
	input(n);
	for (int i = 1; i <= n; i ++){
		input(tmp);
		sum[i] = sum[i - 1] + tmp;
	}
	double l = 0, r = 1e5 + 10;
	while (r - l > eps){
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.3lf\n", l);
	return 0;
}
