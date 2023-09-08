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
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0'); 
	}
	template <typename T> inline void ot(T x, char ed = '\n') {
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}
using namespace IO;
using namespace std;
const int N = 5e5 + 10;
int n, a[N], id[N];
bool st[N];
int ans, stk[N], top;

inline bool cmp(const int &x, const int &y) { return a[x] ^ a[y] ? a[x] < a[y] : x < y; }
int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) rd(a[i]), id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1, l, r; i <= n; ++ i) {
		if (st[id[i]]) continue;
		l = r = id[i], st[l] = true;
		while (l > 1 and !(a[l - 1] % a[id[i]])) l --, st[l] = true;
		while (r < n and !(a[r + 1] % a[id[i]])) r ++, st[r] = true;
		if (r - l > ans) top = 0;
		if (r - l >= ans) {
			ans = r - l;
			if (stk[top] != l) stk[++ top] = l;
		}
	}
	ot(top, ' '), ot(ans);
	sort(stk + 1, stk + top + 1);
	for (int i = 1; i <= top; ++ i) ot(stk[i], ' ');
	return putchar('\n'), 0;
}
