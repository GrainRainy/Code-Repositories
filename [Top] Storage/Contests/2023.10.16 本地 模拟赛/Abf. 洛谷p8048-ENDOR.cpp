#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
int n, k, l;
struct tmp {
	double a;
	int b, c;
	bool operator < (const tmp &t) const { return a < t.a; }
}a[N];
double ans[100];

int main() {
	cin >> n >> k >> l;
	for (int i = 1; i <= n; ++ i) {
		char cc;
		cin >> a[i].a >> a[i].b >> cc;
		if (cc == 'D') a[i].c = 1;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) {
		if (a[i].c) ans[a[i].b] += l - a[i].a;
		else {
			double totdel = 0;
			for (int j = i - 1; j; -- j) {
				if (!a[j].c) continue;
				double gap = (double)(a[i].a - a[j].a - totdel) / 2;
				ans[a[i].b] += gap, a[i].a -= gap, totdel += gap;
				a[i].b = (a[i].b + a[j].b) % k;
			}
			ans[a[i].b] += a[i].a;
		}
	}
	for (int i = 0; i < k; ++ i) printf("%.1lf\n", ans[i]);
	return 0;
}
