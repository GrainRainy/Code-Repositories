#include <bits/stdc++.h>
using namespace std;
const int N = 50;
char s[N];
int sub, n, l[2], a[N], stk[N], tp, pre[N];
bool fa, fb;

void solve() {
	cin >> s + 1 >> l[0] >> l[1], n = strlen(s + 1);
	fa = fb = false;
	memset(pre, 0, sizeof pre);
	memset(stk, 0, sizeof stk), tp = 0;
	for (int i = 1; i <= n; ++ i) {
		if (s[i] == '?') a[i] = 2, stk[++ tp] = i;
		else if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
			a[i] = 0;
		else a[i] = 1;
	}
	for (int s = 0; s < 1 << tp; ++ s) {
		for (int i = 1; i <= tp; ++ i) {
			if ((s >> i - 1) & 1) a[stk[i]] = 1;
			else a[stk[i]] = 0;
		}
		bool f = false;
		for (int i = 1; i <= n; ++ i) {
			if (a[i] != a[i - 1]) pre[i] = 1;
			else pre[i] = pre[i - 1] + 1;
			if (pre[i] >= l[a[i]]) { fa = f = true; };
		}
		if (!f) fb = true;
	}
	if (fa and fb) printf("Case #%d: SURPRISE\n", sub);
	else if (fa) printf("Case #%d: DISLIKE\n", sub);
	else printf("Case #%d: LIKE\n", sub);
	return;
}

int main() {
	int t; cin >> t;
	while (t --) ++ sub, solve();
	return 0;
}
