#include <iostream>
#include <cstring>
#include <algorithm>

//#define abs(a) ((a < 0) ? (-a) : (a))
#define min(a, b) ((a > b) ? (b) : (a))

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

template <typename T> inline void output(T x, char ed = '\n'){
	if (x < 0) putchar('-'), x = -x;
	static short st[64], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 2e5 + 10;
int n;
int nums[N << 1];

inline LL dist_zer(int n){
	LL ans = 0;
	for (int i = 1; i <= (n << 1); ++ i)
		ans += abs(nums[i] - 0);
	return ans;
}

inline LL dist_neg(int n){
	LL ans = 0;
	int min_dist = 0x3f3f3f3f, min_idx = -1;
	for (int i = 1; i <= (n << 1); ++ i){
		if (abs(nums[i] - n) - abs(nums[i] + 1) < min_dist){
			min_dist = abs(nums[i] - n) - abs(nums[i] + 1);
			min_idx = i;
		}
		ans += abs(nums[i] + 1);
	}
	ans -= abs(nums[min_idx] + 1);
	ans += abs(nums[min_idx] - n);
	return ans;
}

inline LL dist_two(int n){
	LL ans = 0;
	for (int i = 1; i <= (n << 1); ++ i)
		ans += abs(nums[i] - 2);
	return ans;
}

inline void solve(){
	int n; input(n);
	for (int i = 1; i <= (n << 1); i ++)
		input(nums[i]);
	// input
	if (n == 1) output(abs(nums[1] - nums[2])), void();
	else if (n == 2) output(min(min(dist_zer(n), dist_neg(n)), dist_two(n)));
	else if (!(n % 2)) output(min(dist_zer(n), dist_neg(n)));
	else output(dist_zer(n));
	
	return;
}

signed main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
