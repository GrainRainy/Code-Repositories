#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n, k, ans;
inline LL qp(LL a) { return a * a * a; }
int main() {
	cin >> n >> k;
	ans += qp(n / k);
	if (!(k & 1)) ans += qp((n + k / 2) / k);
	cout << ans << endl;
	return 0;
}
