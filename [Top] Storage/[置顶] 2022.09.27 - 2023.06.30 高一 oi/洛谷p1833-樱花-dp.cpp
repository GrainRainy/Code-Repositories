#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x; 
	}
}

using namespace IO;
using namespace std;
int sh, sm, eh, em, tt, n, t, c, p;
int f[1010];

int main() {
	scanf("%d:%d", &sh, &sm);
	scanf("%d:%d", &eh, &em);
	tt = (eh - sh) * 60 + em - sm;
	input(n);
	for (int i = 1; i <= n; ++ i) {
		input(t), input(c), input(p);
		if (!p) p = tt / t + 10;
		for (int j = 1; j <= p; j <<= 1) {
			for (int k = tt; k >= j * t; -- k)
				f[k] = max(f[k], f[k - j * t] + j * c);
			p -= j;
		}
		if (p) for (int k = tt; k >= p * t; -- k)
			f[k] = max(f[k], f[k - p * t] + p * c);
	}
	cout << f[tt] << endl;
	return 0;
}

