#include <bits/stdc++.h>

#define __DEBUG__ puts("__DEBUG__");
#define enter putchar('\n')
#define endl '\n'
#define fi first
#define se second

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int n, k;
string a;
map<char, int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k >> a;
	int maxr = 0;
	for (int i = 0; i < a.size(); ++ i) {
		if (!st[a[i]]) maxr = max(maxr, i);
		st[a[i]] ++;
	}
	if (n - maxr - 1 < k) return puts("-1"), 0;
	cout << n - maxr - 1 << endl;
	for (int i = 0; i <= maxr; ++ i)
		cout << a[i];
	for (int i = maxr + 1; i < a.size(); ++ i)
		cout << a[i] << endl;
	return 0;
}
