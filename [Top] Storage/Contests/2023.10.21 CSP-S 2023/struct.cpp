#include <bits/stdc++.h>
using namespace std;
const int Q = 1e2 + 10;
const int N = 1e6;
int n, op, k, buf[N], buftop = -1;
int pos[N], top;
string s, t;
map<string, int> id;

int len(string &s) {
	if (s == "byte") return 1;
	if (s == "short") return 2;
	if (s == "int") return 4;
	if (s == "long") return 8;
	return 0;
}

int main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	while (n --) {
		cin >> op;
		if (op == 1) {
			cin >> s >> k;
			for (int i = 1; i <= k; ++ i)
				cin >> s >> s;
		} else if (op == 2) {
			cin >> t >> s;
			pos[++ top] = buftop + 1;
			id[s] = top;
			int lenth = len(t);
			for (int i = buftop + 1; i <= buftop + lenth; ++ i)
				buf[i] = top;
			buftop += lenth;
		} else if (op == 3) {
			cin >> s;
			cout << pos[id[s]] << '\n';
		} else {
			int ad;
			cin >> ad;
			if (ad > buftop) cout << "ERR\n";
			else cout << pos[buf[ad]] << '\n';
		}
	}
	return 0;
}
