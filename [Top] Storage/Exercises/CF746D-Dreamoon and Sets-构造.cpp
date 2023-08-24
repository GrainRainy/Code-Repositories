#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
	#ifdef __LINUX__
	#define getchar() getchar_unlocked()
	#define putchar(a) putchar_unlocked(a)
	#endif
	
	#ifdef __WINDOWS__
	#define getchar() _getchar_nolock()
	#define putchar(a) _putchar_nolock()
	#endif
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar(); bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T, typename... Args>
	void input(T &x, Args&... args) {
		input(x), input(args...);
	}
	
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[ ++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top -- ] | '0');
		putchar(ed);
	}
	template <typename T, typename ...Args>
	void output(T x, char ch = ' ', Args... args) {
		output(x, ch);
		output(args...);
	}
}

using namespace std; 
using namespace IO;

int n, k, x;
int main() {
	input(n), input(k);
	output((n * 6 - 1) * k, '\n');
	for (int i = 1; i <= n; ++ i) 
		x = i * 6 - 5, output(x * k, ' ', (x + 1) * k, ' ', (x + 2) * k, ' ', (x + 4) * k, '\n');
	return 0;
}
