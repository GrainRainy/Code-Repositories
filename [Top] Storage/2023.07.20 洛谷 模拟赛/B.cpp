#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
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
const int N = 1e5 + 10;
int num, n, ans;
struct Pos {
	int x, y;
	bool operator < (const Pos &t) const {
		if (x ^ t.x) return x < t.x;
		return y < t.y;
	}
}per[N], door[N];
vector<int> aval[N];
int cnt[N];
bool st[N];

inline bool cmp(int a, int b) { return cnt[a] < cnt[b]; }

int main() {
	input(num), input(n);
	for (int i = 1; i <= n; ++ i) input(per[i].x), input(per[i].y);
	for (int i = 1; i <= n; ++ i) input(door[i].x), input(door[i].y);
	sort(per + 1, per + n + 1), sort(door + 1, door + n + 1);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if (per[j].x <= door[i].x and per[j].y <= door[i].y) {
				aval[i].push_back(j);
				cnt[j] ++;
			}
		}
	}
	for (int i = 1, mn, pos; i <= n; ++ i) {
		mn = n + 1, pos = 0;
		for (auto t : aval[i])
			if (!st[t] and cnt[t] < mn)
				mn = cnt[t], pos = t;
		if (pos) {
			st[pos] = true;
			ans ++;
		}
	}
	return printf("%d\n", ans), 0;
}
