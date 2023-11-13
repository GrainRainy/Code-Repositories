#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int q, l, r, wtp, p[N << 1];
string s;
char nw[N << 1];

int sol(const string &t) {
	wtp = 0, nw[wtp ++] = '$', nw[wtp ++] = '#';
	for (int i = 0; i < t.size(); ++ i)
		nw[wtp ++] = t[i], nw[wtp ++] = '#';
	nw[wtp ++] = '^', nw[wtp + 1] = '%';
	for (int i = 1, mid = 0, mr = 0; i < wtp; ++ i) {
		p[i] = i < mr ? min(p[(mid << 1) - i], mr - i) : 1;
		while (nw[i + p[i]] == nw[i - p[i]]) p[i] ++;
		if (i + p[i] > mr) mid = i, mr = i + p[i];
	}
	return *max_element(p, p + wtp) - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s >> q;
	while (q -- ) {
		cin >> l >> r;
		cout << sol(s.substr(l, r - l + 1)) << '\n';
	}
	return 0;
}
