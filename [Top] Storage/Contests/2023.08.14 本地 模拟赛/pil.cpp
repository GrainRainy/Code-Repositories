#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int t, n, ary, ans;
int q[N], hd = 1, tl;
priority_queue<int, vector<int>, greater<int>> a, ruba;
priority_queue<int> b, rubb;

int main() {
	freopen("pil.in", "r", stdin);
	freopen("pil.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> ary;
		q[++ tl] = ary;
		a.push(ary), b.push(ary);
		while (ruba.size() and ruba.top() == a.top()) a.pop(), ruba.pop();
		while (rubb.size() and rubb.top() == b.top()) b.pop(), rubb.pop();
		while (hd < tl and b.top() - a.top() > t) {
			ruba.push(q[hd]), rubb.push(q[hd]);
			while (ruba.size() and ruba.top() == a.top()) a.pop(), ruba.pop();
			while (rubb.size() and rubb.top() == b.top()) b.pop(), rubb.pop();
			hd ++;
		}
		if (ans < tl - hd + 1) ans = tl - hd + 1;
	}
	cout << ans << endl;
	return 0;
}
