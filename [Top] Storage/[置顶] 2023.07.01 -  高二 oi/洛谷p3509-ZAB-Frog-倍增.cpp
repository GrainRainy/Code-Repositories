#include <bits/stdc++.h>
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
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
} 

using namespace IO;
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int n, k, step[N], tmp[N], ans[N];
LL m, pos[N];

int main() {
	input(n), input(k), input(m);
	for (int i = 1; i <= n; ++ i) input(pos[i]), ans[i] = i;
	for (int i = 1, l = 1, r = k + 1; i <= n; ++ i) {
		while (r < n and pos[r + 1] - pos[i] < pos[i] - pos[l]) l ++, r ++;
		step[i] = pos[r] - pos[i] > pos[i] - pos[l] ? r : l;
	}
	while (m) {
		if (m & 1) for (int i = 1; i <= n; ++ i) ans[i] = step[ans[i]];
		memcpy(tmp, step, sizeof(int) * (n + 10));
		for (int i = 1; i <= n; ++ i) step[i] = tmp[tmp[i]];
		m >>= 1;
	}
	for (int i = 1; i <= n; ++ i) output(ans[i], " \n"[i == n]);
	return 0;
} 
