#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
LL q, del, sa, sb;
priority_queue<LL> qa;
priority_queue<LL, vector<LL>, greater<LL>> qb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> q;
	for (int i = 1, op, a, b; i <= q; ++ i) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b, del += b;
			if (qb.size() and a > qb.top()) qb.push(a), sb += a;
			else qa.push(a), sa += a;
			while (qb.size() < qa.size() + qb.size() >> 1) {
				qb.push(qa.top()), sb += qa.top();
				sa -= qa.top(), qa.pop();
			}
			while (qa.size() < qa.size() + qb.size() + 1 >> 1) {
				qa.push(qb.top()), sa += qb.top();
				sb -= qb.top(), qb.pop();
			}
		} else {
			LL res = qa.top() * qa.size() - sa;
			if (qb.size()) res += sb - qa.top() * qb.size();
			cout << qa.top() << ' ' << res + del << '\n';
		}
	}
	return 0;
}
