#include <bits/stdc++.h>
using namespace std;
int m, k;
bool tp[1 << 19];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> m >> k;
	if (!m and !k) return puts("0 0") & 0;
	if (m == 1 and !k) return puts("0 0 1 1") & 0;
	if (m == 1 and k == 1) return puts("-1") & 0;
	if (k >= (1 << m)) return puts("-1") & 0;
	for (int i = 0; i < 1 << m; ++ i)
		if (i != k) cout << i << ' ';
	cout << k << ' ';
	for (int i = (1 << m) - 1; ~i; -- i)
		if (i != k) cout << i << ' ';
	return cout << k << '\n', 0;
}
