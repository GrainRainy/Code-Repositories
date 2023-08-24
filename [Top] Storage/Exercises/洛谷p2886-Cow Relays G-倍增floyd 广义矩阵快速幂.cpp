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

using IO::input;
using namespace std;
using UI = unsigned int;
const int T = 101 + 10;
const int N = 1e3 + 10;
int n, t, s, e, tot;
int num[N];
struct Matrix {
	UI a[T][T];
	UI* operator [] (int x) { return a[x]; }
	Matrix operator * (Matrix t) {
		Matrix ans;
		memset(ans.a, 0x3f, sizeof ans.a);
		for (int k = 1; k <= tot; ++ k)
			for (int i = 1; i <= tot; ++ i)
				for (int j = 1; j <= tot; ++ j)
					ans[i][j] = min(ans[i][j], a[i][k] + t[k][j]);
		return ans;
	}
}dis, res;

void qpow(Matrix a, int b) {
	res = dis;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
}

int main() {
	input(n), input(t), input(s), input(e);
	memset(dis.a, 0x3f, sizeof dis.a);
	for (int i = 1, w, u, v; i <= t; ++ i) {
		input(w), input(u), input(v);
		if (!num[u]) num[u] = ++ tot;
		if (!num[v]) num[v] = ++ tot;
		dis[num[u]][num[v]] = dis[num[v]][num[u]] = w;
	}
	qpow(dis, n - 1);
	return printf("%d\n", res[num[s]][num[e]]), 0;
}
