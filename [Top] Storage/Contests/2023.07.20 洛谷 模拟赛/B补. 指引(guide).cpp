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
const int N = 1e5 + 10;
int num, n, ans;
struct Item {
	int x, y;
	bool type; // 0 refers to the person 
	bool operator < (const Item &t) const { return y < t.y; }
}a[N << 1];

inline bool cmp(Item &a, Item &b) { return a.x > b.x; }
set<int> st; 
set<int>::iterator it;

int main() {
	input(num), input(n);
	for (int i = 1; i <= n; ++ i) {
		input(a[i].x), input(a[i].y);
		a[i].type = 0;
	}
	for (int i = n + 1; i <= n << 1; ++ i) {
		input(a[i].x), input(a[i].y);
		a[i].type = 1;
	}
	sort(a + 1, a + (n << 1) + 1, cmp);
	for (int i = 1; i <= (n << 1); ++ i) {
		if (a[i].type) st.insert(a[i].y);
		else if (st.size()) {
			it = st.lower_bound(a[i].y);
			if (it == st.end()) continue;
			ans ++, st.erase(it);
		}
	}
	return printf("%d", ans), 0;
}
