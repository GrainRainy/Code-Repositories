#include <bits/stdc++.h>
using namespace std;
using D = double;
using PDI = pair<double, int>;
const int N = 1e6 + 10;
int n, a[N], ans;
double sm, cnt, avr;
set<PDI> st;
set<PDI>::iterator it;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

int main() {
	rd(n), cnt = n;
	for (int i = 1; i <= n; ++ i) rd(a[i]), sm += a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) st.insert({a[i], i});
	it = st.upper_bound({sm / cnt, n + 1});
	if (it == st.end()) ans = 0;
	else ans = n - (*it).second + 1;
	for (int i = n, res; i; -- i) {
		sm -= a[i], cnt --;
		it = st.upper_bound({sm / cnt, n + 1});
		if (it == st.end()) res = 0;
		else res = n - (*it).second + 1;
		
		/* ATTENTION !!! */
//		printf("%d\n", res - n + i - 1);
		
		ans = max(ans, res - n + i - 1);
	}
	return cout << ans << '\n', 0;
}
