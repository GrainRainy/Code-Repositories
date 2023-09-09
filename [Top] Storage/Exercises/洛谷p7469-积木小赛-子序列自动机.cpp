#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
const int N = 3e3 + 10;
const int BASE = 13331;
int n;
ULL val, stk[N * N], top;
string s, t;
vector<int> pos[30];
vector<int>::iterator it;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s >> t;
	s = "0" + s, t = "0" + t;
	for (int i = 1; i <= n; ++ i) pos[s[i] - 'a'].push_back(i);
	for (int i = 1, p; i <= n; ++ i) {
		val = p = 0;
		for (int a = i; a <= n; ++ a) {
			it = upper_bound(pos[t[a] - 'a'].begin(), pos[t[a] - 'a'].end(), p);
			if (it == pos[t[a] - 'a'].end()) break;
			val = val * BASE + (t[a] - 'a' + 1);
			stk[++ top] = val;
			p = *it;
		}
	}
	sort(stk + 1, stk + top + 1);
	return cout << unique(stk + 1, stk + top + 1) - stk - 1 << '\n', 0;
}
