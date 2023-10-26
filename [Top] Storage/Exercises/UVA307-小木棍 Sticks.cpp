#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
int n, top, a[68], sm, len, c;
bitset<68> st;

bool dfs(int pos, int res, int pre) {
	if (pos > c) return true;
	if (res == len) return dfs(pos + 1, 0, 1);
	for (int i = pre, failpos = 0; i <= n; ++ i) 
		if (!st[i] and res + a[i] <= len and failpos != a[i]) {
			st[i] = true;
			if (dfs(pos, res + a[i], i + 1)) return true;
			failpos = a[i], st[i] = false;
			if (!res or res + a[i] == len) return false;
		}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> n and n) {
		sm = 0, st.reset();
		for (int i = 1; i <= n; ++ i) cin >> a[i], sm += a[i];
		sort(a + 1, a + n + 1, greater<int>());
		for (len = a[1]; len <= sm; ++ len) {
			if (sm % len) continue;
			c = sm / len;
			if (dfs(1, 0, 1)) break;
		}
		cout << len << '\n';
	}
	return 0;
}
