#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
const int L = 65;
int n, ans, op, a, b, c;
string s;
int tr[N * L][15], tot = 1, sm[N * L];
vector<int> mx[N * L];

void ins(string s, int val, int id) {
	int p = 1;
	for (auto t : s) {
		if (!tr[p][t - '0']) tr[p][t - '0'] = ++ tot;
		p = tr[p][t - '0'], sm[p] += val;
		if (sm[p] > mx[p].size()) mx[p].push_back(id);
	}
}

int query(string s, int k) {
	int p = 1;
	for (auto t : s) {
		if (!tr[p][t - '0']) return -1;
		p = tr[p][t - '0'];
	}
	return mx[p].size() > k ? mx[p][k] : -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> op >> s;
		if (op != 3) ins(s, op == 1 ? 1 : -1, i);
		else {
			cin >> a >> b >> c;
			cout << (ans = query(s, (a * 1ll * abs(ans) + b) % c)) << '\n';
		}
	}
	return 0;
}
