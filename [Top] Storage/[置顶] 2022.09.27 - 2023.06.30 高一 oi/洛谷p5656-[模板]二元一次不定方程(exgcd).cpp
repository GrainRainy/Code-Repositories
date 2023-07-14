#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

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

template <typename T> inline void output(T x, char ed = ' '){
	if (x < 0) putchar('-'), x = -x;
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int exgcd(LL a, LL b, LL &x, LL &y){
	if (!b){
		x = 1, y = 0;
		return a;
	}
	LL d = exgcd(b, a % b, x, y);
	LL t = x;
	x = y;
	y = t - (a / b) * y;
	return d;
}

void solve(){
	LL a, b, c, x, y;
	input(a), input(b), input(c);
	
	LL d = exgcd(a, b, x, y);
	if (c % d!=0) puts("-1"); 
	else {
		x *= c / d, y *= c / d;
		LL p = b / d, q = a / d, k;
		if (x < 0) k = ceil((1.0 - x) / p), x += p * k, y -= q * k; 
		if (x >= 0) k = (x - 1) / p, x -= p * k, y += q * k;
		if (y > 0) {
			output((y - 1) / q + 1), output(x);
			output((y - 1) % q + 1), output(x + (y - 1) / q * p), output(y);
		}
		else output(x), output(y + q * (LL)ceil((1.0 - y) / q));

		puts("");
	}
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0; 
}
