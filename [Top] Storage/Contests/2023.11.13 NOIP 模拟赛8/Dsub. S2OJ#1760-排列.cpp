#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q, a[N], tmp[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	cin >> q;
	for (int i = 1, l, r, k; i <= q; ++ i) {
		cin >> l >> r >> k;
		bool jg = false;
		while (k --) {
			for (int j = l; j <= r; ++ j)
				tmp[j] = a[j - 1 == l - 1 ? r : j - 1];
			for (int j = l; j <= r; ++ j) a[j] = tmp[j];
		}
		for (int j = 1; j <= n; ++ j) {
			f[j] = 1;
			for (int k = 1; k < j; ++ k) 
				if (a[k] < a[j]) f[j] = max(f[j], f[k] + 1);
			if (f[j] > 2) { jg = true; break; }
		}
		puts(jg ? "YES" : "NO");
	}
	return 0;
}
