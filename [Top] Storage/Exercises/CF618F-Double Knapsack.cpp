#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void ot(T x, char ed = '\n') {
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
int n, save[N][2], ans[4];
LL sa[N], sb[N];
bool rot, f[N];

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) rd(sa[i]), sa[i] += sa[i - 1];
	for (int i = 1; i <= n; ++ i) rd(sb[i]), sb[i] += sb[i - 1];
	if (sa[n] > sb[n]) {
		rot = true;
		for (int i = 1; i <= n; ++ i) swap(sa[i], sb[i]);
	}
	for (int i = 0, j = 0; i <= n; ++ i) {
		while (sa[i] >= sb[j] and j <= n) j ++; j --;
		if (f[sa[i] - sb[j]]) {
			ans[0] = save[sa[i] - sb[j]][0] + 1, ans[1] = i;
			ans[2] = save[sa[i] - sb[j]][1] + 1, ans[3] = j;
			break; 
		} else {
			f[sa[i] - sb[j]] = true;
			save[sa[i] - sb[j]][0] = i, save[sa[i] - sb[j]][1] = j;
		}
	}
	if (rot) swap(ans[0], ans[2]), swap(ans[1], ans[3]);
	ot(ans[1] - ans[0] + 1, '\n');
	for (int i = ans[0]; i <= ans[1]; ++ i) ot(i, " \n"[i == ans[1]]);
	ot(ans[3] - ans[2] + 1, '\n');
	for (int i = ans[2]; i <= ans[3]; ++ i) ot(i, " \n"[i == ans[3]]);
	return 0;
}
