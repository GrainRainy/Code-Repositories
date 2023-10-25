#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, h, res, ans, sm;
struct Person {
	int a, b;
	bool operator < (const Person &t) const { return a + b < t.a + t.b; }
}a[N];
priority_queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i].a >> a[i].b, sm += a[i].a;
	cin >> h;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) {
		if (sm + a[i].b >= h) q.push(a[i].a), sm -= a[i].a;
		else {
			if (q.size() and a[i].a < q.top() and q.top() + sm + a[i].b >= h) {
				sm += q.top(); q.pop();
				q.push(a[i].a);
				sm -= a[i].a;
			}
		}
	}
	return cout << q.size() << '\n', 0;
}
