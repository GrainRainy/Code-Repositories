#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
const int M = 1e6 + 10;
bool st;
int n, k, v[N], top = 1;
struct Situ {
	int val;
	string seq;
	bool operator < (const Situ &t) const { 
		return val ^ t.val ? val < t.val : seq < t.seq;
	}
}t[M];
bool ed;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	if (!(-- k)) return cout << 0 << '\n', 0;
	for (int i = 1; i <= n; ++ i) cin >> v[i];
	for (int s = 1; s < 1 << n; ++ s, ++ top) {
		for (int i = 1; i <= n; ++ i)
			if ((s >> i - 1) & 1) {
				t[top].seq = t[top].seq + (char)(i + '0');
				t[top].val += v[i];
			}
	}
	sort(t + 1, t + top);
	cout << t[k].val << '\n';
	for (auto tmp : t[k].seq) cout << tmp << ' ';
	return cout << '\n', 0;
}
