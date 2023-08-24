#include <iostream>
#include <cstring>
#include <algorithm>

#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#define putchar(a) _putchar_nolock()
#endif

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
	static short st[16], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int n, m, k, x;

LL qpow(LL a, LL b){
	LL res = 1;
	while (b > 0){
		if (b & 1) res = res * a % n;
		a = a * a % n;
		b >>= 1;
	}
	return res;
}

int main(){
	input(n), input(m), input(k), input(x);
	return output((x % n + m % n * qpow(10, k) % n) % n), 0;
}

