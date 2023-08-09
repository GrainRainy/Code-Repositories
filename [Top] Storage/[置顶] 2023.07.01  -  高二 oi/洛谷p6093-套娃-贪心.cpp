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
using LL = long long;
const int N = 2e5 + 10;
int n;
struct Item {
	int out, in, b;
	bool operator < (const Item &t) const { return b > t.b; }
}a[N];
multiset<int> st;
multiset<int>::iterator it;
LL ans;

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) {
		input(a[i].out), input(a[i].in), input(a[i].b);
		st.insert(a[i].out);
		ans += (LL)a[i].b * a[i].in;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) {
		it = st.lower_bound(a[i].in);
		if (it != st.begin()) {
			ans -= (*-- it) * (LL)a[i].b;
			st.erase(it);
		}
	}
	return printf("%lld\n", ans), 0;
}
