#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}
using IO::rd;
using namespace std;
const int N = 1e5 + 10;
int n, q, m;
vector<int> pos[N];
vector<int>::iterator np;

int main() {
	rd(n);
	for (int i = 1, tmp; i <= n; ++ i) rd(tmp), pos[tmp].push_back(i);
	rd(q); 
	for (int i = 1, l, tmp, p, f; i <= q; ++ i) {
		rd(l), p = 0, f = 0;
		for (int j = 1; j <= l; ++ j) {
			rd(tmp);
			if (f) continue;
			np = upper_bound(pos[tmp].begin(), pos[tmp].end(), p);
			if (np == pos[tmp].end()) f = 1;
			else p = *np;
		}
		puts(f ? "NIE" : "TAK");
	}
	return 0;
}
