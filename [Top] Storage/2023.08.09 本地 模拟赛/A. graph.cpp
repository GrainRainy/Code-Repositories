#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
int n, tot, cnt, stk[N], sum;
bool mp[N][N];

int calc() {
	int res = 0;
	for (res = 0; n >= res * (res - 1) / 2; ++ res)
		n -= res * (res - 1) / 2;
	return res;
}

int main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	while (n) stk[++ stk[0]] = calc() - 1, sum += stk[stk[0]];
	sum += stk[0];
	cout << sum << '\n';
	for (int a = 1; a <= sum - 1; ++ a) {
		for (int b = 1; b <= sum - a; ++ b)
			if (b <= stk[stk[0]]) cout << '1' << ' ';
			else cout << '0' << ' ';
		cout << '\n';
		stk[stk[0]] --;
		if (stk[stk[0]] == -1) stk[0] --;
	}
	return 0;
}
