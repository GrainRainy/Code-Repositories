#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
}

using IO::input;
using namespace std;
const int N = 1e5 + 10;
int n, c[N], t[N], a[N], b[N];

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(c[i]);
	for (int i = 1; i <= n; ++ i) input(t[i]);
	if (c[1] ^ t[1] or c[n] ^ t[n]) return puts("No") & 0;
	for (int i = 1; i < n; ++ i) {
		a[i] = c[i + 1] - c[i];
		b[i] = t[i + 1] - t[i];
	}
	sort(a + 1, a + n), sort(b + 1, b + n);
	for (int i = 1; i < n; ++ i) if (a[i] ^ b[i]) return puts("No") & 0;
	return puts("Yes") & 0;
} 
