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
using LL = long long;
const int N = 1e5 + 10;
int n, k, pos = 1;
struct Item { 
	int t ,d; 
	bool operator < (const Item &t) const { return d > t.d; }
}ary[N];
bool sti[N], stt[N];
LL ans, tmp;

int main() {
	input(n), input(k);
	for (int i = 1; i <= n; ++ i) input(ary[i].t), input(ary[i].d);
	sort(ary + 1, ary + n + 1);
	for (int i = 1; i <= k; ++ i) tmp += ary[i].d;
	ans = tmp;
	for (int i = 1; i <= n; ++ i) {
		while (pos <= n and stt[ary[pos].t]) pos ++; if (pos > n) break;
		sti[pos] = stt[ary[pos].t] = true;
		if (k < pos) {
			while (sti[k] and k) k --; if (!k) break;
			tmp -= ary[k --].d;
			tmp += ary[pos ++].d;
		}
		ans = max(ans, tmp + (LL)i * i);
	}
	cout << ans << endl;
	return 0;
}
