#include <iostream>

#define N 20010

#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#define putchar(a) _putchar_nolock()
#endif

inline void input(int &x)
{
	x = 0; char c = getchar(); bool f = false;
	for (; c < '0' or c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' and c <= '9'; c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

char ed = ' ';
inline void output(int x)
{
	static short st[10], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top -- ] | '0');
	putchar(ed);
}

int n, i, tmp;
int a[N];

int main(){
	input(n);
	for (i = 1; i <= n; ++ i){
		input(tmp);
		a[tmp] = i - 1;
	}
	// input
	for (i = 1; i <= n; ++ i){
		output(a[i] + N * i);
	}
	puts("");
	for (i = 1; i <= n; ++ i){
		output(N * (n - i) + 1);
	}
	return 0;
}
