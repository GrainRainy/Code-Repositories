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

inline void solve(){
	int a, b, c, d;
	input(a), input(b), input(c), input(d);
	if (b > d or a + (d - b) < c){
		puts("-1");
		return;
	}
	output((d - b) + (a + d - b - c));
	return;
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
