#include <iostream>
#include <cstring>
#include <algorithm>

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
int cnt[N];

inline void solve(){
	input(n);
	int cnt0 = 0, cnt1 = 0, cntn = 0;
	for (int i = 1; i <= n; i ++){
		int tmp; input(tmp);
		if (!tmp) cnt0 ++;
		else if (tmp == 1) cnt1 ++;
		else cntn ++;
	}
	if (cnt0 <= cntn + cnt1 + 1) puts("0");
	else if (cnt0 == n or cnt1 + cnt0 != n) puts("1");
	else puts("2"); // (cnt0 + cnt1 == n)
	return;
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
