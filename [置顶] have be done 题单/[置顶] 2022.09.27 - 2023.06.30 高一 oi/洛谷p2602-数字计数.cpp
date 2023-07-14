#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = ' '){
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 13;
LL l, r;
LL cntl[N], cntr[N];
LL tenPow[N], nums[N];
LL dp[N];

inline void init(){
	tenPow[0] = 1ll;
	for (int i = 1; i <= N; ++ i){
		dp[i] = dp[i - 1] * 10 + tenPow[i -1];
		tenPow[i] = 10ll * tenPow[i - 1];
	}
	return;
}

void solve(LL n, LL *cnt){ // calculate from 1 to n 
	LL tmp = n, top = 0;
	do nums[++ top] = n % 10, n /= 10; while (n);
	
	for (int i = top; i >= 1; -- i){
		for (int j = 0; j <= 9; ++ j) cnt[j] += dp[i - 1] * nums[i];
		for (int j = 0; j < nums[i]; ++ j) cnt[j] += tenPow[i - 1];
		tmp -= tenPow[i - 1] * nums[i], cnt[nums[i]] += tmp + 1;
		cnt[0] -= tenPow[i - 1];
	}
}

int main(){
	input(l), input(r);
	if (l > r) swap(l, r);
	init();
	solve(l - 1, cntl), solve(r, cntr);
	for (int i = 0; i <= 9; i ++) output(cntr[i] - cntl[i]);
	puts("");
	return 0;
}
